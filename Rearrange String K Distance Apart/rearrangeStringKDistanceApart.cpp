using namespace std;

#include <iostream>
#include <queue>
#include <string>
#include <unordered_map>
#include <vector>

class RearrangeStringKDistanceApart {
  public:
    struct valueCompare {
      char operator()(const pair<int, int> &x, const pair<int, int> &y) {
        return y.second > x.second;
      }
    };

    static string reorganizeString(const string &str, int k) {
      if (k <= 1) return str;

      unordered_map<char, int> charFrequencyMap;
      for (char chr : str) {
        charFrequencyMap[chr]++;
      }

      priority_queue<pair<char, int>, vector<pair<char, int>>, valueCompare> maxHeap;
      for (auto entry : charFrequencyMap) {
        maxHeap.push(entry);
      }

      queue<pair<char, int>> queue;
      string resultString;
      while (!maxHeap.empty()) {
        auto currentEntry = maxHeap.top();
        maxHeap.pop();
        resultString += currentEntry.first;
        currentEntry.second--;
        queue.push(currentEntry);
        if (queue.size() == k) {
          auto entry = queue.front();
          queue.pop();
          if (entry.second > 0) {
            maxHeap.push(entry);
          }
        }
      }

      return resultString.length() == str.length() ? resultString : "";
    }
};