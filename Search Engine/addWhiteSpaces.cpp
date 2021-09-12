using namespace std;

#include <iostream>
#include <vector>
#include <string>
#include <set>

bool breakQuery(string query, vector<string> &dict) {
  set<string> dictSet(dict.begin(), dict.end());
  vector<bool> dp(query.length() + 1, false);
  dp[0] = true;
  for (int i = 1; i <= query.length(); i++) {
    for (int j = 0; j < i; j++) {
      if (dp[j] && (dictSet.find(query.substr(j, i - j)) != dictSet.end())) {
        dp[i] = true;
        break;
      }
    }
  }
  return dp[query.length()];
}

int main() {
  string query = "vegancookbook";
  vector<string> dict = {"i", "cream", "cook", "scream", "ice", "cat", "book", "icecream", "vegan"};
  cout << boolalpha << breakQuery(query, dict) << endl;
  return 0;
}