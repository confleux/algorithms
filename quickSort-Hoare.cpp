int Partition (int* a, int left, int right) {
  int pivotElement = a[(left + right) / 2];

  int i = left, //el before left
    j = right;  //el after right

  while (true) {
    while (a[i] < pivotElement) {
      ++i;
    }
    while (a[j] > pivotElement) {
      --j;
    }
    if (i >= j) {
      return j;
    }
    swap(a[i++], a[j--]);
  }
}

void QuickSort (int* a, int left, int right) {
  if (left < right) {
    int pivotIndex = Partition(a, left, right);
    QuickSort(a, left, pivotIndex);
    QuickSort(a, pivotIndex + 1, right);
  }
}
