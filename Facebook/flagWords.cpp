using namespace std;

#include <iostream>
#include <string>

int repeatedLetters(string &s, int ind) {
  int temp = ind;
  while (temp < s.length() && s[temp] == s[ind]) {
    temp++;
  }

  return temp - ind;
}

bool flagWords(string &s, string &w) {
  if (s.empty() || w.empty()) {
    return false;
  }

  int i = 0;
  int j = 0;
  while (i < s.length() && j < w.length()) {
    if (s[i] == w[j]) {
      int len1 = repeatedLetters(s, i);
      int len2 = repeatedLetters(w, j);

      if (len1 < 3 && len1 != len2 || len1 >= 3 && len1 < len2) {
        return false;
      }

      i += len1;
      j += len2;
    } else {
      return false;
    }
  }

  return i == s.length() && j == w.length();
}

int main() {
  string s = "mooooronnn";
  string w = "moron";

  if (flagWords(s, w)) {
    cout << "Word Flagged" << endl;
    cout << "The word \"" + s + "\"" + " is a possible morph of \"" + w + "\""  << endl;
  } else {
    cout << "Word Safe" << endl;
  }
  return 0;
}