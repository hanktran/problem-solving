using namespace std;

#include <iostream>
#include <queue>
#include <vector>

class KthLargestNumberInStream {
  public:
    struct numCompare {
      bool operator()(const int &x, const int &y) { return x > y; }
    };

  priority_queue<int, vector<int>, numCompare> minHeap;
  const int k;

  KthLargestNumberInStream(const vector<int> &nums, int k): k(k) {
    for (int i = 0; i < nums.size(); i++) {
      add(nums[i]);
    }
  }

  virtual int add(int num) {
    minHeap.push(num);

    if ((int)minHeap.size() > this->k) {
      minHeap.pop();
    }

    return minHeap.top();
  }
};