using namespace std;

#include <iostream>
#include <vector>

class ExpressNumber {
  public:
    int countWays(int n) {
      if (n == 0) {
        return 1;
      }

      if (n == 1) {
        return 1;
      }

      if (n == 2) {
        return 1;
      }

      if (n == 3) {
        return 2;
      }

      int subtract1 = countWays(n - 1);
      int subtract3 = countWays(n - 3);
      int subtract4 = countWays(n - 4);

      return subtract1 + subtract3 + subtract4;
    }
};

class ExpressNumberTopDown {
  public:
    int countWays(int n) {
      vector<int> dp(n + 1, 0);
      return countWaysRecursive(dp, n);
    }

    int countWaysRecursive(vector<int> &dp, int n) {
      if (n == 0) {
        return 1;
      }

      if (n == 1) {
        return 1;
      }

      if (n == 2) {
        return 1;
      }

      if (n == 3) {
        return 2;
      }

      if (dp[n] == 0) {
        int subtract1 = countWaysRecursive(dp, n - 1);
        int subtract3 = countWaysRecursive(dp, n - 3);
        int subtract4 = countWaysRecursive(dp, n - 4);
        dp[n] = subtract1 + subtract3 + subtract4;
      }

      return dp[n];
    }
};

class ExpressNumberBottomUp {
  public:
    int countWays(int n) {
      if (n <= 2) return 1;
      if (n == 3) return 2;

      vector<int> dp(n + 1);
      dp[0] = 1;
      dp[1] = 1;
      dp[2] = 1;
      dp[3] = 2;

      for (int i = 4; i <= n; i++) {
        dp[i] = dp[i - 1] + dp[i - 3] + dp[i - 4];
      }

      return dp[n];
    }
};