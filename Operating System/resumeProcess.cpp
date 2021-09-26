using namespace std;

#include <iostream>
#include <vector>

int getMissingID(const vector<int> &arr, int left, int right, int newN) {
  if ((left + 1) == right) {
    return arr[left] + newN;
  }

  int middle = left + (right - left) / 2;
  int missingNums = (arr[middle] - arr[left]) - (middle - left);
  if (newN > missingNums) {
    return getMissingID(arr, middle, right, newN - missingNums);
  } else {
    return getMissingID(arr, left, middle, newN);
  }
}

int resumeProcess(vector<int> &arr, int n) {
  int pid = getMissingID(arr, 0, arr.size(), n);
  return pid;
}

int main() {
  vector<int> processes = {5, 7, 9, 10, 13};
  cout << resumeProcess(processes, 3);
  return 0;
}