#ifndef __stack_enhanced___
#define __stack_enhanced___

#include "stack.hpp"

template <typename T> class StackEnhanced : public Stack<T>
{
  public:
    // Inherit the Stack<T> constructors as they are
    // https://en.cppreference.com/w/cpp/language/using_declaration
    using Stack<T>::Stack;

    void clear()
    {
    // Setting _head to 0 makes the stack "empty" instantly.
    // We do not need to erase _storage; the stack just forgets old values.
    this->_head = 0;    }
};

// Allow: stack << value1 << value2
template <typename T>
StackEnhanced<T> &operator<<(StackEnhanced<T> &stack, const T &value)
{
  stack.push(value);   // push one element on top
  return stack;        // return the same stack so chaining works
}

#endif // __stack_enhanced___