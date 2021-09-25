using namespace std;

#include <iostream>
#include <vector>

void dfs(vector<vector<int>> &matrix, int r, int c, int currId, int newId) {
  if (r < 0 || c < 0 || r >= matrix.size() || c >= matrix[0].size() || matrix[r][c] != currId) {
    return;
  }

  matrix[r][c] = newId;

  dfs(matrix, r - 1, c, currId, newId);
  dfs(matrix, r + 1, c, currId, newId);
  dfs(matrix, r, c - 1, currId, newId);
  dfs(matrix, r, c + 1, currId, newId);
}

vector<vector<int>> updateVLAN(vector<vector<int>> &matrix, int r, int c, int newId) {
  int currId = matrix[r][c];
  if (currId == newId) {
    return matrix;
  }

  dfs(matrix, r, c, currId, newId);
  return matrix;
}

void print(vector<vector<int>> &res) {
  cout << "[";
  for (int i = 0; i < res.size(); i++) {
    cout << "[";
    for (int j = 0; j < res[i].size(); j++) {
      cout << res[i][j];
      if (j < res[i].size() - 1) {
        cout << ", ";
      }
    }
    cout << "]";
    if (i < res.size() - 1) {
      cout << ", ";
    }
  }
  cout << "]" << endl;
}

int main() {
  vector<vector<int>> matrix = {
    {1,1,1,1,1},
    {1,1,1,1,0},
    {1,1,1,0,0},
    {1,1,0,1,0},
    {1,1,0,0,1}
  };
  int r = 1, c = 1, newId = 2;
  auto res = updateVLAN(matrix, r, c, newId);
  print(res);
  return 0;
}