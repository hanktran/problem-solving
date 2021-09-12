using namespace std;

#include <iostream>
#include <vector>
#include <string>
#include <stack>
#include <sstream>

vector<string> split(const string &s, char delim) {
  stringstream ss(s);
  string item;
  vector<string> elems;
  while (getline(ss, item, delim)) {
    elems.push_back(item);
  }
  return elems;
}

vector<int> serviceTime(int n, vector<string> logs) {
  stack<int> stack;
  vector<int> funcTimes(n);
  vector<string> func;
  char delim = ':';
  func = split(logs[0], delim);
  stack.push(stoi(func[0]));
  int time = stoi(func[2]);
  for (int i = 0; i < logs.size(); i++) {
    func.clear();
    func = split(logs[i], delim);
    if (func[1].find("start") != string::npos) {
      if (!stack.empty()) {
        funcTimes[stack.top()] += stoi(func[2]) - time;
      }
      stack.push(stoi(func[0]));
      time = stoi(func[2]);
    } else {
      funcTimes[stack.top()] += stoi(func[2]) - time + 1;
      stack.pop();
      time = stoi(func[2]) + 1;
    }
  }

  return funcTimes;
}

int main() {
  vector<string> logs = {"0:start:0","0:start:2","0:end:5","1:start:6","1:end:6","0:end:7"};
  auto result = serviceTime(2, logs);
  cout << "[";
  int j = 0;
  for (auto i : result) {
    cout << i;
    if (j != result.size() - 1) {
      cout << ", ";
    }
    j++;
  }
  cout << "]" << endl;
  return 0;
}