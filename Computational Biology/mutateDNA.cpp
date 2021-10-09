#include <iostream>
#include <unordered_map>
#include <string>
#include <set>

using namespace std;

bool mutateDNA(string s1, string s2) {
  if (s1 == s2) {
    return true;
  }

  unordered_map<char, char> edges;
  for (int i = 0; i < s1.length(); i++) {
    char temp = edges.find(s1[i]) != edges.end() ? edges[s1[i]] : s2[i];
    if (temp != s2[i]) {
      return false;
    }
    edges[s1[i]] = s2[i];
  }

  return set<char>(s2.begin(), s2.end()).size() < 26;
}

int main() {
  string s1 = "aabcc";
  string s2 = "ccdee";

  if (mutateDNA(s1, s2)) {
    cout << "Mutation Possible";
  } else {
    cout << "Mutation not Possible";
  }
  
  return 0;
}