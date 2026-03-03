#include <iostream>

// III
// a - массив массивов, которые нужно слить в 1
// sa - количество массивов в массиве a
// sai - массив соотвествующих размеров массивов в a
// с - итоговый массив, в который нужно слить все
template < class T > T *mergeN(const T *const *a, size_t sa, const size_t *sai, T *c);