#include <iostream>
#include <string>
#include <unordered_map>

struct CompareSecond
{
  bool operator()(const pair<char, int> &left, const pair<char, int> &right) const
  {
    return left.second < right.second;
  }
};

string detectVirus(string s, int k) {
  if (s.length() * k == 0) {
    return "";
  }

  int left = 0;
  int right = 0;
  int start = 0;
  int end = 0;

  unordered_map<char, int> characterMap;
  while (right < s.length()) {
    characterMap[s[right]] = right;
    right++;

    if (characterMap.size() == k + 1) {
      pair<char, int> min = *min_element(characterMap.begin(), characterMap.end(), CompareSecond());
      int min_idx = min.second;
      characerMap.erase(s[min_idx]);
      left = min_idx + 1;
    }

    if ((end - start) < (right - left)) {
      start = left;
      end = right;
    }

    return s.substr(start, end - start);
  }
}

int main() {
  string infectedDNA = "ababffzzeee";
  int k = 3;

  cout << detectVirus(infectedDNA, k);
  return 0;
}