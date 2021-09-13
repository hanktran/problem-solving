using namespace std;

#include <iostream>
#include <vector>
#include <unordered_map>

int twoSetsOfDays(vector<int> &hoursPerDay, int k) {
  unordered_map<int, int> hmap;
  int sum = 0;
  int lsize = INT_MAX;
  int result = INT_MAX;
  hmap[0] = -1;
  for (int i = 0; i < hoursPerDay.size(); i++) {
    sum += hoursPerDay[i];
    hmap[sum] = i;
  }

  sum = 0;
  for (int i = 0; i < hoursPerDay.size(); i++) {
    sum += hoursPerDay[i];
    if (hmap.find(sum - k) != hmap.end()) {
      lsize = min(lsize, i - hmap[sum - k]);
    }

    if (hmap.find(sum + k) != hmap.end() && lsize < INT_MAX) {
      result = min(result, hmap[sum + k] - i + lsize);
    }
  }

  if (result == INT_MAX) {
    return -1;
  }

  return result;
}

int main() {
  vector<int> hoursPerDay = {1, 2, 2, 3, 2, 6, 7, 2, 1, 4, 8};
  int k = 5;
  cout << to_string(twoSetsOfDays(hoursPerDay, k)) << endl;
}