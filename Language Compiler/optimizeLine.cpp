using namespace std;

#include <iostream>
#include <vector>
#include <algorithm>

bool sortCol(const vector<int> &vec1, const vector<int> &vec2) {
  return vec1[0] > vec2[0];
}

string optimizeLine(string &line, vector<int> &indices, vector<string> &sources, vector<string> &targets) {
  vector<vector<int>> sorted;
  for (int i = 0; i < indices.size(); i++) {
    sorted.push_back({indices[i], i});
  }

  sort(sorted.begin(), sorted.end(), sortCol);
  for (auto item : sorted) {
    int i = item[0], j = item[1];
    string s = sources[j], t = targets[j];
    if (line.substr(i, s.length()) == s) {
      line = line.substr(0, i) + t + line.substr(i + s.length());
    }
  }
  return line;
}

int main(){
  string line = "foo(input, i);";
  vector<int> indices = {0, 11};
  vector<string> sources = {"foo", "i"};
  vector<string>targets = {"foobar", "j+1"};
  cout << optimizeLine(line, indices, sources, targets) << endl;
  return 0;
}
