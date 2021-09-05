using namespace std;

#include <iostream>
#include <vector>
#include <stack>

bool verifySession(vector<int> &pushOp, vector<int> popOp) {
  int M = pushOp.size();
  int N = popOp.size();
  if (M != N) {
    return false;
  }

  stack<int> stack;

  int i = 0;
  for (int pid : pushOp) {
    stack.push(pid);
    while (!stack.empty() && stack.top() == popOp[i]) {
      stack.pop();
      i++;
    }
  }

  return stack.empty();
}

int main() {
  vector<int> pushOp = {1, 2, 3, 4, 5};
  vector<int> popOp = {4, 5, 3, 2, 1};

  if (verifySession(pushOp, popOp)) {
    cout << "Session Successfull!";
  } else {
    cout << "Session Faulty!";
  }
}