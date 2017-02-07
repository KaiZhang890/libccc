#include "minunit.h"
#include <ccc/sort.h>
#include <time.h>

int *create_array(int count) {
  int *array = calloc(count, sizeof(int));
  srand(time(NULL));
  for (int i = 0; i < count; i++) {
    array[i] = rand() % 10000;
  }
  return array;
}

int is_sorted(int a[], int c) {
  for (int i = 0; i < c; i++) {
    if (i + 1 < c) {
      if (a[i] > a[i + 1]) {
        return 0;
      }
    }
  }

  return 1;
}

char *test_bubble_sort() {
  int count = 20;
  int *array = create_array(count);
  mu_assert(is_sorted(array, count) == 0, "Rand numbers, not sorted.");

  bubbleSort(array, count);
  mu_assert(is_sorted(array, count) == 1, "Bubble sort should be sorted.");

  free(array);
  return NULL;
}

char *test_quick_sort() {
  int count = 20;
  int *array = create_array(count);
  mu_assert(is_sorted(array, count) == 0, "Rand numbers, not sorted.");

  quickSort(array, 0, count - 1);
  mu_assert(is_sorted(array, count) == 1, "Quick sort should be sorted.");

  free(array);
  return NULL;
}

char *all_tests() {
  mu_suite_start();

  mu_run_test(test_bubble_sort);
  mu_run_test(test_quick_sort);


  int count = 10000;
  int *array = create_array(count);
  int *array2 = malloc(count * sizeof(int));
  memcpy(array2, array, count * sizeof(int));
  debug("Performance test start, int array count:%d", count);

  clock_t c0 = clock();
  bubbleSort(array, count);
  clock_t c1 = clock();
  debug("bubbleSort duration: %lu", c1 - c0);
  mu_assert(is_sorted(array, count) == 1, "Bubble sort should be sorted.");

  c0 = clock();
  quickSort(array2, 0, count-1);
  c1 = clock();
  debug("quickSort duration: %lu", c1 - c0);
  mu_assert(is_sorted(array2, count) == 1, "Quick sort should be sorted.");

  debug("Performance test end");

  return NULL;
}

RUN_TESTS(all_tests);
