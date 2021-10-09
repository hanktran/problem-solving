#include <iostream>
#include <string>

using namespace std;

int returnPalindromeLength(string s, int left, int right) {
  while (left >= 0 && right < s.length() && s[left] == s[right]) {
    left--;
    right++;
  }

  return right - left - 1;
}

string locateProtein(string s) {
  if (s.length() < 1) {
    return "";
  }

  int start = 0, end = 0;
  for (int i = 0; i < s.length(); i++) {
    int len1 = returnPalindromeLength(s, i, i);
    int len2 = returnPalindromeLength(s, i, i + 1);
    int len = max(len1, len2);

    if (len > end - start) {
      start = i - (len - 1) / 2;
      end = i + len / 2;
    }
  }

  return s.substr(start, end + 1 - start);
}

int main() {
  string sequence = "aaccbababcbc";
  cout << locateProtein(sequence);
  return 0;
}