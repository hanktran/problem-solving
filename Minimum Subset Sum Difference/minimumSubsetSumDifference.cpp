using namespace std;

#include <iostream>
#include <vector>
#include <stdlib.h>

class PartitionSet1 {
  public:
    int canPartition(const vector<int> &num) {
      return this->canPartitionRecusive(num, 0, 0, 0);
    }

  private:
    int canPartitionRecusive(const vector<int> &num, int currentIndex, int sum1, int sum2) {
      if (currentIndex == num.size()) {
        return abs(sum1 - sum2);
      }

      int diff1 = canPartitionRecusive(num, currentIndex + 1, sum1 + num[currentIndex], sum2);

      int diff2 = canPartitionRecusive(num, currentIndex + 1, sum1, sum2 + num[currentIndex]);

      return min(diff1, diff2);
    }
};

class PartitionSet2 {
  public:
    int canPartition(const vector<int> &num) {
      int sum = 0;
      for (int i = 0; i < num.size(); i++) {
        sum += num[i];
      }

      vector< vector<int> > dp(num.size(), vector<int>(sum + 1, -1));
      return this->canPartitionRecusive(dp, num, 0, 0, 0);
    }

  private:
    int canPartitionRecusive(vector< vector<int> > &dp, const vector<int> &num, int currentIndex, int sum1, int sum2) {
      if (currentIndex == num.size()) {
        return abs(sum1 - sum2);
      }

      if (dp[currentIndex][sum1] == -1) {
        int diff1 = canPartitionRecusive(dp, num, currentIndex + 1, sum1 + num[currentIndex], sum2);
        int diff2 = canPartitionRecusive(dp, num, currentIndex + 1, sum1, sum2 + num[currentIndex]);

        dp[currentIndex][sum1] = min(diff1, diff2);
      }

      return dp[currentIndex][sum1];
    }
};

class PartitionSet3 {
  public:
    int canPartition(const vector<int> &num) {
      int sum = 0;
      for (int i = 0; i < num.size(); i++) {
        sum += num[i];
      }

      int n = num.size();
      vector< vector<bool> > dp(n, vector<bool>(sum / 2 + 1, false));

      for (int i = 0; i < n; i++) {
        dp[i][0] = true;
      }

      for (int s = 0; s <= sum / 2; s++) {
        dp[0][s] = (num[0] == s ? true : false);
      }

      for (int i = 1; i < num.size(); i++) {
        for (int s = 1; s <= sum / 2; s++) {
          if (dp[i - 1][s]) {
            dp[i][s] = dp[i - 1][s];
          } else if (s >= num[i]) {
            dp[i][s] = dp[i - 1][s - num[i]];
          }
        }
      }

      int sum1 = 0;
      for (int i = sum / 2; i >= 0; i--) {
        if (dp[n - 1][i] == true) {
          sum1 = i;
          break;
        }
      }

      int sum2 = sum - sum1;
      return abs(sum2 - sum1);
    }
};