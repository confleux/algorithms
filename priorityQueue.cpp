struct Heap {
  vector<int> arr;
  vector<int> priority;
  int n = 0;
 
  void push (int x, int p) {
    arr.push_back(x);
    priority.push_back(p);
    ++n;
 
    siftUp(n - 1);
  }
 
  int extractMin () {
    if (n == 0) {
      return -1;
    }
 
    int returnValue = arr[0];
 
    arr[0] = arr[n - 1];
    priority[0] = priority[n - 1];
 
    arr.pop_back();
    priority.pop_back();
    --n;
 
    siftDown(0);
    return returnValue;
  }
 
  void decreaseKey (int key, int x) {
    int index = 0;
    for (int i = 0; i < n; ++i) {
      if (priority[i] == key) {
        index = i;
        break;
      }
    }
    arr[index] = x;
    siftUp(index);
  }
 
  void siftDown (int i) {
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
      swap(priority[i], priority[j]);
      i = j;
    }
  }
 
  void siftUp (int i) {
    while (arr[i] < arr[(i - 1) / 2]) {
      swap(arr[i], arr[(i - 1) / 2]);
      swap(priority[i], priority[(i - 1) / 2]);
      i = (i - 1) / 2;
    }
  }
};
