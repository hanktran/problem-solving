using namespace std;

#include <iostream>
#include <vector>

class FindRange {
  public:
    static pair<int, int> findRange(const vector<int> &arr, int key) {
      pair<int, int> result(-1, -1);
      result.first = search(arr, key, false);
      if (result.first != -1) {
        result.second = search(arr, key, true);
      }
      return result;
    }

  private:
    static int search(const vector<int> &arr, int key, bool findMaxIndex) {
      int keyIndex = -1;
      int start = 0;
      int end = arr.size() - 1;
      while (start <= end) {
        int mid = start + (end - start) / 2;
        if (key < arr[mid]) {
          end = mid - 1;
        } else if (key > arr[mid]) {
          start = mid + 1;
        } else {
          keyIndex = mid;
          if (findMaxIndex) {
            start = mid + 1;
          } else {
            end = mid - 1;
          }
        }
      }

      return keyIndex;
    }
};