using namespace std;

#include <iostream>
#include <queue>
#include <vector>

class SumOfElements {
  public:
    struct numCompare {
      bool operator()(const int &x, const int &y) {
        return x > y;
      }
    };

    static int findSumOfElements(const vector<int>, &nums, int k1, int k2) {
      priority_queue<int, vector<int>, numCompare> minHeap;
      for (int i = 0; i < nums.size(); i++) {
        minHeap.push(nums[i]);
      }

      for (int i = 0; i < k1; i++) {
        minHeap.pop();
      }

      int elementSum = 0;
      for (int i = 0; i < k2 - k1 - 1; i++) {
        elementSum += minHeap.top();
        minHeap.pop();
      }

      return elementSum;
    }
};

class SumOfElements1 {
  public:
    static int findSumOfElements(const vector<int> &nums, int k1, int k2) {
      priority_queue<int> maxHeap;
      for (int i = 0; i < nums.size(); i++) {
        if (i < k2 - 1) {
          maxHeap.push(nums[i]);
        } else if (nums[i] < maxHeap.top()) {
          maxHeap.pop();
          maxHeap.push(nums[i]);
        }
      }

      int elementSum = 0;
      for (int i = 0; i < k2 - k1 - 1; i++) {
        elementSum += maxHeap.top();
        maxHeap.pop();
      }

      return elementSum;
    }
};