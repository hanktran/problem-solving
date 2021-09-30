using namespace std;

#include <iostream>
#include <string>
#include <stack>

int evaluateExpression(string expression) {
  int number = 0;
  int sign = 1;
  int output = 0;
  stack<int> stack;
  for (int i = 0; i < expression.length(); i++) {
    char c = expression[i];
    if (isdigit(c)) {
      number = number * 10 + (int(c) - 48);
    } else if (c == '-' || c == '+') {
      output += number * sign;
      if (c == '-') {
        sign = -1;
      } else {
        sign = 1;
      }
      number = 0;
    } else if (c == '(') {
      stack.push(output);
      stack.push(sign);
      output = 0;
      sign = 1;
    } else if (c == ')') {
      output += sign * number;
      output *= stack.top();
      stack.pop();
      output += stack.top();
      stack.pop();
      number = 0;
    }
  }

  return output + number * sign;
}

int main() {
  string expression = "{4 - (10 + 52) + 99}";
  cout << to_string(evaluateExpression(expression)) << endl;
  return 0;
}