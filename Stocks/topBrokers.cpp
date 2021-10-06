#include <iostream>
#include <vector>
#include <queue>
#include <unordered_map>

using namespace std;

vector<int> topBrokers(vector<int> brokerIDs, int k) {
  unordered_map<int, int> numFrequencyMap;
  for (int n : brokerIDs) {
    if (numFrequencyMap.find(n) == numFrequencyMap.end()) {
      numFrequencyMap[n] = 0;
    }
    numFrequencyMap[n] += 1;
  }

  priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> minHeap;
  for (auto &entry : numFrequencyMap) {
    minHeap.push(pair<int, int>(entry.first, entry.second));
    if (minHeap.size() > k) {
      minHeap.pop();
    }
  }

  vector<int> topNumbers;
  while (!minHeap.empty()) {
    auto pair = minHeap.top();
    minHeap.pop();
    topNumbers.push_back(pair.first);
  }

  return topNumbers;
}

void print(vector<int> result) {
  cout << "[";
  for (int i = 0; i < result.size(); i++) {
    cout << result[i];
    if (i < result.size() - 1) {
      cout << ", ";
    }
  }
  cout << "]";
}

int main() {
  vector<int> result = topBrokers({ 1, 3, 5, 12, 11, 12, 11, 12, 5 }, 3);
  print(result);
  return 0;
}