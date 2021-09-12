using namespace std;

#include <iostream>
#include <vector>

void DFS(vector<vector<bool>> &friends, int n, vector<bool> &visited, int v) {
  for (int i = 0; i < n; i++) {
    if (friends[v][i] == true && !visited[i] && i != v) {
      visited[i] = true;
      DFS(friends, n, visited, i);
    }
  }
}

int friendCircles(vector<vector<bool>> &friends, int n) {
  if (n == 0) {
    return 0;
  }

  int numberCircles = 0;
  vector<bool> visited(n, false);
  for (int i = 0; i < n; i++) {
    if (!visited[i]) {
      visited[i] = true;
      DFS(friends, n, visited, i);
      numberCircles = numberCircles + 1;
    }
  }

  return numberCircles;
}

int main() {
  int n = 4;
  vector<vector<bool>> friends = {
    {true, true, false, false},
    {true, true, true, false},
    {false, true, true, false},
    {false, false, false, true}
  };

  cout << "Number of friends circles: " + to_string(friendCircles(friends, n));
}