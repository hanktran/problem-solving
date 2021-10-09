#include <iostream>
#include <vector>
#include <stack>

using namespace std;

int maximumRowArea(vector<int> heights) {
  stack<int> stack;
  stack.push(-1);

  int maxArea = 0;
  for (int i = 0; i < heights.size(); i++) {
    while (stack.top() != -1 && heights[stack.top()] >= heights[i]) {
      int top = stack.top();
      stack.pop();
      int height = heights[top];
      int R = i;
      int L = stack.top();
      int width = (R - L) - 1;
      int area = height * width;
      maxArea = max(maxArea, area);
    }
    stack.push(i);
  }

  while (stack.top() != -1) {
    int top = stack.top();
    stack.pop();
    int height = heights[top];
    int R = heights.size();
    int L = stack.top();
    int width = (R - L) - 1;
    int area = height * width;
    maxArea = max(maxArea, area);
  }

  return maxArea;
}

int lowCoverage(vector<vector<string>> &matrix) {
  if (matrix.size() == 0) return 0;
  int maxArea = 0;
  vector<int> dp(matrix[0].size());

  for (int i = 0; i < matrix.size(); i++) {
    for (int j = 0; j < matrix[0].size(); j++) {
      if (matrix[i][j] == "1") {
        dp[j] = dp[j] + 1;
      } else {
        dp[j] = 0;
      }
    }

    maxArea = max(maxArea, maximumRowArea(dp));
  }

  return maxArea;
}

int main() {
  vector<vector<string>> mall = {
    {"1","0","0","1","1","1"},
    {"1","0","1","1","0","1"},
    {"0","1","1","1","1","1"},
    {"0","0","1","1","1","1"}
  };
  cout << "Maximum Row Area: " << to_string(lowCoverage(mall)) << endl;
  return 0;
}