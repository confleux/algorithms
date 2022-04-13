void radixsort(vector<vector<int>> arr, int n, int m, int k) {
  for (int i = m - 1; i >= m - k; --i) {
    int* count = new int[LETTERS];
    for (int j = 0; j < LETTERS; ++j) {
      count[j] = 0;
    }
     
    for (int j = 0; j < n; ++j) {
      int digit = arr[j][i];
      count[digit] += 1;
    }
 
    int sum = 0;
    for (int j = 0; j < LETTERS; ++j) {
      int tmp = count[j];
      count[j] = sum;
      sum += tmp;
    }
 
    vector<vector<int>> res(n, vector<int>(m));
 
    for (int j = 0; j < n; ++j) {
      int digit = arr[j][i];
      res[count[digit]] = arr[j];
      count[digit] += 1;
    }
 
    arr = res;
}
