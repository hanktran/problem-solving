using namespace std;

#include <iostream>
#include <vector>

class Staircase {
  public:
    int countWays(int n) {
      if (n == 0) {
        return 1;
      }

      if (n == 1) {
        return 1;
      }

      if (n == 2) {
        return 2;
      }

      int take1Step = countWays(n - 1);
      int take2Step = countWays(n - 2);
      int take3Step = countWays(n - 3);

      return take1Step + take2Step + take3Step;
    }
};

class StaircaseTopDown {
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
        return 2;
      }

      if (dp[n] == 0) {
        int take1Step = countWaysRecursive(dp, n - 1);
        int take2Step = countWaysRecursive(dp, n - 2);
        int take3Step = countWaysRecursive(dp, n - 3);
        dp[n] = take1Step + take2Step + take3Step;
      }

      return dp[n];
    }
};

class StaircaseBottomUp {
  public:
    int countWays(int n) {
      vector<int> dp(n + 1);
      dp[0] = 1;
      dp[1] = 1;
      dp[2] = 2;

      for (int i = 3; i <= n; i++) {
        dp[i] = dp[i - 1] + dp[i - 2] + dp[i - 3];
      }

      return dp[n];
    }
};

class StaircaseBottomUp1 {
  public:
    int countWays(int n) {
      if (n < 2) return 1;
      if (n == 2) return 2;

      int n1 = 1, n2 = 1, n3 = 2, temp;
      for (int i = 3; i <= n; i++) {
        temp = n1 + n2 + n3;
        n1 = n2;
        n2 = n3;
        n3 = temp;
      }

      return n3;
    }
};