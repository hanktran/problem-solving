using namespace std;

#include <iostream>
#include <vector>

class MaxInBitonicArray {
  public:
    static int findMax(const vector<int>& arr) {
      int start = 0, end = arr.size() - 1;
      while (start < end) {
        int mid = start + (end - start) / 2;
        if (arr[mid] > arr[mid + 1]) {
          end = mid;
        } else {
          start = mid + 1;
        }
      }

      return arr[start];
    }
};