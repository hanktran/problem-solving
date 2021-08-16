using namespace std;

#include <iostream>
#include <vector>

class SubsetSum {
  public:
    int countSubsets(const vector<int> &num, int sum) {
      return this->countSubsetsRecursive(num, sum, 0);
    }

  private:
    int countSubsetsRecursive(const vector<int> &num, int sum, int currentIndex) {
      if (sum == 0) {
        return 1;
      }

      if (num.empty() || currentIndex >= num.size()) {
        return 0;
      }

      int sum1 = 0;
      if (num[currentIndex] <= sum) {
        sum1 = countSubsetsRecursive(num, sum - num[currentIndex], currentIndex + 1);
      }

      int sum2 = countSubsetsRecursive(num, sum, currentIndex + 1);

      return sum1 + sum2;
    }
};

class SubsetSumTopDown {
  public:
    int countSubsets(const vector<int> &num, int sum) {
      vector<vector<int>> dp(num.size(), vector<int>(sum + 1, -1));
      return this->countSubsetsRecursive(dp, num, sum 0);
    }

  private:
    int countSubsetsRecursive(vector<vector<int>> &dp, const vector<int> &num, int sum, int currentIndex) {
      if (sum == 0) {
        return 1;
      }

      if (num.empty() || currentIndex >= num.size()) {
        return 0;
      }

      if (dp[currentIndex][sum] == -1) {
        int sum1 = 0;
        if (num[currentIndex] <= sum) {
          sum1 = countSubsetsRecursive(dp, num, sum - num[currentIndex], currentIndex + 1);
        }

        int sum2 = countSubsetsRecursive(dp, num, sum, currentIndex + 1);

        dp[currentIndex][sum] = sum1 + sum2;
      }

      return dp[currentIndex][sum];
    }
};

class SubsetSumBottomUp {
  public:
    int countSubsets(const vector<int> &num, int sum) {
      int n = num.size();
      vector<vector<int>> dp(n, vector<int>(sum + 1, 0));

      for (int i = 0; i < n; i++) {
        dp[i][0] = 1;
      }

      for (int s = 1; s <= sum; s++) {
        dp[0][s] = (num[0] == s ? 1 : 0);
      }

      for (int i = 1; i < num.size(); i++) {
        for (int s = 1; s <= sum; s++) {
          dp[i][s] = dp[i - 1][s];

          if (s >= num[i]) {
            dp[i][s] += dp[i - 1][s - num[i]];
          }
        }
      }

      return dp[num.size() - 1][sum];
    }
};

class SubsetSumBottomUp1 {
  public:
    int countSubsets(const vector<int> &num, int sum) {
      int n = num.size();
      vector<int> dp(sum + 1);
      dp[0] = 1;

      for (int s = 1; s <= sum; s++) {
        dp[s] = (num[0] == s ? 1 : 0);
      }

      for (int i = 1; i < num.size(); i++) {
        for (int s = sum; s >= 0; s--) {
          if (s >= num[i]) {
            dp[s] += dp[s - num[i]];
          }
        }
      }

      return dp[sum];
    }
};