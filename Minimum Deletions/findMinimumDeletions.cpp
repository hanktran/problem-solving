using namespace std;

#include <iostream>
#include <vector>

class MDSS {
  public:
    int findMinimumDeletions(const vector<int> &nums) {
      return nums.size() - findLISLength(nums);
    }

  private:
    int findLISLength(const vector<int> &nums) {
      vector<int> dp(nums.size());
      dp[0] = 1;

      int maxLength = 1;
      for (int i = 1; i < nums.size(); i++) {
        dp[i] = 1;
        for (int j = 0; j < i; j++) {
          if (nums[i] > nums[j] && dp[i] <= dp[j]) {
            dp[i] = dp[j] + 1;
            maxLength = max(maxLength, dp[i]);
          }
        }
      }

      return maxLength;
    }
};