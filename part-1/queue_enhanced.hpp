#ifndef __queue_enhanced__
#define __queue_enhanced__

#include <cassert>
#include <vector>

#include "queue.hpp"

template <typename T>
class Dequeue : public Queue<T>
{
public:
  // Inherit the constructors of Queue<T>
  using Queue<T>::Queue;

  // Access the element at the back of the queue
  T &back()
  {
    return this->_storage[_tail()];
  }

  // Const-access the element at the back of the queue
  const T &back() const
  {
    return this->_storage[_tail()];
  }

  // Add a new element to the front of the queue by copying
  void enqueue_front(const T &value)
  {
    // The front is at _head(). To add before the front,
    // we move the head one step "forward" (i.e. increase size)
    // by writing into the new head position.

    assert(this->_size < this->_storage.size());

    // Increase size first so that _head() points to the new slot
    this->_size++;
    this->_storage[this->_head()] = value;
  }

  // Remove the element at the back of the queue
  void dequeue_back()
  {
    // Removing from back just moves _position forward by 1
    // and decreases the size.
    assert(this->_size >= 1);

    // Move _position forward by 1 (wrapping around)
    this->_position = _tail();
    this->_size--;
  }

  // Remove all elements from the queue
  void clear()
  {
    // Same idea as stack: just reset the size to 0.
    this->_size = 0;
    this->_position = 0; // optional but clean
  }

protected:
  // Return the index of the element at the back of the queue
  size_t _tail() const
  {
    assert(this->_size >= 1);

    // _position is the first empty slot at the back,
    // so the last filled slot is one step after it.
    auto index = this->_position + 1;
    if (index >= this->_storage.size()) { index -= this->_storage.size(); }
    return index;
  }
};

#endif // __queue_enhanced__