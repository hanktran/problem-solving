using namespace std;

#include <iostream>
#include <vector>

int pathCost(vector<int> elevationMap) {
  int water = 0;
  int n = elevationMap.size();
  vector<int> leftMax(n);
  vector<int> rightMax(n);

  leftMax[0] = elevationMap[0];
  rightMax[n - 1] = elevationMap[n - 1];

  for (int i = 1; i < n; i++) {
    leftMax[i] = max(leftMax[i - 1], elevationMap[i]);
  }

  for (int i = n - 2; i >= 0; i--) {
    rightMax[i] = max(rightMax[i + 1], elevationMap[i]);
  }

  for (int i = 0; i < n; i++) {
    water += min(leftMax[i], rightMax[i]) - elevationMap[i];
  }

  return water;
}

int main() {
  vector<int> elevationMap = {1, 2, 1, 3, 1, 2, 1, 4, 1, 0, 0, 2, 1, 4};
  cout << "Accumulated water: " << to_string(pathCost(elevationMap)); 
}