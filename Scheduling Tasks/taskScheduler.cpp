using namespace std;

#include <iostream>
#include <queue>
#include <unordered_map>
#include <vector>

class TaskSchedular {
  public:
    struct valueCompare {
      char operator()(const pair<int, int> &x, pair<int, int> &y) {
        return y.second > x.second;
      }
    };

    static int scheduleTasks(vector<char> &tasks, int k) {
      int intervalCount = 0;
      unordered_map<char, int> taskFrequencyMap;
      for (char chr : tasks) {
        taskFrequencyMap[chr]++;
      }

      priority_queue<pair<char, int>, vector<pair<char, int>>, valueCompare> maxHeap;
      for (auto entry : taskFrequencyMap) {
        maxHeap.push(entry);
      }

      while (!maxHeap.empty()) {
        vector<pair<char, int>> waitList;
        int n = k + 1;
        for (; n > 0 && !maxHeap.empty(); i--) {
          intervalCount++;
          auto currentEntry = maxHeap.top();
          maxHeap.pop();
          if (currentEntry.second > 1) {
            currentEntry.second--;
            waitList.push_back(currentEntry);
          }
        }

        for (auto it = waitList.begin(); it != waitList.end(); it++) {
          maxHeap.push(*it);
        }

        if (!maxHeap.empty()) {
          intervalCount += n;
        }
      }

      return intervalCount;
    }
};