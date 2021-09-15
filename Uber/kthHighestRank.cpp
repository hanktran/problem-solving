using namespace std;

#include <iostream>
#include <vector>
#include <queue>

int kthHighestRank(vector<int> &ranks, int k) {
  priority_queue<int, vector<int>, greater<int>> minHeap;
  for (int i = 0; i < k; i++) {
    minHeap.push(ranks[i]);
  }

  for (int i = k; i < ranks.size(); i++) {
    if (ranks[i] > minHeap.top()) {
      minHeap.pop();
      minHeap.push(ranks[i]);
    }
  }

  return minHeap.top();
}

int main() {
  vector<int> driverID = {1, 5, 12, 2, 11, 9, 7, 30, 20};
  int k = 3;
  cout << "Driver with the rank " << to_string(kthHighestRank(driverID, k)) + " is selected!" << endl;
}