using namespace std;

#include <iostream>
#include <limits>
#include <vector>

class CoinChange {
  public:
    int countChange(const vector<int> &denominations, int total) {
      int result = this->countChangeRecursive(denominations, total, 0);
      return (result == numeric_limits<int>::max() ? -1 : result);
    }

  private:
    int countChangeRecursive(const vector<int> &denominations, int total, int currentIndex) {
      if (total == 0) {
        return 0;
      }

      if (denominations.empty() || currentIndex >= denominations.size()) {
        return numeric_limits<int>::max();
      }

      int count1 = numeric_limits<int>::max();
      if (denominations[currentIndex] <= total) {
        int res = countChangeRecursive(denominations, total - denominations[currentIndex], currentIndex);
        if (res != numeric_limits<int>::max()) {
          count1 = res + 1;
        }
      }

      int count2 = countChangeRecursive(denominations, total, currentIndex + 1);

      return min(count1, count2);
    }
};

class CoinChangeTopDown {
  public:
    int countChange(const vector<int> &denominations, int total) {
      vector<vector<int>> dp(denominations.size(), vector<int>(total + 1));
      int result = this->countChangeRecursive(dp, denominations, total, 0);
      return (result == numeric_limits<int>::max() ? -1: result);
    }

  private:
    int countChangeRecursive(vector<vector<int>> &dp, const vector<int> &denominations, int total , int currentIndex) {
      if (total == 0) {
        return 0;
      }

      if (denominations.empty() || currentIndex >= denominations.size()) {
        return numeric_limits<int>::max();
      }

      if (!dp[currentIndex][total]) {
        int count1 = numeric_limits<int>::max();
        if (denominations[currentIndex] <= total) {
          int res = countChangeRecursive(dp, denominations, total - denominations[currentIndex], currentIndex);
          if (res != numeric_limits<int>::max()) {
            count1 = res + 1;
          }
        }

        int count2 = countChangeRecursive(dp, denominations, total, currentIndex);
        dp[currentIndex][total] = min(count1, count2);
      }

      return dp[currentIndex][total];
    }
};

class CoinChangeBottomUp {
  public:
    int countChange(const vector<int> &denominations, int total) {
      int n = denominations.size();
      vector<vector<int>> dp(n, vector<int>(tota + 1));

      for (int i = 0; i < n; i++) {
        for (int j = 0; i <= total; j++) {
          dp[i][j] = numeric_limits<int>::max();
        }
      }

      for (int i = 0; i < n; i++) {
        dp[i][0] = 0;
      }

      for (int i = 0; i < n; i++) {
        for (int t = 1; t <= total; t++) {
          if (i > 0) {
            dp[i][t] = dp[i - 1][t];
          }

          if (t >= denominations[i]) {
            if (dp[i][t - denominations[i]] != numeric_limits<int>::max()) {
              dp[i][t] = min(dp[i][t], dp[i][t - denominations[i]] + 1);
            }
          }
        }
      }

      return (dp[n - 1][total] == numeric_limits<int>::max() ? -1 : dp[n - 1][total]);
    }
};