using namespace std;

#include <iostream>
#include <vector>
#include <string>
#include <unordered_map>

int possibleMatches(string s, vector<string> words) {
  unordered_map<char, vector<string>> waitingList;
  for (auto w : words) {
    waitingList[w[0]].push_back(w);
  }

  for (char c : s) {
    auto advance = waitingList[c];
    waitingList[c] = {};
    for (auto it : advance) {
      auto itr = next(it.begin(), 1);
      waitingList[*itr].push_back(it.substr(1));
    }
  }

  return waitingList[0].size();
}

int main() {
  string plagiarised = "abcde";
  vector<string> students = {"a","bb","acd","ace"}; 
  cout << "The content was copied from " << to_string(possibleMatches(plagiarised, students)) << " students";
  return 0;
}