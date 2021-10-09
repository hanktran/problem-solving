#include <iostream>
#include <vector>
#include <string>
#include <queue>
#include <unordered_set>

using namespace std;

vector<string> neighbors(string &str) {
  vector<string> res;
  for (int i = 0; i < str.length(); i++) {
    string backward = str.substr(0, i) + to_string(str[i] == '0' ? 9 : str[i] - '0' - 1) + str.substr(i + 1);
    res.push_back(backward);

    string forward = str.substr(0, i) + to_string(str[i] == '9' ? 0 : str[i] - '0' + 1) + str.substr(i + 1);
    res.push_back(forward);
  }

  return res;
}

int powerUp(vector<string> &deadStates, string &target) {
  queue<string> q;
  unordered_set<string> visited(deadStates.begin(), deadStates.end());
  int depth = -1;
  q.push("0000");
  while (!q.empty()) {
    depth++;
    int size = q.size();
    for (int i = 0; i < size; i++) {
      string node = q.front();
      q.pop();
      if (node == target) {
        return depth;
      }

      if (visited.find(node) != visited.end()) {
        continue;
      }

      visited.insert(node);
      auto neighbor = neighbors(node);
      for (auto n : neighbor) {
        q.push(n);
      }
    }
  }

  return -1;
}

int main() {
  vector<string> deadStates = {"0201","0101","0102","1212","2002"};
  string target = "0202";
  cout << "The system will power up in " + to_string(powerUp(deadStates, target)) + " dial turns\n";
}