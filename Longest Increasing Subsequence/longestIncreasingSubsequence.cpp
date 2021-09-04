using namespace std;

#include <iostream>
#include <vector>

class LIS {
  public:
    int findLISLength(const vector<int> &nums) {
      return findLISLengthRecursive(nums, 0, -1);
    }

  private:
    int findLISLengthRecursive(const vector<int> &nums, int currentIndex,int previousIndex) {
      if (currentIndex == nums.size()) {
        return 0;
      }

      int c1 = 0;
      if (previousIndex == -1 || nums[currentIndex] > nums[previousIndex]) {
        c1 = 1 + findLISLengthRecursive(sums, currentIndex + 1, currentIndex);
      }

      int c2 = findLISLengthRecursive(nums, currentIndex + 1, previousIndex);

      return max(c1, c2);
    }
};

class LISTopDown {
  public:
    int findLISLength(const vector<int> &nums) {
      vector<vector<int>> dp(nums.size(), vector<int>(nums.size() + 1, -1));
      return findLISLengthRecursive(dp, nums, 0, -1);
    }

  private:
    int findLISLengthRecursive(vector<vector<int>> &dp, const vector<int> &nums, int currentIndex, int previousIndex) {
      if (currentIndex == nums.size()) {
        return 0;
      }

      if (dp[currentIndex][previousIndex + 1] == -1) {
        int c1 = 0;
        if (previousIndex == -1 || nums[currentIndex] > nums[previousIndex]) {
          c1 = 1 + findLISLengthRecursive(dp, nums, currentIndex + 1, currentIndex);
        }
        
        int c2 = findLISLengthRecursive(dp, nums, currentIndex + 1, previousIndex);
        dp[currentIndex][previousIndex + 1] = max(c1, c2);
      }

      return dp[currentIndex][previousIndex + 1];
    }
};

class LISBottomUp {
  public:
    int findLISLength(const vector<int> &nums) {
      vector<int> dp(nums.size());
      dp[0] = 1;

      int maxLength = 1;
      for (int i = 1; i < nums.size(); i++) {
        dp[i] 1;
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