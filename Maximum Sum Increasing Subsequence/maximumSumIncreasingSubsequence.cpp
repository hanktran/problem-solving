using namespace std;

#include <iostream>
#include <vector>
#include <string>
#include <unordered_map>

class MSIS {
  public:
    int findMSIS(const vector<int> &nums) {
      return findMSISRecursive(nums, 0, -1, 0);
    }

  private:
    int findMSISRecursive(const vector<int> &nums, int currentIndex, int previousIndex, int sum) {
      if (currentIndex == nums.size()) {
        return sum;
      }

      int s1 = sum;
      if (previousIndex == -1 || nums[currentIndex] > nums[previousIndex]) {
        s1 = findMSISRecursive(nums, currentIndex + 1, currentIndex, sum + nums[currentIndex]);
      }

      int s2 = findMSISRecursive(nums, currentIndex + 1, previousIndex, sum);

      return max(s1, s2);
    }
};

class MSISTopDown {
  public:
    int findMSIS(const vector<int> &nums) {
      unordered_map<string, int> dp;
      return findMSISRecurisve(dp, nums, 0, -1, 0);
    }

  private:
    int findMSISRecurisve(unordered_map<string, int> &dp, const vector<int> &nums, int currentIndex, int previousIndex, int sum) {
      if (currentIndex == nums.size()) {
        return sum;
      }

      string subProblemKey = to_string(currentIndex) + "-" + to_string(previousIndex) + "-" + to_string(sum);

      if (dp.find(subProblemKey) == dp.end()) {
        int s1 = sum;
        if (previousIndex == -1 || nums[currentIndex] > nums[previousIndex]) {
          s1 = findMSISRecurisve(dp, nums, currentIndex + 1, currentIndex, sum + nums[currentIndex]);
        }

        int s2 = findMSISRecurisve(dp, nums, currentIndex + 1, previousIndex, sum);
        dp.emplace(subProblemKey, max(s1, s2));
      }

      return dp[subProblemKey];
    }
};

class MSISBottomUp {
  public:
    int findMSIS(const vector<int> &nums) {
      vector<int> dp(nums.size());
      dp[0] = nums[0];

      int maxSum = nums[0];
      for (int i = 1; i < nums.size(); i++) {
        dp[i] = nums[i];
        for (int j = 0; j < i; j++) {
          if (nums[i] > nums[j] && nums[i] < dp[j] + nums[i]) {
            dp[i] = dp[j] + nums[i];
          }
        }
        maxSum = max(maxSum, dp[i]);
      }

      return maxSum;
    }
};