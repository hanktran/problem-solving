using namespace std;

#include <iostream>
#include <queue>
#include <vector>

class ConnectRopes {
  public:
    static int minimumCostToConnectRopes(const vector<int> &ropeLengths) {
      priority_queue<int, vector<int>, greater<int>> minHeap;

      for (int i = 0; i < ropeLengths.size(); i++) {
        minHeap.push(ropeLengths[i]);
      }

      int result = 0, temp = 0;
      while (minHeap.size() > 1) {
        temp = minHeap.top();
        minHeap.pop();
        temp += minHeap.top();
        minHeap.pop();
        result += temp;
        minHeap.push(temp);
      }

      return result;
    }
};