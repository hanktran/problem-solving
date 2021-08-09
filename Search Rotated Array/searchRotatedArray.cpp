using namespace std;

#include <iostream>
#include <vector>

class SearchRotatedArray {
  public:
    static int search(const vector<int> &arr, int key) {
      int start = 0, end = arr.size() - 1;
      while (start <= end) {
        int mid = start + (end - start) / 2;
        if (key == arr[mid]) {
          return arr[mid];
        }

        if ((arr[start] == arr[mid]) && (arr[mid] == arr[end])) {
          ++start; // for situation has dupliates in arr
          --end;
        } else if (arr[start] < arr[mid]) {
          if (key >= arr[start] && key < arr[mid]) {
            end = mid - 1;
          } else {
            start = mid + 1;
          }
        } else {
          if (key > arr[mid] && key <= arr[end]) {
            start = mid + 1;
          } else {
            end = mid - 1;
          }
        }
      }

      return -1;
    }
};