using namespace std;

#include <iostream>
#include <vector>

int minimumHops(vector<int> values) {
  if (values.size() < 2) {
    return 0;
  }

  int maxReach = values[0];
  int currReach = values[0];
  
  int hops = 1;
  for (int i = 1; i < values.size(); i++) {
    if (currReach < i) {
      hops++;
      currReach = maxReach;
    }
    maxReach = max(maxReach, values[i] + i);
  }

  return hops;
}

int main() {
  vector<int> switch_array = {4, 1, 1, 3, 1, 1, 1};
  cout << "Minimum hops to final router are: " << to_string(minimumHops(switch_array));
}