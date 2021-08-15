using namespace std;

#include <iostream>
#include <queue>
#include <vector>

class KthSmallestNumber {
  public:
    static int findKthSmallestNumber(const vector<int> &nums, int k) {
      priority_queue<int> maxHeap;

      for (int i = 0; i < k; i++) {
        maxHeap.push(nums[i]);
      }

      for (int i = k; i < nums.size(); i++) {
        if (nums[i] < maxHeap.top()) {
          maxHeap.pop();
          maxHeap.push(nums[i]);
        }
      }

      return maxHeap.top();
    }
};