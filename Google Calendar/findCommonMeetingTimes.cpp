using namespace std;

#include <iostream>
#include <vector>

void meetingsIntersection(vector<vector<int>> &meetingsA, vector<vector<int>> &meetingsB, vector<vector<int>> &intersection) {
  int i = 0;
  int j = 0;
  while (i < meetingsA.size() && j < meetingsB.size()) {
    int start = max(meetingsA[i][0], meetingsB[j][0]);
    int end = min(meetingsA[i][1], meetingsB[j][1]);

    if (start < end) {
      intersection.push_back({start, end});
    }

    if (meetingsA[i][1] < meetingsB[j][1]) {
      i++;
    } else {
      j++;
    }
  }
}

void print(vector<vector<int>> &output) {
  cout << "[";
  for (auto meeting : output) {
    cout << "[";
    for (int i = 0; i < 2; i++) {
      cout << meeting[i];
      if (i < 1) {
        cout << ", ";
      }
    }
    cout << "]";
  }
  cout << "]";
}

int main() {
  vector<vector<int>> meetingsA = {{1, 3}, {5, 6}, {7, 9}};
  vector<vector<int>> meetingsB = {{2, 3}, {5, 7}};
  vector<vector<int>> intersection;
  meetingsIntersection(meetingsA, meetingsB, intersection);
  print(intersection);

  return 0;
}