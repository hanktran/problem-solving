using namespace std;

#include <iostream>
#include <vector>
#include <string>
#include <unordered_map>

string generateKey(string &message) {
  string key = "";

  for (int i = 1; i < message.length(); i++) {
    int diff = message[i] - message[i - 1];
    key += diff < 0 ? diff + 26 : diff;
    key += ",";
  }

  return key;
}

vector<vector<string>> combineMessages(vector<string> &messages) {
  unordered_map<string, vector<string>> messageGroup;

  for (auto message : messages) {
    string key = generateKey(message);
    vector<string> list;
    if (messageGroup.find(key) != messageGroup.end()) {
      list = messageGroup[key];
    }
    list.push_back(message);
    messageGroup[key] = list;
  }

  vector<vector<string>> groups;
  for (auto &group : messageGroup) {
    groups.push_back(group.second);
  }

  return groups;
}

int main() {
  vector<string> messages = {"lmn", "mno", "azb", "bac", "yza", "bdfg"};
  vector<vector<string>> groups = combineMessages(messages);

  cout << "The Grouped Messages are:\n\n";
  for (auto group : groups) {
    cout << "==========\n";
    for (auto str : group) {
      cout << str << endl;
    }
    cout << endl;
  }
  return 0;
}