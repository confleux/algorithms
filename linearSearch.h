using namespace std;

void LinearSearch (int * a, int n, int x) {
  for (int i = 0; i < n; ++i) {
    if (x == a[i]) {
      return i;
    }
  }
  return -1;
}
