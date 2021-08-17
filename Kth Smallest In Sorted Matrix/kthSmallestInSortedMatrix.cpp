using namespace std;

#include <iostream>
#include <queue>
#include <vector>

class KthSmallestInSortedMatrix {
  public:
    struct numCompare {
      bool operator()(const pair<int, pair<int, int>> &x, const pair<int, pair<int, int>> &y) {
        return x.first > y.first;
      }
    };

    static int findKthSmallest(vector<vector<int>> &matrix, int k) {
      int n = matrix.size();
      priority_queue<pair<int, pair<int, int>>, vector<pair<int, pair<int, int>>>, numCompare> minHeap;
      for (int i = 0; i < n && i < k; i++) {
        minHeap.push(make_pair(matrix[i][0], make_pair(i, 0)));
      }

      int numberCount = 0, result = 0;
      while (!minHeap.empty()) {
        auto heapTop = minHeap.top();
        minHeap.pop();
        result = heapTop.first;
        if (++numberCount == k) {
          break;
        }

        heapTop.second.second++;
        if (n > heapTop.second.second) {
          heapTop.first = matrix[heapTop.second.first][heapTop.second.second];
          minHeap.push(heapTop);
        }
      }

      return result;
    }
};

class KthSmallestInSortedMatrix {
  public:
    static int findKthSmallest(vector<vector<int>> &matrix, int k) {
      int n = matrix.size();
      int start = matrix[0][0], end = matrix[n - 1][n - 1];
      while (start < end) {
        int mid = start + (end - start) / 2;
        pair<int, int> smallLargePair = {matrix[0][0], matrix[n -1][n - 1]};
        int count = countLessEqual(matrix, mid, smallLargePair);
        if (count == k) {
          return smallLargePair.first;
        }

        if (count < k) {
          start = smallLargePair.second;
        } else {
          end = smallLargePair.first;
        }
      }
      
      return start;
    }

  private:
    static int countLessEqual(vector<vector<int>> &matrix, int mid, pair<int, int> &smallLargePair) {
      int count = 0;
      int n = matrix.size(), row = n - 1, col = 0;
      while (row >= 0 && col < n) {
        if (matrix[row][col] > mid) {
          smallLargePair.second = min(smallLargePair.second, matrix[row][col]);
          row--;
        } else {
          smallLargePair.first = max(smallLargePair.first, matrix[row][col]);
          count += row + 1;
          col++;
        }
      }

      return count;
    }
};