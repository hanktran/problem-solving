using namespace std;

#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>

bool sortCol(const vector<int> &v1, const vector<int> &v2) {
  return v1[0] < v2[0];
}

int minMeetingRooms(vector<vector<int>> &meetingTimes) {
  if (meetingTimes.size() == 0) {
    return 0;
  }

  sort(meetingTimes.begin(), meetingTimes.end(), sortCol);
  priority_queue<int, vector<int>, greater<int>> minHeap;
  minHeap.push(meetingTimes[0][1]);

  for (int i = 1; i < meetingTimes.size(); i++) {
    int currStart = meetingTimes[i][0];
    int currEnd = meetingTimes[i][1];
    int earliestEnding = minHeap.top();

    if (earliestEnding <= currStart) {
      minHeap.pop();
    }
    minHeap.push(currEnd);
  }

  return minHeap.size();
}

int main() {
  vector<vector<int>> meetingTimes = {{2, 8}, {3, 4}, {3, 9}, {5, 11}, {8, 20}, {11, 15}};
  cout << minMeetingRooms(meetingTimes);
  return 0;
}