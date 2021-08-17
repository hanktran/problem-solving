using namespace std;

#include <iostream>
#include <queue>
#include <vector>

class KthSmallestInMSortedArrays {
  public:
    struct valueCompare {
      bool operator()(const pair<int, pair<int, int>> &x, const pair<int, pair<int, int>> &y) {
        return x.first > y.first;
      }
    };

    static int findKthSmallest(const vector<vector<int>> &lists, int k) {
      priority_queue<pair<int, pair<int, int>>, vector<pair<int, pair<int, int>>>, valueCompare> minHeap;
      for (int i = 0; i < lists.size(); i++) {
        if (!lists[i].empty()) {
          minHeap.push(make_pair(lists[i][0], make_pair(i, 0)));
        }
      }

      int numberCount = 0, result = 0;
      while (!minHeap.empty()) {
        auto node = minHeap.top();
        minHeap.pop();
        result = node.first;
        if (++numberCount == k) {
          break;
        }
        node.second.second++;
        if (lists[node.second.first].size() > node.second.second) {
          node.first = lists[node.second.first][node.second.second];
          minHeap.push(node);
        }
      }

      return result;
    }
};