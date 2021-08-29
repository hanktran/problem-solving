using namespace std;

#include <iostream>
#include <vector>

class Staircase {
  public:
    int findMinFee(const vector<int> &fee) {
      return findMinFeeRecursive(fee, 0);
    }

  private:
    int findMinFeeRecursive(const vector<int> &fee, int currentIndex) {
      if (currentIndex > fee.size() - 1) {
        return 0;
      }

      int take1Step = findMinFeeRecursive(fee, currentIndex + 1);
      int take2Step = findMinFeeRecursive(fee, currentIndex + 2);
      int take3Step = findMinFeeRecursive(fee, currentIndex + 3);

      int minFee = min(min(take1Step, take2Step), take3Step);

      return minFee + fee[currentIndex];
    }
};

class StaircaseTopDown {
  public:
    int findMinFee(const vector<int> &fee) {
      vector<int> dp(free.size() , 0);
      return findMinFeeRecursive(dp, fee, 0);
    }

  private:
    int findMinFeeRecursive(vector<int> &dp, const vector<int> &fee, int currentIndex) {
      if (currentIndex > fee.size() - 1) {
        return 0;
      }

      if (dp[currentIndex] == 0) {
        int take1Step = findMinFeeRecursive(dp, fee, currentIndex + 1);
        int take2Step = findMinFeeRecursive(dp, fee, currentIndex + 2);
        int take3Step = findMinFeeRecursive(dp, fee, currentIndex + 3);

        dp[currentIndex] = fee[currentIndex] + min(min(take1Step, take2Step), take3Step);
      }

      return dp[currentIndex];
    }
};

class StaircaseBottomUp {
  public:
    int findMinFee(const vector<int> &fee) {
      vector<int> dp(fee.size() + 1);
      dp[0] = 0;
      dp[1] = fee[0];
      dp[2] = fee[0];

      for (int i = 2; i < fee.size(); i++) {
        dp[i + 1] = min(fee[i] + dp[i], min(fee[i - 1] + dp[i - 1], fee[i - 2] + dp[i - 2]));
      }

      return dp[fee.size()];
    }
};