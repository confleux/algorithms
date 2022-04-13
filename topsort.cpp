void topsort(vector<vector<int> >& adj, vector<int>& colour, vector<int>& order, int v) {
  colour[v] = BLACK;
  for (int i = 0; i < adj[v].size(); ++i) {
    if (colour[adj[v][i]] == WHITE) {
      topsort(adj, colour, order, adj[v][i]);
    }
  }
  order.push_back(v);
}

//  do not forget to reverse order vector
