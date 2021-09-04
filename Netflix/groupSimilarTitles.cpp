using namespace std;

#include <iostream>
#include <string>
#include <unordered_map>
#include <vector>
#include <algorithm>

void groupTitles(vector<string> &strs, vector<vector<string>> &output) {
  if (strs.size() == 0) {
    return ;
  }

  unordered_map<string, vector<string>> res;
  vector<int> count(26, 0);
  for (auto s : strs) {
    for (char c : s) {
      int index = c - 'a';
      count[index]++;
    }

    string key = "";
    for (int i = 0; i < 26; i++) {
      key += "#";
      key += to_string(count[i]);
    }

    res[key].push_back(s);
    fill(count.begin(), count.end(), 0);
  }

  for (auto itr : res) {
    output.push_back(itr.second);
  }
}

int main() {
  vector<string> titles = {"duel", "dule", "speed", "spede", "deul", "cars"};
  vector<vector<string>> output;
  groupTitles(titles, output);
  string query = "spede";

  for (auto o : output) {
    auto it = find(o.begin(), o.end(), query);
    if (it != o.end()) {
      for (auto s : o) {
        cout << s << endl;
      }
    }
  }
}