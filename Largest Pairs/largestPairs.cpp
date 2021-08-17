using namespace std;

#include <iostream>
#include <queue>
#include <vector>

class LargestPairs {
  public:
    struct sumCompare {
      bool operator()(const pair<int, int> &x, const pair<int, int> &y) {
        return (x.first + x.second) > (y.first + y.second);
      }
    };

    static vector<pair<int, int>> findKLargestPairs(const vector<int> &nums1, const vector<int> &nums2, int k) {
      vector<pair<int, int>> minHeap;
      for (int i = 0; i < nums1.size() && i < k; i++) {
        for (int j = 0; j < nums2.size() && j < k; j++) {
          if (minHeap.size() < k) {
            minHeap.push_back(make_pair(nums1[i], nums2[j]));
            push_heap(minHeap.begin(), minHeap.end(), sumCompare());
          } else {
            if ((nums1[i] + nums2[j]) < (minHeap.front().first + minHeap.front().second)) {
              break;
            } else {
              pop_heap(minHeap.begin(), minHeap.end(), sumCompare());
              minHeap.pop_back();
              minHeap.push_back(make_pair(nums1[i], nums2[j]));
              push_heap(minHeap.begin(), minHeap.end(), sumCompare());
            }
          }
        }
      }

      return minHeap;
    }
};