#include <iostream>
#include <vector>
#include <string>
#include <unordered_map>
#include <queue>

using namespace std;

int minimumMoves(string beginWord, string endWord, vector<string> wordList) {
  int L = beginWord.length();
  unordered_map<string, vector<string>> allComboDict;

  for (auto word : wordList) {
    for (int i = 0; i < L; i++) {
      string newWord = word.substr(0, i) + "*" + word.substr(i + 1, (L - i - 1));
      vector<string> transformations;
      if (allComboDict.find(newWord) != allComboDict.end()) {
        transformations = allComboDict[newWord];
      }
      transformations.push_back(word);
      allComboDict[newWord] = transformations;
    }
  }

  queue<pair<string, int>> Q;
  Q.push(pair<string, int>(beginWord, 0));

  unordered_map<string, bool> visited;
  visited[beginWord] = true;

  while (!Q.empty()) {
    pair<string, int> node = Q.front();
    Q.pop();
    string word = node.first;
    int level = node.second;
    for (int i = 0; i < L; i++) {
      string newWord = word.substr(0, i) + "*" + word.substr(i + 1, (L - i - 1));
      vector<string> temp;
      if (allComboDict.find(newWord) != allComboDict.end()) {
        temp = allComboDict[newWord];
      }
      for (string adjacentWord : temp) {
        if (adjacentWord == endWord) {
          return level += 1;
        }

        if (visited.find(adjacentWord) == visited.end()) {
          visited[adjacentWord] = true;
          Q.push(pair<string, int>(adjacentWord, level + 1));
        }
      }
    }
  }
  return 0;
}

int main(){
  string initialWord = "hit";
  string finalWord = "cog";
  vector<string> wordGroup = {"hot","dot","dog","lot","log","cog"};
  cout << "The shortest sequece is of length: " << minimumMoves(initialWord, finalWord, wordGroup) << endl;
  return 0;
}