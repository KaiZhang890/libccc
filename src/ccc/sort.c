#include "sort.h"

void bubbleSort(int a[], int c) {
  for (int i = 0; i < c; i++) {
    int c2 = c - i - 1;
    for (int j = 0; j < c2; j++) {
      if (a[j] > a[j+1]) {
        int t = a[j];
        a[j] = a[j+1];
        a[j+1] = t;
      }
    }
  }
}

int partition(int a[], int l, int r) {
  int pivot = a[l];
  int i = l;
  int j = r + 1;
  int t;
  while(1) {
    do ++i; while(pivot >= a[i] && i <= r);
    do --j; while(pivot < a[j]);
    if (i >= j) break;
    t = a[i];
    a[i] = a[j];
    a[j] = t;
  }
  t = a[l];
  a[l] = a[j];
  a[j] = t;

  return j;
}

void quickSort(int a[], int l, int r) {
  int j;
  if (l < r) {
    j = partition(a, l, r);
    quickSort(a, l, j - 1);
    quickSort(a, j + 1, r);
  }
}
