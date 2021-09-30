using namespace std;

#include <iostream>
#include <string>
#include <stack>

string loopUnrolling(string codeBlock) {
  stack<int> countStack;
  stack<string> statementStack;
  string currentStatement = "";

  int n = 0;
  for (int i = 0; i < codeBlock.length(); i++) {
    char ch = codeBlock[i];
    if (isdigit(ch)) {
      n = n * 10 + ch - '0';
    } else if (ch == '[') {
      countStack.push(n);
      statementStack.push(currentStatement);
      currentStatement = "";
      n = 0;
    } else if (ch == ']') {
      string unrollStatement = statementStack.top();
      statementStack.pop();
      int currentN = countStack.top();
      for (; currentN > 0; currentN--) {
        unrollStatement += currentStatement;
      }
      currentStatement = unrollStatement;
    } else {
      currentStatement += ch;
    }
  }
  return currentStatement;
}

int main() {
  string codeBlock = "2[sum = sum + i; 2[i++; ]]";
  cout << loopUnrolling(codeBlock) << endl;
  return 0;
}