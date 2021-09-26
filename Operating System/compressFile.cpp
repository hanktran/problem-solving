using namespace std;

#include <iostream>
#include <unordered_set>
#include <vector>
#include <string>
#include <unordered_map>

bool dfs(string word, unordered_set<string> &wordSet, unordered_map<string, bool> &cache) {
  if (cache.find(word) != cache.end()) {
    return cache[word];
  }

  for (int i = 1; i < word.length(); i++) {
    string prefix = word.substr(0, i);
    string suffix = word.substr(i);
    if (wordSet.find(prefix) != wordSet.end()) {
      if (wordSet.find(suffix) != wordSet.end() || dfs(suffix, wordSet, cache)) {
        cache[word] = true;
        return true;
      }
    }
  }

  cache[word] = false;
  return false;
}

vector<string> identifyConcatenations(vector<string> &words) {
  vector<string> res;
  unordered_set<string> wordSet(words.begin(), words.end());
  unordered_map<string, bool> cache;

  for (auto word : words) {
    if (dfs(word, wordSet, cache)) {
      res.push_back(word);
    }
  }

  return res;
}

void print(vector<string> &res) {
  cout << "[";
  for (int i = 0; i < res.size(); i++) {
    cout << res[i];
    if (i < res.size() - 1) {
      cout << ", ";
    }
  }
  cout << "]" << endl;
}

int main() {
  vector<string> fileWords = {"n", "cat", "cats", "dog", "catsndog"};
  auto result = identifyConcatenations(fileWords);
  print(result);
}