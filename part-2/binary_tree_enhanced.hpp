#ifndef __binary_tree_enhanced__
#define __binary_tree_enhanced__

#include <cassert>
#include <memory>
#include <utility>   // std::move

// A class representing a binary tree
template <typename V>
struct BinaryTreeEnhanced {
  V _value;
  std::unique_ptr<BinaryTreeEnhanced<V>> _left;
  std::unique_ptr<BinaryTreeEnhanced<V>> _right;

  // NEW: pointer to parent (does not own anything)
  BinaryTreeEnhanced<V>* _parent = nullptr;

  friend V &value(BinaryTreeEnhanced *t) { return t->_value; }
  friend const V &value(const BinaryTreeEnhanced *t) { return t->_value; }

  friend BinaryTreeEnhanced *left(const BinaryTreeEnhanced *t)
  {
    return t->_left.get();
  }

  friend BinaryTreeEnhanced *right(const BinaryTreeEnhanced *t)
  {
    return t->_right.get();
  }

  friend BinaryTreeEnhanced *parent(const BinaryTreeEnhanced *t)
  {
    return t ? t->_parent : nullptr;
  }
};

// A helper function to build an enhanced binary tree
template <typename V>
std::unique_ptr<BinaryTreeEnhanced<V>>
make_binary_tree_enhanced(const V &value,
                          std::unique_ptr<BinaryTreeEnhanced<V>> l,
                          std::unique_ptr<BinaryTreeEnhanced<V>> r)
{
  // 1) Create the root node and give it the children
  auto t = std::make_unique<BinaryTreeEnhanced<V>>();
  t->_value = value;
  t->_left = std::move(l);
  t->_right = std::move(r);

  // 2) Tell the children who their parent is
  if (t->_left)  { t->_left->_parent = t.get(); }
  if (t->_right) { t->_right->_parent = t.get(); }

  return t;
}

#endif // __binary_tree_enhanced__