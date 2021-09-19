using namespace std;

#include <iostream>
#include <vector>
#include <unordered_map>

bool checkDelivery(vector<int> &packages, int k) {
  int currSum = 0;
  unordered_map<int, int> map;
  map[0] = -1;
  for (int i = 0; i < packages.size(); i++) {
    currSum += packages[i];
    if (k != 0) {
      currSum = currSum % k;
    }

    if (map.find(currSum) != map.end()) {
      if (i - map[currSum] > 1) {
        return true;
      }
    } else {
      map[currSum] = i;
    }
  }
  return false;
}

int main(){
  vector<int> packages = {58, 42, 46, 49, 331, 26, 6, 37, 3};
  int k = 10;
  cout << boolalpha << checkDelivery(packages, k) << endl;
}