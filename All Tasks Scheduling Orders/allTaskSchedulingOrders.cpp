using namespace std;

#include <algorithm>
#include <iostream>
#include <queue>
#include <string>
#include <unordered_map>
#include <vector>

class AllTaskSchedulingOrders {
  public:
    static void printOrders(int tasks, vector<vector<int>> &prerequisites) {
      vector<int> sortedOrder;
      if (tasks <= 0) {
        return;
      }

      unordered_map<int, int> inDegree;
      unordered_map<int, vector<int>> graph;
      for (int i = 0; i < tasks; i++) {
        inDegree[i] = 0;
        graph[i] = vector<int>();
      }

      for (int i = 0; i < prerequisites.size(); i++) {
        int parent = prerequisites[i][0], child = prerequisites[i][1];
        graph[parent].push_back(child);
        inDegree[child]++;
      }

      vector<int> sources;
      for (auto entry : inDegree) {
        if (entry.second == 0) {
          sources.push_back(entry.first);
        }
      }

      printAllTopoligicalSorts(graph, inDegree, sources, sortedOrder);
    }

  private:
    static void printAllTopoligicalSorts(unordered_map<int, vector<int>> &graph, unordered_map<int, int> &inDegree, const vector<int> &sources, vector<int> &sortedOrder) {
      if (!sources.empty()) {
        for (int vertex : sources) {
          sortedOrder.push_back(vertex);

          vector<int> sourcesForNextCall = sources;
          sourcesForNextCall.erase(find(sourcesForNextCall.begin(), sourcesForNextCall.end(), vertex));

          vector<int> children = graph[vertex];
          for (auto child : children) {
            inDegree[child]--;
            if (inDegree[child] == 0) {
              sourcesForNextCall.push_back(child);
            }
          }

          printAllTopoligicalSorts(graph, inDegree, sourcesForNextCall, sortedOrder);

          sortedOrder.erase(find(sortedOrder.begin(), sortedOrder.end(), vertex));
          for (auto child : children) {
            inDegree[child]++;
          }
        }
      }

      if (sortedOrder.size() == inDegree.size()) {
        for (int num : sortedOrder) {
          cout << num << " ";
        }
        cout << endl;
      }
    }
};

int main(int argc, char *argv[]) {
  vector<vector<int>> vec = {{0, 1}, {1, 2}};
  AllTaskSchedulingOrders::printOrders(3, vec);
  cout << endl;

  vec = {{3, 2}, {3, 0}, {2, 0}, {2, 1}};
  AllTaskSchedulingOrders::printOrders(4, vec);
  cout << endl;

  vec = {{2, 5}, {0, 5}, {0, 4}, {1, 4}, {3, 2}, {1, 3}};
  AllTaskSchedulingOrders::printOrders(6, vec);
  cout << endl;
}