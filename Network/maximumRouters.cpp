using namespace std;

#include <iostream>
#include <vector>

int dfs(vector<vector<int>> &grid, int i, int j, int prevVal, vector<vector<int>> &cache) {
  if (i < 0 || j < 0 || i > grid.size() - 1 || j > grid[0].size() - 1) {
    return 0;
  } else if (prevVal > grid[i][j]) {
    return 0;
  } else if (cache[i][j] != 0) {
    return cache[i][j];
  }

  int pathUp = dfs(grid, i - 1, j, grid[i][j], cache);
  int pathDown = dfs(grid, i + 1, j, grid[i][j], cache);
  int pathLeft = dfs(grid, i, j - 1, grid[i][j], cache);
  int pathRight = dfs(grid, i, j + 1, grid[i][j], cache);

  int max1 = max(pathUp, pathDown);
  int max2 = max(pathLeft, pathRight);

  cache[i][j] = 1 + max(max1, max2);

  return cache[i][j];
}

int maximumRouters(vector<vector<int>> &grid) {
  if (grid.size() == 0) {
    return 0;
  }

  int res = 0;
  vector<vector<int>> cache(grid.size(), vector<int>(grid[0].size()));

  for (int i = 0; i < grid.size(); i++) {
    for (int j = 0; j < grid[i].size(); j++) {
      if (cache[i][j] == 0) {
        int prevVal = grid[i][j];
        dfs(grid, i, j, prevVal, cache);
        res = max(cache[i][j], res);
      }
    }
  }

  return res;
}

int main() {
  vector<vector<int>> grid = {
    {2,9,6},
    {8,4,7},
    {5,3,1}
  };
  cout << "Maximum Routers are " + to_string(maximumRouters(grid)) << endl;
}