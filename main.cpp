#include <iostream>

template < class T > T *mergeN(const T *const *a, size_t sa, const size_t *sai, T *c)
{
  if (!a || !sai || !c)
    return nullptr;
  size_t c_i = 0;
  for (size_t i = 0; i < sa; ++i)
  {
    if (a[i] != nullptr)
      for (size_t j = 0, curr_size = sai[i]; j < curr_size; ++j)
      {
        c[c_i++] = a[i][j]; // T::operator=(T)
      }
  }
  return c + c_i;
}