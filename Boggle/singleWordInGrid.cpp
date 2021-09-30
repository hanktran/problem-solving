#include <iostream>
#include <string>
#include <vector>

using namespace std;

bool dfs(int row, int col, string suffix, vector<vector<char>> &grid) {
  if (suffix.length() == 0) {
    return true;
  }

  if (row < 0 || row >= grid.size() || col < 0 || col >= grid[0].size() || grid[row][col] != suffix[0]) {
    return false;
  }

  bool res = false;
  grid[row][col] = '#';
  vector<vector<int>> offsets {{0, 1}, {1, 0}, {0, -1}, {-1, 0}};
  for (auto offset : offsets) {
    int rowOffset = offset[0];
    int colOffset = offset[1];
    res = dfs(row + rowOffset, col + colOffset, suffix.substr(1), grid);
    if (res) {
      break;
    }
  }
  grid[row][col] = suffix[0];
  return res;
}

bool exists(vector<vector<char>> &grid, string word) {
  for (int row = 0; row < grid.size(); row++) {
    for (int col = 0; col < grid[0].size(); col++) {
      if (dfs(row, col, word, grid)) {
        return true;
      }
    }
  }
  return false;
}

int main() {
  vector<vector<char>> grid {
    {'C', 'S', 'L', 'I', 'M'}, 
    {'O', 'I', 'L', 'M', 'O'}, 
    {'O', 'L', 'I', 'E', 'O'}, 
    {'R', 'T', 'A', 'S', 'N'}, 
    {'S', 'I', 'T', 'A', 'C'}
  };
  string word = "COIL";
  cout << boolalpha << exists(grid, word)<<endl;

  word = "COCOON";
  cout<< boolalpha << exists(grid, word);
  return 0;
}