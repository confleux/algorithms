using namespace std;

int Partition (int* a, int left, int right) {
  int pivot = a[right];
  //i is a pointer to the next from last element of array of values less than pivot
  int i = left;
  
  //j is a pointer to the next from last element of array of values bigger than pivot
  for (int j = left; j < right; ++j) {
    if (a[j] < pivot) {
      swap(a[i], a[j]);
      ++i;
    }
  }

  swap(a[i], a[right]);
  return i;
}

void QuickSort (int* a, int left, int right) {
  if (left < right) {
    int pivot = Partition(a, left, right); 
    QuickSort(a, left, pivot - 1);
    QuickSort(a, pivot + 1, right);
  }
}


