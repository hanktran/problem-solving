using namespace std;

#include <iostream>
#include <limits>
#include <vector>

class ArrayReader {
  public:
    vector<int> arr;

    ArrayReader(const vector<int> &arr) {
      this->arr = arr;
    }

    virtual int get(int index) {
      if (index >= arr.size()) {
        return numeric_limits<int>::max();
      }
      return arr[index];
    }
};

class SearchInfiniteSortedArray {
  public:
    static int search(ArrayReader *reader, int key) {
      int start = 0, end = 1;
      while (reader->get(end) < key) {
        int newStart = end + 1;
        end += (end - start + 1) * 2;
        start = newStart;
      }
      return binarySearch(reader, key, start, end);
    }

  private:
    static int binarySearch(ArrayReader *reader, int key, int start, int end) {
      while (start <= end) {
        int mid = start + (end - start) / 2;
        if (key < reader->get(mid)) {
          end = mid - 1;
        } else if (key > reader->get(mid)) {
          start = mid + 1;
        } else {
          return mid;
        }
      }

      return -1;
    }
};
