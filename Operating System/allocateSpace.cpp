using namespace std;

#include <iostream>
#include <vector>
#include <unordered_map>

int allocateSpace(vector<int> &processes, int newP) {
  int count = 0, sum = 0;
  unordered_map<int, int> res;
  res[0] = 1;
  for (int i = 0; i < processes.size(); i++) {
    sum += processes[i];
    if (res.find(sum - newP) != res.end()) {
      count += res[sum-newP];
    }
    res[sum] = res.find(sum) == res.end() ? 1 : res[sum] + 1;
  }

  return count;
}

int main(){
  vector<int> processes = {1, 2, 3, 4, 5, 6, 7, 1, 23, 21, 3, 1, 2, 1, 1, 1, 1, 1, 12, 2, 3, 2, 3, 2, 2};
  cout << allocateSpace(processes, 1);
  return 0;
}