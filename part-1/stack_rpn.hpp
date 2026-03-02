#ifndef __stack_rpn__
#define __stack_rpn__

#include "stack.hpp"

// PLUS: replace top two values a, b with a + b
template <typename T>
void plus(Stack<T> &stack)
{
  // Read the top value (b), then remove it
  T b = stack.top();
  stack.pop();

  // Read the new top value (a), then remove it
  T a = stack.top();
  stack.pop();

  // Push the result back
  stack.push(a + b);
}

// MINUS: replace a, b with a - b
template <typename T>
void minus(Stack<T> &stack)
{
  T b = stack.top();
  stack.pop();

  T a = stack.top();
  stack.pop();

  stack.push(a - b);
}

// MULTIPLIES: replace a, b with a * b
template <typename T>
void multiplies(Stack<T> &stack)
{
  T b = stack.top();
  stack.pop();

  T a = stack.top();
  stack.pop();

  stack.push(a * b);
}

// DIVIDES: replace a, b with a / b
template <typename T>
void divides(Stack<T> &stack)
{
  T b = stack.top();
  stack.pop();

  T a = stack.top();
  stack.pop();

  stack.push(a / b);
}

// NEGATE: replace a with -a
template <typename T>
void negate(Stack<T> &stack)
{
  T a = stack.top();
  stack.pop();

  stack.push(-a);
}

#endif // __stack_rpn__