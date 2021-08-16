using namespace std;

#include <iostream>
#include <queue>
#include <unordered_map>
#include <vector>

class MaximumDistinctElements {
  public:
    struct valueCompare {
      bool operator()(const pair<int, int> &x, const pair<int, int> &y) {
        return x.second > y.second;
      }
    };

    static int findMaximumDistinctElements(const vector<int> &nums, int k) {
      int distinctElementsCount = 0;
      if (nums.size() <= k) {
        return distinctElementsCount;
      }

      unordered_map<int, int> numFrequencyMap;
      for (auto i : nums) {
        numFrequencyMap[i]++;
      }

      priority_queue<pair<int, int>, vector<pair<int, int>>, valueCompare> minHeap;
      for (auto entry : numFrequencyMap) {
        if (entry.second == 1) {
          distinctElementsCount++;
        } else {
          minHeap.push(entry);
        }
      }

      while (k > 0 && !minHeap.empty()) {
        auto entry = minHeap.top();
        minHeap.pop();
        k -= entry.second - 1;
        if (k > 0) {
          distinctElementsCount++;
        }
      }

      if (k > 0) {
        distinctElementsCount -= k;
      }

      return distinctElementsCount;
    }
};