#include "boost_test.hpp"

#include "main.hpp"

BOOST_AUTO_TEST_SUITE(mergeN_tests)

BOOST_AUTO_TEST_CASE(test_standart_merge)
{
  int row1[] = {1, 2};
  int row2[] = {3, 4, 5};
  int row3[] = {6};

  const int *a[] = {row1, row2, row3};
  size_t sa = 3;
  size_t sai[] = {2, 3, 1};

  int result[6] = {};

  mergeN(a, sa, sai, result);
  int expected[] = {1, 2, 3, 4, 5, 6};

  BOOST_CHECK_EQUAL_COLLECTIONS(result, result + 6, expected, expected + 6);
}

BOOST_AUTO_TEST_CASE(test_empty_arrays)
{
  int row1[] = {1, 2};
  int *row2 = nullptr;
  int row3[] = {3};

  const int *a[] = {row1, row2, row3};
  size_t sa = 3;
  size_t sai[] = {2, 0, 1};

  int result[3];
  mergeN(a, sa, sai, result);

  int expected[] = {1, 2, 3};

  BOOST_CHECK_EQUAL_COLLECTIONS(result, result + 3, expected, expected + 3);
}

BOOST_AUTO_TEST_CASE(test_single_array)
{
  int row1[] = {3, 4, 5};
  const int *a[] = {row1};

  size_t sa = 1;
  size_t sai[] = {3};

  int result[3];

  mergeN(a, sa, sai, result);

  int expected[] = {3, 4, 5};

  BOOST_CHECK_EQUAL_COLLECTIONS(result, result + 3, expected, expected + 3);
}


BOOST_AUTO_TEST_CASE(test_sorted_merge_basic) {
    int row1[] = {1, 5, 10};
    int row2[] = {2, 3, 12};
    int row3[] = {0, 7, 8};

    const int* a[] = {row1, row2, row3};
    size_t sa = 3;
    size_t sai[] = {3, 3, 3};

    int result[9];
    mergeN(a, sa, sai, result);

    int expected[] = {0, 1, 2, 3, 5, 7, 8, 10, 12};
    BOOST_CHECK_EQUAL_COLLECTIONS(result, result + 9, expected, expected + 9);
}

BOOST_AUTO_TEST_CASE(test_sorted_merge_duplicates) {
    int row1[] = {1, 2, 2};
    int row2[] = {2, 5};
    int row3[] = {1, 1, 6};

    const int* a[] = {row1, row2, row3};
    size_t sa = 3;
    size_t sai[] = {3, 2, 3};

    int result[8];
    mergeN(a, sa, sai, result);

    int expected[] = {1, 1, 1, 2, 2, 2, 5, 6};
    BOOST_CHECK_EQUAL_COLLECTIONS(result, result + 8, expected, expected + 8);
}

BOOST_AUTO_TEST_SUITE_END()