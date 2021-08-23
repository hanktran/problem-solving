using namespace std;

#include <iostream>
#include <vector>

class TargetSum {
  public:
    int findTargetSubsets(const vector<int> &num, int s) {
      int totalSum = 0;
      for (auto n : num) {
        totalSum += n;
        if (n < 1) return -1;
      }

      if (totalSum < s || (s + totalSum) % 2 == 1) {
        return 0;
      }

      return countSubsets(num, (s + totalSum) / 2);
    }

  private:
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
            dp[i][s] += dp[i - 1][s - sum[i]];
          }
        }
      }

      return dp[num.size() - 1][sum];
    }
};

class TargetSum2 {
  public:
    int findTargetSubsets(const vector<int> &num, int s) {
      int totalSum = 0;
      for (auto n : num) {
        totalSum += n;
        if (n < 1) return -1;
      }

      if (totalSum < s || (s + totalSum) % 2 == 1) {
        return 0;
      }

      return countSubsets(num, (s + totalSum) / 2);
    }

  private:
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