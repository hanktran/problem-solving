using namespace std;

#include <iostream>
#include <queue>
#include <unordered_map>
#include <vector>

class TaskSchedulingOrder {
  public:
    static vector<int> findOrder(int tasks, const vector<vector<int>> &prerequisites) {
      vector<int> sortedOrder;
      if (tasks <= 0) {
        return sortedOrder;
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

      queue<int> sources;
      for (auto entry : inDegree) {
        if (entry.second == 0) {
          sources.push(entry.first);
        }
      }

      while (!sources.empty()) {
        int vertex = sources.front();
        sources.pop();
        sortedOrder.push_back(vertex);
        vector<int> children = graph[vertex];
        for (auto child : children) {
          inDegree[child]--;
          if(inDegree[child] == 0) {
            sources.push(child);
          }
        }
      }

      if (sortedOrder.size() != tasks) {
        return vector<int>();
      }

      return sortedOrder;
    }
};