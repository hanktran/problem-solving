using namespace std;

#include <iostream>
#include <vector>
#include <unordered_map>
#include <queue>

void scheduleProcess(int vertices, vector<vector<int>> edges, vector<int> &sortedOrder) {
  if (vertices <= 0) {
    return;
  }

  unordered_map<int, int> inDegree;
  unordered_map<int, vector<int>> graph;
  for (int i = 0; i < vertices; i++) {
    inDegree[i] = 0;
    graph[i] = {};
  }

  for (int i = 0; i < edges.size(); i++) {
    int parent = edges[i][1], child = edges[i][0];
    graph[parent].push_back(child);
    inDegree[child] += 1;
  }

  queue<int> sources;
  for (auto itr = inDegree.begin(); itr != inDegree.end(); itr++) {
    if (itr->second == 0) {
      sources.push(itr->first);
    }
  }

  while (!sources.empty()) {
    int vertex = sources.front();
    sources.pop();
    sortedOrder.push_back(vertex);
    vector<int> children = graph[vertex];
    for (int child : children) {
      inDegree[child] -= 1;
      if (inDegree[child] == 0) {
        sources.push(child);
      }
    }
  }

  if (sortedOrder.size() != vertices) {
    sortedOrder.clear();
  }
}

void print(vector<int> &result) {
  cout << "[";
  for (int i = 0; i < result.size(); i++) {
    cout << result[i];
    if (i < result.size() - 1) {
      cout << ", ";
    }
  }
  cout << "]" << endl;
}

int main() {
  int n = 4;
  vector<vector<int>> dependencies =  {{1,0},{2,0},{3,1},{3,2}};
  vector<int> result;
  scheduleProcess(4, dependencies, result);
  print(result);
  return 0;
}