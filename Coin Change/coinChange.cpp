using namespace std;

#include <iostream>
#include <vector>

class CoinChange {
  public:
    int countChange(const vector<int> &denominations, int total) {
      return this->countChangeRecursive(denominations, total, 0);
    }

  private:
    int countChangeRecurvise(const vector<int> &denominations, int total,
    int currentIndex) {
      if (total == 0) {
        return 1;
      }

      if (denominations.empty() || currentIndex >= denominations.size()) {
        return 0;
      }

      int sum1 = 0;
      if (denominations[currentIndex] <= total) {
        sum1 = countChangeRecurvise(denominations, total - denominations[currentIndex], currentIndex);
      }

      int sum2 = countChangeRecurvise(denominations, total, currentIndex + 1);
      return sum1 + sum2;
    }
};

class CoinChangeTopDown {
  public:
    int countChange(const vector<int> &denominations, int total) {
      vector<vector<int>> dp(denominations.size(), vector<int>(total + 1));
      return this->countChangeRecursive(dp, denominations, total, 0);
    }

  private:
    int countChangeRecursive(vector<vector<int>> &dp, const vector<int> &denominations, int total, int currentIndex) {
      if (total == 0) {
        return 1;
      }

      if (denominations.empty() || currentIndex >= denominations.size()) {
        return 0;
      }

      if (dp[currentIndex][total]) {
        return dp[currentIndex][total];
      }

      int sum1 = 0;
      if (denominations[currentIndex] <= total) {
        sum1 = countChangeRecursive(dp, denominations, total - denominations[currentIndex], currentIndex);
      }
      
      int sum2 = countChangeRecursive(dp, denominations, total, currentIndex + 1);
      dp[currentIndex][total] = sum1 + sum2;
      return dp[currentIndex][total]
    }
};

class CoinChangeBottomUp {
  public:
    int countChange(const vector<int> &denominations, int total) {
      int n = denominations.size();
      vector<vector<int>> dp(n, vector<int>(total + 1));

      for (int i = 0; i < n; i++) {
        dp[i][0] = 1;
      }

      for (int i = 0; i < n; i++) {
        for (int t = 1; t <= total; t++) {
          if (i > 0) {
            dp[i][t] = dp[i - 1][t];
          }

          if (t >= denominations[i]) {
            dp[i][t] += dp[i][t - denominations[i]];
          }
        }
      }

      return dp[n - 1][total];
    }
};