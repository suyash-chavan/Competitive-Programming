#include <iostream>
#include <vector>
#include <climits>
using namespace std;

const int I = INT_MAX; // infinity for int

vector<pair<int, int>> prims(vector<vector<int>> graph) {
  const int N = graph.size() - 1; // number of vertices
  vector<int> near(N+1, I); // size = N+1 because N vertices (1 to N) and 0th empty
  vector<pair<int, int>> MST;

  int u, v, minEdge = I;
  for (int i=1; i<=N; i++) {
    for (int j=1; j<=i; j++) {
      if (graph[i][j] < minEdge) {
        minEdge = graph[i][j];
        u = i;
        v = j;
      }
    }
  }

  MST.push_back({u, v});
  near[u] = near[v] = 0;

  for (int i=1; i<=N; i++) {
    if (near[i] == 0) continue;

    near[i] = (graph[i][u] < graph[i][v]) ? u : v;
  }

  // there will be N-1 edges in MST 
  // and one (0th) is already included (minimum edge)
  // so loop starts from 1
  for (int i=1; i<N-1; i++) {
    minEdge = I;
    int k;
    for (int j=1; j<=N; j++) {
      if (near[j] != 0 && graph[j][near[j]] < minEdge) {
        minEdge = graph[j][near[j]];
        k = j;
      }
    }

    MST.push_back({k, near[k]});
    near[k] = 0;

    for (int j=1; j<=N; j++) {
      if (near[j] != 0 && graph[j][k] < graph[j][near[j]]) 
        near[j] = k;
    }
  }

  return MST;
}

int main() {
  vector<vector<int>> graph = {
    {I, I, I, I, I, I, I, I, I, I},
    {I, I, 8, I, I, I, I, 11, I, 4},
    {I, 8, I, 7, I, 4, I, I, 2, I},
    {I, I, 7, I, 9, 14, I, I, I, I},
    {I, I, I, 9, I, 10, I, I, I, I},
    {I, I, 4, 14, 10, I, 2, I, I, I},
    {I, I, I, I, I, 2, I, 1, 6, I},
    {I, 11, I, I, I, I, 1, I, 7, 8},
    {I, I, 2, I, I, I, 6, 7, I, I},
    {I, 4, I, I, I, I, I, 8, I, I}
  };

  // for (auto row: graph) {
  //   for (auto ele: row) {
  //     if (ele == I)
  //       cout << "I ";
  //     else
  //       cout << ele << " ";
  //   }
  //   cout << "\n";
  // }

  vector<pair<int, int>> MST = prims(graph);

  int cost = 0;
  for (auto edge: MST) {
    cout << edge.first << " --(" << graph[edge.first][edge.second] << ")--> " << edge.second << endl;
    cost += graph[edge.first][edge.second];
  }
  cout << "Total cost of MST: " << cost;

  return 0;
}
