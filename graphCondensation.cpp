void topsort(vector<vector<int> >& adj, vector<int>& colour, vector<int>& order, int v) {
  colour[v] = BLACK;
  for (int i = 0; i < adj[v].size(); ++i) {
    if (colour[adj[v][i]] == WHITE) {
      topsort(adj, colour, order, adj[v][i]);
    }
  }
  order.push_back(v);
}
 
void findComponent(vector<vector<int> >& adj, vector<int>& colour, vector<int>& components, int v, int c) {
  colour[v] = BLACK;
  components[v] = c;
  for (int i = 0; i < adj[v].size(); ++i) {
    if (colour[adj[v][i]] == WHITE) {
      findComponent(adj, colour, components, adj[v][i], c);
    }
  }
}
