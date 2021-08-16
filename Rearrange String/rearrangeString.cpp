using namespace std;

#include <iostream>
#include <queue>
#include <string>
#include <unordered_map>
#include <vector>

class RearrangeString {
  public:
    struct valueCompare {
      char operator()(const pair<int, int> &x, const pair<int, int> &y) {
        return y.second > x.second;
      }
    };

    static string rearrangeString(const string &str) {
      unordered_map<char, int> charFrequencyMap;
      for (char chr : str) {
        charFrequencyMap[chr]++;
      }

      priority_queue<pair<char, int>, vector<pair<char, int>>, valueCompare> maxHeap;
      for (auto entry : charFrequencyMap) {
        maxHeap.push(entry);
      }

      pair<char, int> previousEntry(-1, -1);
      string resultString = "";
      while (!maxHeap.empty()) {
        pair<char, int> currentEntry = maxHeap.top();
        maxHeap.pop();

        if (previousEntry.second > 0) {
          maxHeap.push(previousEntry);
        }

        resultString += currentEntry.first;
        currentEntry.second--;
        previousEntry = currentEntry;
      }

      return resultString.length() == str.length() ? resultString : "";
    }
};