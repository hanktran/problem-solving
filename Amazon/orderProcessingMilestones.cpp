using namespace std;

#include <iostream>
#include <vector>

int search(vector<int> milestones, int n) {
  int first = 0;
  int last = milestones.size();
  while (first < last) {
    int mid = (first + last) / 2;
    if (milestones[mid] >= n) {
      last = mid;
    } else {
      first = mid + 1;
    }
  }
  return first;
}

vector<int> milestoneDays(vector<int> milestones, int target) {
  int firstDay = search(milestones, target);
  if (target == milestones[firstDay]) {
    int lastDay = search(milestones, target + 1) - 1;
    return {firstDay, lastDay};
  }
  return {-1, -1};
}

int main() {
  vector<int> milestones = {0, 1, 1, 2, 2, 2, 3, 4, 4, 4, 5, 5, 6, 7};
  int target = 4;
  auto res = milestoneDays(milestones, target);
  cout << "[" << res[0] << ", " << res[1] << "]" << endl;
  return 0;
}