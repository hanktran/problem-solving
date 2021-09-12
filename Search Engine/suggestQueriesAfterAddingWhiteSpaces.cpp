using namespace std;

#include <iostream>
#include <unordered_map>
#include <set>
#include <string>
#include <vector>

void helper(string s, set<string> dictSet, unordered_map<string, vector<string>> &map, vector<string> &res) {
  if (map.find(s) != map.end()) {
    res = map[s];
    return;
  }

  if (s.length() == 0) {
    res.push_back("");
    return;
  }

  for (auto word : dictSet) {
    if (s.rfind(word, 0) == 0) {
      vector<string> sublist;
      helper(s.substr(word.length()), dictSet, map, sublist);
      for (auto sub : sublist) {
        res.push_back(word + (sub.empty() ? "" : " ") + sub);
      }
    }
  }

  map[s] = res;
}

void breakQuery(string query, vector<string> &dict, vector<string> &res) {
  set<string> dictSet(dict.begin(), dict.end());
  unordered_map<string, vector<string>> map;
  helper(query, dictSet, map, res);
}

void print(vector<string> &res) {
  cout << "[";
  int i = 0;
  for (auto s : res) {
    cout << s;
    if (i < res.size() - 1) {
      cout << ", ";
    }
    i++;
  }
  cout << "]" << endl;
}

int main() {
  string query = "vegancookbook";
  vector<string> dict = {"an", "book", "car", "cat", "cook", "cookbook",
  "crash", "cream", "high", "highway", "i", "ice", "icecream", "low", "scream", "veg", "vegan", "way"};
  vector<string> res;
  breakQuery(query, dict, res);
  print(res);

  query = "highwaycarcrash";
  res.clear();
  breakQuery(query, dict, res);
  print(res);
}