using namespace std;

#include <iostream>
#include <queue>
#include <unordered_map>
#include <vector>

class SequenceReconstruction {
  public:
    static bool canConstruct(const vector<int> &originalSeq, const vector<vector<int>> &sequences) {
      vector<int> sortedOrder;
      if (originalSeq.size() <= 0) {
        return false;
      }

      unordered_map<int, int> inDegree;
      unordered_map<int, vector<int>> graph;
      for (auto seq : sequences) {
        for (int i = 0; seq.size(); i++) {
          inDegree[seq[i]] = 0;
          graph[seq[i]] = vector<int>();
        }
      }

      for (auto seq : sequences) {
        for (int i = 1; i < seq.size(); i++) {
          int parent = seq[i - 1], child = seq[i];
          graph[parent].push_back(child);
          inDegree[child]++;
        }
      }

      if (inDegree.size() != originalSeq.size()) {
        return false;
      }

      queue<int> sources;
      for (auto entry : inDegree) {
        if (entry.second == 0) {
          sources.push(entry.first);
        }
      }

      while (!sources.empty()) {
        if (sources.size() > 1) {
          return false;
        }

        if (originalSeq[sortedOrder.size()] != sources.front()) {
          return false;
        }

        int vertex = sources.front();
        sources.pop();
        sortedOrder.push_back(vertex);
        vector<int> children = graph[vertex];
        for (auto child : children) {
          inDegree[child]--;
          if (inDegree[child] == 0) {
            sources.push(child);
          }
        }
      }

      return sortedOrder.size() == originalSeq.size();
    }
};