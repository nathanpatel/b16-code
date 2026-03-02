#ifndef __list_enhanced__
#define __list_enhanced__

#include "list.hpp"
#include <cassert>
#include <utility>   // std::move

template <typename T>
void list_delete_after(Node<T> *node)
{
  // There must be a node after 'node' to delete
  assert(node != nullptr);
  assert(node->next != nullptr);

  // victim = the node we want to delete (take ownership of it)
  auto victim = std::move(node->next);

  // Now link node directly to what comes after victim
  node->next = std::move(victim->next);

  // victim goes out of scope here -> its node is automatically destroyed
}

#endif