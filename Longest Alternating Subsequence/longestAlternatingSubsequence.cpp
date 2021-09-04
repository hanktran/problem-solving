using namespace std;

#include <iostream>
#include <vector>

class LAS {
  public:
    int findLASLength(const vector<int> &nums) {
      return max(findLASLengthRecursive(nums, -1, 0, true),
                  findLASLengthRecursive(nums, -1, 0, false));
    }

  private:
    int findLASLengthRecursive(const vector<int> &nums, int previousIndex, int currentIndex, bool isAsc) {
      if (currentIndex == nums.size()) {
        return 0;
      }

      int c1 = 0;
      if (isAsc) {
        if (previousIndex == -1 || nums[previousIndex] < nums[currentIndex]) {
          c1 = 1 + this->findLASLengthRecursive(nums, currentIndex, currentIndex + 1, !isAsc);
        }
      } else {
        if (previousIndex == -1 || nums[previousIndex] > nums[currentIndex]) {
          c1 = 1 + this->findLASLengthRecursive(nums, currentIndex, currentIndex + 1, !isAsc);
        }
      }

      int c2 = this->findLASLengthRecursive(nums, previousIndex, currentIndex + 1, isAsc);
      return max(c1, c2);
    }
};

class LASTopDown {
  public:
    int findLASLength(const vector<int> &nums) {
      vector<vector<vector<int>>> dp(nums.size(), vector<vector<int>>(nums.size(), vector<int>(2, -1)));
      return max(findLASLengthRecursive(dp, nums, -1, 0, true),
                  findLASLengthRecursive(dp, nums, -1, 0, false));
    }

  private:
    int findLASLengthRecursive(vector<vector<vector<int>>> &dp, const vector<int> &nums, int previousIndex, int currentIndex, bool isAsc) {
      if (currentIndex == nums.size()) {
        return 0;
      }

      if (isAsc) {
        if (previousIndex == -1 || nums[previousIndex] < nums[currentIndex]) {
          c1 = 1 + this->findLASLengthRecursive(dp, nums, currentIndex, currentIndex + 1, !isAsc);
        }
      } else {
        if (previousIndex == -1 || nums[previousIndex] > nums[currentIndex]) {
          c1 = 1 + this->findLASLengthRecursive(dp, nums, currentIndex, currentIndex + 1, !isAsc);
        }
      }

      int c2 = this->findLASLengthRecursive(dp, nums, previousIndex, currentIndex + 1, isAsc);
      dp[previousIndex + 1][currentIndex][isAsc ? 1 : 0] = max(c1, c2);
    }
};

class LASBottomUp {
  public:
    int findLASLength(const vector<int> &nums) {
      if (nums.empty()) {
        return 0;
      }

      vector<vector<int>> dp(nums.size(), vector<int>(2));
      int maxLength = 1;
      for (int i = 0; i < nums.size(); i++) {
        dp[i][0] = dp[i][1] = 1;
        for (int j = 0; j < i; j++) {
          if (nums[i] > nums[j]) {
            dp[i][0] = max(dp[i][0], 1 + dp[j][1]);
            maxLength = max(maxLength, dp[i][0]);
          } else if (nums[i] != nums[j]) {
            dp[i][1] = max(dp[i][1], 1 + dp[j][0]);
            maxLength = max(maxLength, dp[i][1]);
          }
        }
      }

      return maxLength;
    }
};