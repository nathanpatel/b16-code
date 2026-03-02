#ifndef __array_delete__
#define __array_delete__

#include <cstddef>
#include <utility>
#include <vector>

template <typename T>
void array_delete(std::vector<T> &A, std::size_t index)
{
void array_delete(std::vector<T> &A, std::size_t index)
{
  // 1) Safety check:
  if (index >= A.size()) {
    return;
  }

  // 2) Shift items LEFT to fill the gap.
  //
  // We start at the deletion point.
  // Each step copies/moves the item from the right into the current spot.
  //
  // Stop when j is the second-to-last index,
  // because we read A[j+1].
  for (std::size_t j = index; j + 1 < A.size(); ++j) {
    A[j] = std::move(A[j + 1]);
  }

  // 3) Remove the last element.
  // After shifting, the final element is duplicated,
  // so we shrink the vector by 1.
  A.pop_back();
}}

#endif // __array_delete__