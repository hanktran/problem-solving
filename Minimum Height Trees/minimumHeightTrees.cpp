using namespace std;

#include <deque>
#include <iostream>
#include <string>
#include <unordered_map>
#include <vector>

class MinimumHeightTrees {
  public:
    static vector<int> findTrees(int nodes, vector<vector<int>> &edges) {
      vector<int> minHeightTrees;
      if (nodes <= 0) {
        return minHeightTrees;
      }

      if (nodes == 1) {
        minHeightTrees.push_back(0);
        return minHeightTrees;
      }

      unordered_map<int, int> inDegree;
      unordered_map<int, vector<int>> graph;
      for (int i = 0; i < nodes; i++) {
        inDegree[i] = 0;
        graph[i] = vector<int>();
      }

      for (int i = 0; i < edges.size(); i++) {
        int n1 = edges[i][0], n2 = edges[i][1];
        graph[n1].push_back(n2);
        graph[n2].push_back(n1);

        inDegree[n1]++;
        inDegree[n2]++;
      }

      deque<int> leaves;
      for (auto entry : inDegree) {
        if (entry.second == 1) {
          leaves.push_back(entry.first);
        }
      }

      int totalNodes = nodes;
      while (totalNodes > 2) {
        int leavesSize = leaves.size();
        totalNodes -= leavesSize;
        for (int i = 0; i < leavesSize; i++) {
          int vertex = leaves.front();
          leaves.pop_front();
          vector<int> children = graph[vertex];
          for (auto child : children) {
            inDegree[child]--;
            if (inDegree[child] == 1) {
              leaves.push_back(child);
            }
          }
        }
      }

      std::move(std::begin(leaves), std::end(leaves), std::back_inserter(minHeightTrees));
      return minHeightTrees;
    }
};

int main(int argc, char* argv[]) {
  vector<vector<int>> vec = {{0, 1}, {1, 2}, {1, 3}, {2, 4}};
  vector<int> result = MinimumHeightTrees::findTrees(5, vec);
  cout << "Roots of MHTs: ";
  for (auto num : result) {
    cout << num << " ";
  }
  cout << endl;

  vec = {{0, 1}, {0, 2}, {2, 3}};
  result = MinimumHeightTrees::findTrees(4, vec);
  cout << "Roots of MHTs: ";
  for (auto num : result) {
    cout << num << " ";
  }
  cout << endl;

  vec = {{0, 1}, {1, 2}, {1, 3}};
  result = MinimumHeightTrees::findTrees(4, vec);
  cout << "Roots of MHTs: ";
  for (auto num : result) {
    cout << num << " ";
  }
  cout << endl;
}