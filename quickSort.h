using namespace std;

int Partition (int * a, int left, int right) {
  int pivot = a[right];
  int i = left;
  
  for (int j = left; j < right; ++j) {
    if (a[j] < pivot) {
      swap(a[i], a[j]);
      ++i;
    }
  }

  swap(a[i], a[right]);
  return i;
}

void QuickSort (int * a, int left, int right) {
  if (left < right) {
    int pivot = Partition(a, left, right); 
    QuickSort(a, left, pivot - 1);
    QuickSort(a, pivot + 1, right);
  }
}


