using namespace std;

#include <iostream>
#include <vector>
#include <string>

void removeComments(vector<string> source, vector<string> &output) {
  string buffer = "";
  bool block = false;
  for (auto line : source) {
    int i = 0;
    while (i < line.length()) {
      char c = line[i];

      if (c == '/' && (i + 1) < line.length() && line[i + 1] == '/' && !block) {
        i = line.length();
      } else if (c == '/' && (i + 1) < line.length() && line[i + 1] == '*' && !block) {
        block = true;
        i++;
      } else if (c == '*' && (i + 1) < line.length() && line[i + 1] == '/' && block) {
        block = false;
        i++;
      } else if (!block) {
        buffer += c;
      }
      i++;
    }

    if (buffer != "" && !block) {
      output.push_back(buffer);
      buffer = "";
    }
  }
}

void print(vector<string> output) {
  cout << "[";
  for (int i = 0; i < output.size(); i++) {
    cout << output[i];
    if (i < output.size() - 1) {
      cout << ", " << endl;
    }
  }
  cout << "]" << endl;
}

int main() {
  vector<string> source = {
    "/* Example code for feature */", 
    "int main() {", 
    "  /*", 
    "  This is a", 
    "  block comment", 
    "  */", 
    "  int value = 10;  // This is an inline comment", 
    "  int sum = value + /* this is // also a block */ value;", 
    "  return 0;", 
    "}"
  };
  vector<string> output;
  removeComments(source, output);
  print(output);
  return 0;
}