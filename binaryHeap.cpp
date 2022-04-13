using namespace std;

struct BinaryHeap {
  int * a;
  int size;
};

int Left (int i) {
  return (i * 2);  
}
  
int Right (int i) {
  return (i * 2) + 1;  
}
  
int Parent (int i) {
  return (i / 2);
}
  
void MaxHeapify (BinaryHeap A, int i) {
  int l = Left(i);
  int r = Right(i);; 

  int largest;

  if (l <= A.size && A.a[l] > A.a[i]) {
    largest = l;
  } else {
    largest = i;
  }

  if (r <= A.size && A.a[r] > A.a[largest]) {
    largest = r;
  }
  
  if (largest != i) {
    swap(A.a[i], A.a[largest]);
    MaxHeapify(A, largest);
  }
}
