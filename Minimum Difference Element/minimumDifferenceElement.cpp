using namespace std;

#include <iostream>
#include <vector>

class MininumDifference {
  public:
    static int searchMinDiffElement(const vector<int> &arr, int key) {
      if (key < arr[0]) {
        return arr[0];
      }

      if (key > arr[arr.size() - 1]) {
        return arr[arr.size() - 1];
      }

      int start = 0, end = arr.size() - 1;
      while (start <= end) {
        int mid = start + (end - start) / 2;
        if (key < arr[mid]) {
          end = mid - 1;
        } else if (key > arr[mid]) {
          start = mid + 1;
        } else {
          return arr[mid];
        }
      }

      if ((arr[start] - key) < (key - arr[end])) {
        return arr[start];
      }
      return arr[end];
    }
};