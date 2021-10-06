#include <iostream>
#include <vector>
#include <unordered_map>
#include <algorithm>
#include <string>
#include <set>

using namespace std;

void dfs(string w, string endWord, unordered_map<string, set<string>> &graph, vector<string> &path, vector<vector<string>> &ans) {
  if (w == endWord) {
    ans.push_back(path);
  } else {
    for (auto itr = graph[w].begin(); itr != graph[w].end(); itr++) {
      auto nw = *itr;
      path.push_back(nw);
      dfs(nw, endWord, graph, path, ans);
      path.pop_back();
    }
  }
}

void possibleResults(string beginWord, string endWord, vector<string> wordList, vector<vector<string>> &res) {
  if (beginWord == endWord) {
    res.push_back({beginWord});
    return;
  }

  unordered_map<string, set<string>> graph;
  string helper = "qwertyuiopasdfghjklzxcvbnm";
  set<string> dictSet(wordList.begin(), wordList.end());

  set<string> layer;
  layer.insert(beginWord);
  dictSet.erase(beginWord);

  bool stop = false;
  while (layer.size() > 0 && !stop) {
    set<string> newLayer;
    for (auto itr = layer.begin(); itr != layer.end(); itr++) {
      auto w = *itr;
      for (int i = 0; i < w.length(); i++) {
        for (auto c : helper) {
          auto nw = w.substr(0, i) + c + w.substr(i + 1);
          if (dictSet.find(nw) != dictSet.end()) {
            newLayer.insert(nw);
            graph[w].insert(nw);
          }

          if (nw == endWord) {
            stop = true;
          }
        }
      }
    }
    set<string> temp;
    set_difference(dictSet.begin(), dictSet.end(), newLayer.begin(), newLayer.end(), inserter(temp, temp.end()));
    dictSet = temp;
    layer = newLayer;
  }

  vector<string> path = {beginWord};
  dfs(beginWord, endWord, graph, path, res);
}

void print(vector<vector<string>> res) {
  cout << "[";
  for (int i = 0; i < res.size(); i++) {
    cout << "[";
    for (int j = 0; j < res[i].size(); j++) {
      cout << res[i][j];

      if (j < res[i].size() - 1) {
        cout << ", ";
      }
    }
    cout << "]";
    if (i < res.size() - 1) {
      cout << ", ";
    }
  }
}

int main() {
  string initialWord = "hit";
  string finalWord = "cog";
  vector<string> wordGroup = {"hot", "dot", "dog", "lot", "log", "cog", "lit"};
  vector<vector<string>> res;
  possibleResults(initialWord, finalWord, wordGroup, res);
  cout << "All minimum sequences are:\n";
  print(res);
  return 0;
}