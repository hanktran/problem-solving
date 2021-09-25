using namespace std;

#include <iostream>
#include <vector>
#include <unordered_map>
#include <queue>

int totalTime(int mainServerId, vector<int> &parents, vector<int> &delays) {
  int n = parents.size();
  if (n <= 1) {
    return 0;
  }

  int res = 0;
  unordered_map<int, vector<int>> children;

  vector<int> numbers;
  for (int i = 0; i < parents.size(); i++) {
    numbers.push_back(parents[i]);
  }

  for (int index = 0; index < numbers.size(); index++) {
    int val = numbers[index];
    vector<int> tempList;
    if (children.find(val) != children.end()) {
      tempList = children[val];
    }
    tempList.push_back(index);
    children[val] = tempList;
  }

  queue<pair<int, int>> queue;
  queue.push(pair<int, int>(mainServerId, delays[mainServerId]));

  while (!queue.empty()) {
    auto node = queue.front();
    queue.pop();
    int curId = node.first;
    int curTime = node.second;
    res = max(res, curTime);
    vector<int> temp;
    if (children.find(curId) != children.end()) {
      temp = children[curId];
    }

    for (int child : temp) {
      queue.push(pair<int, int>(child, curTime + delays[child]));
    }
  }
  return res;
}

int main() {
  int mainServerId = 0;
  vector<int> parents = {-1, 0, 0, 1, 1, 2, 2, 3, 3, 4, 4, 5, 5, 6, 6};
  vector<int> delays = {1, 1, 1, 1, 1, 1, 1, 0, 0, 0, 0, 0, 0, 0, 0};
  cout << to_string(totalTime(mainServerId, parents, delays));
  return 0;
}