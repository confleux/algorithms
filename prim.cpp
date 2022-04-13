void prim(int n, vector<bool>& used, vector<double>& minimalEdge, vector<int>& path, vector<vector<double> >& weightAdj, double& result) {
  for (int i = 0; i < n; ++i) {
    int v = -1;
 
    for (int j = 0; j < n; ++j) {
      if (!used[j] && (v == -1 || minimalEdge[v] > minimalEdge[j])) {
        v = j;
      }
    }

    used[v] = true;
    if (path[v] != -1) {
      result += weightAdj[v][path[v]];
    }
 
    for (int j = 0; j < n; ++j) {
      if (weightAdj[v][j]  < minimalEdge[j]) {
        minimalEdge[j] = weightAdj[v][j];
        path[j] = v;
      }
    }
  }
}
