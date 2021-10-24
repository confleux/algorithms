using namespace std;

void InsertionSort (int * a, int n) {
  for (int i = 1; i < n; ++i) {
    int key = a[i];
    int j = i - 1;
    while (j > -1  && key < a[j]) {
      cout << "i: " << i << " j: " << j << "\n";
      a[j + 1] = a[j];
      --j; 
    }
    a[j + 1] = key;
  }
}
