using namespace std;

#include <iostream>
#include <string>

string match(string cheater, string student) {
  string window = "";
  int j = 0, min = cheater.length() + 1;
  for (int i = 0; i < cheater.length(); i++) {
    if (cheater[i] == student[j]) {
      j++;
      if (j == student.length()) {
        int end = i + 1;
        j--;
        while (j >= 0) {
          if (cheater[i] == student[j]) {
            j--;
          }
          i--;
        }
        j++;
        i++;
        if (end - i < min) {
          min = end - i;
          window = cheater.substr(i, min);
        }
      }
    }
  }
  return window;
}

int main() {
  string cheater = "quiqutit";
  string student = "quit";
  cout << "Copied Content: " + match(cheater, student);
  return 0;
}