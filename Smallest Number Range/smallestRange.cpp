using namespace std;

#include <iostream>
#include <limits>
#include <queue>
#include <vector>

class SmallestRange {
  public:
    struct valueCompare {
      bool operator()(const pair<int, pair<int, int>> &x, const pair<int, pair<int, int>> &y) {
        return x.first > y.first;
      }
    };

    static pair<int, int> findSmallestRange(const vector<vector<int>> &lists) {
      priority_queue<pair<int, pair<int, int>>, vector<pair<int, pair<int, int>>>, valueCompare> minHeap;

      int rangeStart = 0, rangeEnd = numeric_limits<int>::max(), currentmaxNumber = numeric_limits<int>::min();

      for (int i = 0; i < lists.size(); i++) {
        if (!lists[i].empty()) {
          minHeap.push(make_pair(lists[i][0], make_pair(i, 0)));
          currentmaxNumber = max(currentmaxNumber, lists[i][0]);
        }
      }

      while (minHeap.size() == lists.size()) {
        auto node = minHeap.top();
        minHeap.pop();
        if (rangeEnd - rangeStart > currentmaxNumber - node.first) {
          rangeStart = node.first;
          rangeEnd = currentmaxNumber;
        }

        node.second.second++;
        if (lists[node.second.first].size() > node.second.second) {
          node.first = lists[node.second.first][node.second.second];
          minHeap.push(node);
          currentmaxNumber = max(currentmaxNumber, node.first);
        }
      }

      return make_pair(rangeStart, rangeEnd);
    }
};