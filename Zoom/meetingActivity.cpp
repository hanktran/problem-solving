using namespace std;

#include <iostream>
#include <vector>
#include <unordered_map>
#include <unordered_set>

int minSteps(vector<int> &k) {
  int n = k.size();
  if (n <= 1) {
    return 0;
  }

  unordered_map<int, vector<int>> graph;
  for (int i = 0; i < n; i++) {
    if (graph.find(k[i]) == graph.end()) {
      graph[k[i]] = {i};
    } else {
      graph[k[i]].push_back(i);
    }
  }

  vector<int> current;
  current.push_back(0);
  unordered_set<int> visited;
  int step = 0;

  while (!current.empty()) {
    vector<int> nextNode;

    for (int node : current) {
      if (node == n - 1) {
        return step;
      }

      for (int child : graph[k[node]]) {
        if (visited.find(child) == visited.end()) {
          visited.insert(child);
          nextNode.push_back(child);
        }
      }

      graph[k[node]].clear();

      if (node + 1 < n && visited.find(node + 1) == visited.end()) {
        visited.insert(node + 1);
        nextNode.push_back(node + 1);
      }

      if (node - 1 >= 0 && visited.find(node - 1) == visited.end()) {
        visited.insert(node - 1);
        nextNode.push_back(node - 1);
      }
    }
    current = nextNode;
    step++;
  }
  return -1;
}

int main() {
  vector<int> k = {1, 2, 3, 4, 1, 3, 5, 3, 5};
  cout << to_string(minSteps(k)) << endl;
  return 0;
}