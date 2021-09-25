using namespace std;

#include <iostream>
#include <vector>
#include <queue>

int minVariationLength(vector<int> &nums, int threshold) {
  deque<int> maxDeque;
  deque<int> minDeque;
  int start = 0, end = 0;
  int ans = 0;

  while (end < nums.size()) {
    while (!minDeque.empty() && nums[end] < nums[minDeque.back()]) {
      minDeque.pop_back();
    }

    while (!maxDeque.empty() && nums[end] > nums[maxDeque.front()]) {
      maxDeque.pop_back();
    }

    minDeque.push_back(end);
    maxDeque.push_back(end);

    int variation = nums[maxDeque.front()] - nums[minDeque.front()];
    if (variation > threshold) {
      start++;
      
      if (start > minDeque.front()) {
        minDeque.pop_front();
      }

      if (start > maxDeque.front()) {
        maxDeque.pop_front();
      }
    }

    ans = max(ans, (end - start + 1));
    end++;
  }

  return ans;
}

int main() {
  vector<int> trafficRates = {10, 1, 2, 4, 7, 2};
  int thresholdMinVal = 5;
  cout << "The traffic of this customer changes by less than or equal to " << to_string(thresholdMinVal) << " Gbps in a " << to_string(minVariationLength(trafficRates, thresholdMinVal)) << " day window\n";
  return 0;
}