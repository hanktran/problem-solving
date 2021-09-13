using namespace std;

#include <iostream>
#include <vector>
#include <algorithm>

bool sortCol(const vector<int> &v1, const vector<int> &v2) {
  return v1[0] < v2[0];
}

void insertMeeting(vector<vector<int>> &meetingTimes, vector<int> newMeeting, vector<vector<int>> &output) {
  sort(meetingTimes.begin(), meetingTimes.end(), sortCol);
  int i = 0;
  int n = meetingTimes.size();
  int newStart = newMeeting[0];
  int newEnd = newMeeting[1];

  while (i < n && newStart > meetingTimes[i][0]) {
    output.push_back(meetingTimes[i]);
    i++;
  }

  int size = output.size();
  if (size == 0 || output[size - 1][1] < newStart) {
    output.push_back(newMeeting);
  } else {
    output[size - 1][1] = max(output[size - 1][1], newEnd);
  }

  size = output.size();
  while (i < n) {
    if (output[size - 1][1] < meetingTimes[i][0]) {
      output.push_back(meetingTimes[i]);
    } else {
      output[size - 1][1] = max(output[size - 1][1], meetingTimes[i][1]);
    }
    i++;
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
    vector<vector<int>> meetingTimes = {{1, 3}, {4, 6}, {9, 10}, {10, 12}, {13, 15}, {16, 18}};
    vector<int> newMeeting = {7, 9};
    
    vector<vector<int>> output;

    insertMeeting(meetingTimes, newMeeting, output);
    print(output);
    return 0;
}