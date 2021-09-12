using namespace std;

#include <iostream>
#include <vector>
#include <numeric>

int dividePosts(vector<int> &days, int k) {
  int left = 1;
  int right = accumulate(days.begin(), days.end(), 0) / k;

  while (left < right) {
    int mid = (left + right + 1) / 2;
    int target = 0;
    int divisions = 0;
    for (auto posts : days) {
      target += posts;
      if (target >= mid) {
        divisions++;
        target = 0;
      }
    }

    if (divisions >= k) {
      left = mid;
    } else {
      right = mid - 1;
    }
  }

  return left;
}

int main() {
    vector<int> days = {1000,2000,3000,4000,5000};
    int nodes = 3;
    cout << "The master node was assigned " <<  to_string(dividePosts(days, nodes)) << " posts\n";
    return 0;
}