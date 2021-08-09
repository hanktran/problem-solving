using namespace std;

#include <iostream>
#include <vector>

class RotationCountOfRotatedArray {
  public:
    static int countRotations(const vector<int> &arr) {
      int start = 0, end = arr.size() - 1;
      while (start < end) {
        int mid = start + (end - start) / 2;
        
        if (mid < end && arr[mid] > arr[mid + 1]) {
          return mid + 1;
        }

        if (mid > start && arr[mid - 1] > arr[mid]) {
          return mid;
        }

        if (arr[start] < arr[mid]) {
          start = mid + 1;
        } else {
          end = mid - 1;
        }
      }

      return 0;
    }
};

class RotationCountWithDuplicates {
  public:
    static int countRotations(const vector<int> &arr) {
      int start = 0, end = arr.size() - 1;
      while (start < end) {
        int mid = start + (end - start) / 2;
        if (mid < end && arr[mid] > arr[mid + 1]) {
          return mid + 1;
        }

        if (mid > start && arr[mid - 1] > arr[mid]) {
          return mid;
        }

        if (arr[start] == arr[mid] && arr[mid] == arr[end]) {
          if (arr[start] > arr[start + 1]) {
            return start + 1;
          }
          ++start;
          
          if (arr[end - 1] > arr[end]) {
            return end;
          }
          --end;
        } else if (arr[start] < arr[mid] || arr[start] == arr[mid] && arr[mid] > arr[end]) {
          start = mid + 1;
        } else {
          end = mid - 1;
        }
      }

      return 0;
    }
};