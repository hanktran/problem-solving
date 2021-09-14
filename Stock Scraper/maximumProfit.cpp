using namespace std;

#include <iostream>
#include <vector>

int maxProfit(vector<int> &A) {
  if (A.size() < 1) {
    return 0;
  }

  int currentMax = A[0];
  int globalMax = A[0];
  for (int i = 1; i < A.size(); i++) {
    if (currentMax < 0) {
      currentMax = A[i];
    } else {
      currentMax = currentMax + A[i];
    }

    if (globalMax < currentMax) {
      globalMax = currentMax;
    }
  }

  return globalMax;
}

int main() {
  vector<int> stocks = {-4, 2, -5, 1, 2, 3, 6, -5, 1};
  cout << "Maximum Profit: " + to_string(maxProfit(stocks)) + "%" ;
}