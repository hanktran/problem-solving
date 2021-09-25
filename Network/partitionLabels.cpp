using namespace std;

#include <iostream>
#include <string>
#include <vector>

int partitionLabels(string files) {
  vector<int> last(26);
  for (int i = 0; i < files.length(); i++) {
    last[files[i] - 'a'] = i;
  }

  int start = 0, end = 0, count = 0;
  for (int i = 0; i < files.length(); i++) {
    end = max(end, last[files[i] - 'a']);

    if (i == end) {
      count++;
      start = i + 1;
    }
  }

  return count;
}

int main() {
  string files = "abacdc";
  cout << "The files \"" + files + "\" will be divided into " + to_string(partitionLabels(files)) + " worker nodes!" << endl;
  return 0;
}