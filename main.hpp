#ifndef MAIN_HPP
#define MAIN_HPP

#include <iostream>

// III
// Интерфейс:
// a - массив массивов, которые нужно слить в 1
// sa - количество массивов в массиве a
// sai - массив соотвествующих размеров массивов в a
// с - итоговый массив, в который нужно слить все

// Неявный интерфейс:
// 1) Наличие перегрузки оператора копирующего присваивания
// 2) Наличие перегрузки оператора <

// Недостатки явного интерфейса:
// 1) В аргументах набор указателей, непонятно кто за что отвечает, по сигнатуре нельзя догадаться, что именно нужно
// передать в функцию.
// 2) Невозможно заведомо знать, достаточно ли элементов в массиве c, можно выйти за границы
// выделенной памяти
// 3) Слишком много ответственности на пользователе (посчитать заранее общее кол-во элементов,
// выделить память для c, составить массив массивов, создать к этому массиву массив размеров)

// Ещё можно добавить то, что мы не можем контроллировать exception safety. Если вызовется исключение в момент
// присвоения c[c_i++] = a[i][j], то массив будет заполнен частично, пользователь никак не сможет понять, насколько
// имеенно заполнен массив, было бы лучше пробрасывать ещё один аргумент по ссылке, в который мы бы ложили число успешно
// слитых элементов массива.

template < class T > T *mergeN(const T *const *a, size_t sa, const size_t *sai, T *c)
{
  if (!a || !sai || !c)
  {
    return nullptr;
  }

  size_t total_s = 0;
  size_t *a_inds = new size_t[sa];
  for (size_t i = 0; i < sa; ++i)
  {
    total_s += sai[i];
    a_inds[i] = 0;
  }
  try
  {
    for (size_t i = 0; i < total_s; ++i)
    {
      const T *minEl = nullptr;
      size_t min_ind = 0;
      const T *first_not_null = nullptr;
      for (size_t j = 0; j < sa; ++j)
      {
        if (a_inds[j] < sai[j] && (!minEl || a[j][a_inds[j]] < *minEl))
        { // T::operator < (const T&)
          minEl = &(a[j][a_inds[j]]);
          min_ind = j;
        }
      }
      a_inds[min_ind]++;
      c[i] = *minEl; // T::operator=(const T&)
    }
  }
  catch (...)
  {
    delete[] a_inds;
    throw;
  }
  delete[] a_inds;
  return c + total_s;
}

void print_ints(const int *arr, size_t size)
{
  for (size_t i = 0; i < size; ++i)
  {
    if (i != 0)
    {
      std::cout << " ";
    }
    std::cout << arr[i];
  }
  std::cout << "\n";
}

#endif