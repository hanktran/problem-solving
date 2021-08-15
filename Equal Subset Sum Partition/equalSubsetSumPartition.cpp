using namespace std;

#include <iostream>
#include <vector>

// brute-force solution
class PartitionSet {
  public:
    bool canPartition(const vector<int> &num) {
      int sum = 0;
      for (int i = 0; i < num.size(); i++) {
        sum += num[i];
      }

      if (sum % 2 != 0) {
        return false;
      }

      return this->canPartitionRecursive(num, sum / 2, 0);
    }

  private:
    bool canPartitionRecursive(const vector<int> &num, int sum, int currentIndex) {
      if (sum == 0) {
        return true;
      }

      if (num.empty() || currentIndex >= num.size()) {
        return false;
      }

      if (num[currentIndex] <= sum) {
        if (canPartitionRecursive(num, sum - num[currentIndex], currentIndex + 1)) {
          return true;
        }
      }

      return canPartitionRecursive(num, sum, currentIndex + 1);
    }
};

// top-down DP memoization
class PartitionSetTopDownDP {
  public:
    bool canPartition(const vector<int> &num) {
      int sum = 0;
      for (int i = 0; i < num.size(); i++) {
        sum += num[i];
      }

      if (sum % 2 != 0) {
        return false;
      }

      vector< vector<int> > dp(num.size(), vector<int>(sum / 2 + 1, -1));
      return this->canPartitionRecursive(dp, num, sum / 2, 0);
    }

  private:
    bool canPartitionRecursive(vector< vector<int> > &dp, const vector<int> &num, int sum, int currentIndex) {
      if (sum == 0) {
        return true;
      }

      if (num.empty() || currentIndex >= num.size()) {
        return false;
      }

      if (dp[currentIndex][sum] == -1) {
        if (num[currentIndex] <= sum) {
          if (canPartitionRecursive(dp, num, sum - num[currentIndex], currentIndex + 1)) {
            dp[currentIndex][sum] = 1;
            return true;
          }

          dp[currentIndex][sum] = canPartitionRecursive(dp, num, sum, currentIndex + 1);
        }
      }

      return dp[currentIndex][sum] == 1 ? true : false;
    }
};

// bottom-up DP
class PartitionSetBottomUpDP {
  public:
    bool canPartition(const vector<int> &num) {
      int n = num.size();
      int sum = 0;
      for (int i = 0; i < n; i++) {
        sum += num[i];
      }

      if (sum % 2 != 0) {
        return false;
      }

      sum /= 2;

      vector< vector<bool> > dp(n, vector<bool>(sum + 1));

      for (int i = 0; i < n; i++) {
        dp[i][0] = true;
      }

      for (int s = 1; s <= sum; s++) {
        dp[0][s] = (num[0] == s ? true : false);
      }

      for (int i = 1; i < n; i++) {
        for (int s = 1; s <= sum; s++) {
          if (dp[i - 1][s]) {
            dp[i][s] = dp[i - 1][s];
          } else if (s >= num[i]) {
            dp[i][s] = dp[i - 1][s - num[i]];
          }
        }
      }

      return dp[n - 1][sum];
    }
};