using namespace std;

#include <algorithm>
#include <iostream>
#include <queue>
#include <vector>

class KLargestNumbers {
  public:
    struct greater {
      bool operator()(const int &a, const int &b) const { return a > b; }
    };
    static vector<int> findKLargestNumbers(const vector<int> &nums, int k) {
      vector<int> minHeap(nums.begin(), nums.begin() + k);
      make_heap(minHeap.begin(), minHeap.end(), greater());

      for (int i = k; i < nums.size(); i++) {
        if (nums[i] > minHeap.front()) {
          pop_heap(minHeap.begin(), minHeap.end(), greater());
          minHeap.pop_back();
          minHeap.push_back(nums[i]);
          push_heap(minHeap.begin(), minHeap.end(), greater());
        }
      }

      return minHeap;
    }
};