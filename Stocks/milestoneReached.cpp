#include <iostream>
#include <vector>

using namespace std;

void milestoneReached(vector<vector<int>> &matrix, int milestone, vector<int> &failed) {
  failed = {-1, -1};

  int m = matrix.size();
  if (m == 0) {
    return;
  }
  int n = matrix[0].size();

  int left = 0, right = m * n - 1;
  int middleIdx, middleElement;
  while (left <= right) {
    middleIdx = left + (right - left) / 2;
    middleElement = matrix[middleIdx / n][middleIdx % n];
    if (milestone == middleElement) {
      failed = {middleIdx / n, middleIdx % n};
      return;
    } else {
      if (milestone < middleElement) {
        right = middleIdx - 1;
      } else {
        left = middleIdx + 1;
      }
    }
  }
}

int main() {
  vector<vector<int>> matrix = {
    {0, 2, 4, 6, 8},
    {10, 12, 14, 18, 22},
    {24, 30, 34, 60, 64}
  };
  int milestone = 24;
  vector<int> res;
  milestoneReached(matrix, milestone, res);
  cout << "Milestone reached on day " << to_string(res[1] + 1) << " of week " << to_string(res[0] + 1);
  return 0;
}