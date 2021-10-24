#include <fstream>
#include <iostream>

using namespace std;

int main () {
  ifstream ifs("antiqs.in");

  int n;
  ifs >> n;

  int arr[n];
  for (int i = 1; i <= n; ++i) {
    arr[i - 1] = i;
  }
  for (int i = 2; i < n; ++i) {
   swap(arr[i], arr[i / 2]);
  }

  ofstream ofs("antiqs.out");
  for (int i = 0; i < n; i++)
  {
    ofs << arr[i] << " ";
  }
  
  ofs.close();

  return 0;
}
