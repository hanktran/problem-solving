using namespace std;

#include <algorithm>
#include <iostream>
#include <queue>
#include <vector>

class KClosestElements {
  public:
    struct numCompare {
      bool operator()(const pair<int, int> &x, const pair<int, int> &y) {
        return x.first > y.first;
      }
    };

    static vector<int> findClosestElements(const vector<int> &arr, int K, int X) {
      int index = binarySearch(arr, X);
      int low = index - K, high = index + K;
      low = max(low, 0);
      high = min(high, (int)arr.size() - 1);

      priority_queue<pair<int, int>, vector<pair<int, int>>, numCompare> minHeap;
      for (int i = low; i <= high; i++) {
        minHeap.push(make_pair(abs(arr[i] - X), i));
      }

      vector<int> result;
      for (int i = 0; i < K; i++) {
        result.push_back(arr[minHeap.top().second]);
      }

      sort(result.begin(), result.end());
      return result;
    }

  private:
    static int binarySearch(const vector<int> &arr, int target) {
      int low = 0;
      int high = (int)arr.size() - 1;
      while (low < high) {
        int mid = low + (high - low) / 2;
        if (arr[mid] == target) {
          return mid;
        }

        if (arr[mid] < target) {
          low = mid + 1;
        } else {
          high = mid - 1;
        }
      }

      if (low > 0) {
        return low - 1;
      }
      return low;
    }
};

class KClosestElements2 {
  public:
    static vector<int> findClosetElements(const vector<int> &arr, int K, int X) {
      deque<int> result;
      int index = binarySearch(arr, X);
      int leftPointer = index;
      int rightPointer = index + 1;
      for (int i = 0; i < K; i++) {
        if (leftPointer >= 0 && rightPointer < (int)arr.size()) {
          int diff1 = abs(X - arr[leftPointer]);
          int diff2 = abs(X - arr[rightPointer]);
          if (diff1 < diff2) {
            result.push_front(arr[leftPointer--]);
          } else {
            result.push_back(arr[rightPointer++]);
          }
        } else if (leftPointer >= 0) {
          result.push_front(arr[leftPointer--]);
        } else if (rightPointer < (int)arr.size()) {
          result.push_back(arr[rightPointer++]);
        }
      }

      vector<int> reslutVec;
      std::move(std::begin(result), std::end(result), std::back_inserter(reslutVec));
      return reslutVec;
    }

  private:
    static int binarySearch(const vector<int> &arr, int target) {
      int low = 0;
      int high = (int)arr.size() - 1;
      while (low <= high) {
        int mid = low + (high - low) / 2;
        if (arr[mid] == target) {
          return mid;
        }

        if (arr[mid] > target) {
          high = mid - 1;
        } else {
          low = mid + 1;
        }
      }
      if (low > 0) {
        return low - 1;
      }
      return low;
    }
};