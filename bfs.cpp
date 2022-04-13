void BFS(const vector<vector<int> >& arr, vector<int>& explored, int root, int distance) {
  queue<int> q;
  explored[root] = distance;
  q.push(root);
  while (!q.empty()) {
    int v = q.front();
    q.pop();
    for (int i = 0; i < arr[v].size(); ++i) {
      if (explored[arr[v][i]] == 0) {
        explored[arr[v][i]] = explored[v] + 1;
        q.push(arr[v][i]);
      }
    }
  }
}
