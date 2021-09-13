using namespace std;

#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>

bool sortCol(const vector<int> &v1, const vector<int> &v2) {
  return v1[0] < v2[0];
}

void mergeMeetings(vector<vector<int>> &meetingTimes, vector<vector<int>> &merged) {
  sort(meetingTimes.begin(), meetingTimes.end(), sortCol);
  for (auto meeting : meetingTimes) {
    int size = merged.size();
    if (size == 0 || merged[size - 1][1] < meeting[0]) {
      merged.push_back(meeting);
    } else {
      merged[size - 1][1] = max(merged[size - 1][1], meeting[1]);
    }
  }
}

void print(vector<vector<int>> &merged) {
  cout << "[";
  for (auto paired : merged) {
    int size = 0;
    cout << "[";
    for (auto item : paired) {
      cout << item;
      if (size < 1) {
        cout << ", ";
      }
      size++;
    }
    cout << "]";
  }
}

int main() {
  vector<vector<int>> meetingTimes = {{1, 4}, {2, 5}, {6, 8}, {7, 9}, {10, 13}};
  vector<vector<int>> merged;
  mergeMeetings(meetingTimes, merged);
  print(merged);

  merged.clear();
  vector<vector<int>> meetingTimes1 = {{4, 7}, {1, 3}, {8, 10}, {2, 3}, {6, 8}};
  mergeMeetings(meetingTimes1, merged);
  print(merged);
  
  return 0;
}