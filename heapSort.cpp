void siftdown (int* arr, int n, int i) {
  while (2 * i + 1 < n) {
    int left = 2 * i + 1;
    int right = 2 * i + 2;
 
    int j = left;
    if (right < n && arr[right] < arr[left]) {
      j = right;
    }
    if (arr[i] <= arr[j]) {
      break;
    }
    swap(arr[i], arr[j]);
    i = j;
  }
}
 
void buildheap (int* arr, int n) {
  for (int i = n / 2; i >= 0 ; --i) {
    siftdown(arr, n, i);
  }
}
 
void heapsort (int* arr, int n) {
  buildheap(arr, n);
  int tmp = n;
  for (int i = 0; i < n - 1; ++i) {
    swap(arr[0], arr[n - 1 - i]);
    --tmp;
    siftdown(arr, tmp, 0);
  }
}
