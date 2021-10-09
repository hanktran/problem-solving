#include <iostream>
#include <vector>

using namespace std;

vector<int> determineLocation(vector<vector<int>> &region, int lossValue) {
  int row = region.size() - 1;
  int col = 0;

  while (row >= 0 && col < region[0].size()) {
    if (region[row][col] > lossValue) {
      row--;
    } else if (region[row][col] < lossValue) {
      col++;
    } else {
      return {row, col};
    }
  }

  return {-1, -1};
}

int main() {
  vector<vector<int>> region = {{1,4,7,11,15},{2,5,8,12,19},{3,6,9,16,22},{10,13,14,17,24},{18,21,23,26,30}};
  int lossValue = 5;
  auto res = determineLocation(region, lossValue);
  cout << "The coordinates of the loss value region are: " << "[" << res[0] << ", " << res[1] << "]" << endl;
  return 0;
}