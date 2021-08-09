using namespace std;

#include <iostream>
#include <vector>

class SearchBitonicArray {
  public:
    static int search(const vector<int> &arr, int key) {
      int maxIndex = findMax(arr);
      int keyIndex = binarySearch(arr, key, 0, maxIndex);
      if (keyIndex != -1) {
        return keyIndex;
      }
      return binarySearch(arr, key, maxIndex + 1, arr.size() - 1);
    }

    static int findMax(const vector<int> &arr) {
      int start = 0, end = arr.size() - 1;
      while (start < end) {
        int mid = start + (end - start) / 2;
        if (arr[mid] < arr[mid + 1]) {
          start = mid + 1;
        } else {
          end = mid;
        }
      }

      return start;
    }

  private:
    static int binarySearch(const vector<int> &arr, int key, int start, int end) {
      while (start <= end) {
        int mid = start + (end - start) / 2;
        if (key == arr[mid]) {
          return mid;
        }

        if (arr[start] > arr[end]) {
          if (key > arr[mid]) {
            end = mid - 1;
          } else {
            start = mid + 1;
          }
        } else {
          if (key > arr[mid]) {
            start = mid + 1;
          } else {
            end = mid - 1;
          }
        }
      }

      return -1;
    }
};