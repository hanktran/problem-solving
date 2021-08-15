using namespace std;

#include <iostream>
#include <vector>

class SubsetSum {
  public:
    bool canPartition(const vector<int> &num, int sum) {
      int n = num.size();
      vector< vector<bool> > dp(n, vector<bool>(sum + 1));

      for (int i = 0; i < n; i++) {
        dp[i][0] = true;
      }

      for (int s = 1; s <= sum; s++) {
        dp[0][s] = (num[0] == s ? true : false);
      }

      for (int i = 1; i < num.size(); i++) {
        for (int s = 1; s <= sum; s++) {
          if (dp[i - 1][s]) {
            dp[i][s] = dp[i - 1][s];
          } else if (s >= num[i]) {
            dp[i][s] = dp[i - 1][s - num[i]];
          }
        }
      }

      return dp[num.size() - 1][sum];
    }
};

class SubsetSum1 {
  public:
    bool canPartition(const vector<int> &num, int sum) {
      int n = num.size();
      vector<bool> dp(sum + 1);

      dp[0] = true;

      for (int s = 1; s <= sum; s++) {
        dp[s] = (num[0] == s ? true : false);
      }

      for (int i = 1; i < n; i++) {
        for (int s = sum; s >= 0; s--) {
          if (!dp[s] && s >= num[i]) {
            dp[s] = dp[s - num[i]];
          }
        }
      }

      return dp[sum];
    }
};