using namespace std;

#include <iostream>
#include <vector>
#include <queue>

int updateConfiguration(vector<vector<int>> &grid) {
  queue<pair<int, int>> queue;
  int rows = grid.size(), cols = grid[0].size();
  for (int r = 0; r < rows; r++) {
    for (int c = 0; c < cols; c++) {
      if (grid[r][c] == 2) {
        queue.push(pair<int, int>(r, c));
      }
    }
  }
  queue.push(pair<int, int>(-1, -1));

  int minutesElapsed = -1;
  vector<vector<int>> directions = {{-1, 0}, {0, 1}, {1, 0}, {0, -1}};
  while (!queue.empty()) {
    auto p = queue.front();
    queue.pop();
    int row = p.first;
    int col = p.second;
    if (row == -1) {
      minutesElapsed++;

      if (!queue.empty()) {
        queue.push(pair<int, int>(-1, -1));
      }
    } else {
      for (auto d : directions) {
        int neighborRow = row + d[0];
        int neighborCol = col + d[1];
        if (neighborRow >= 0 && neighborRow < rows && neighborCol >= 0 && neighborCol < cols) {
          if (grid[neighborRow][neighborCol] == 1) {
            grid[neighborRow][neighborCol] = 2;
            queue.push(pair<int, int>(neighborRow, neighborCol));
          }
        }
      }
    }
  }

  return minutesElapsed;
}

int main() {
  vector<vector<int>> grid = {{1, 1, 0, 0, 1}, {0, 1, 0, 1, 1}, {1, 1, 2, 0, 1}, {1, 0, 1, 1, 1}, {1, 1, 0, 1, 1}};
  cout << to_string(updateConfiguration(grid)) << endl;
  return 0;
}