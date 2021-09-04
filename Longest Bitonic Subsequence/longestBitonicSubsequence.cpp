using namespace std;

#include <iostream>
#include <vector>

class LBS {
  public:
    int findLBSLength(const vector<int> &nums) {
      int maxLength = 0;
      for (int i = 0; i < nums.size(); i++) {
        int c1 = findLDSLength(nums, i, -1);
        int c2 = findLDSLengthRev(nums, i, -1);
        maxLength = max(maxLength, c1 + c2 - 1);
      }

      return maxLength;
    }

  private:
    int findLDSLength(const vector<int> &nums, int currentIndex, int previousIndex) {
      if (currentIndex == nums.size()) {
        return 0;
      }

      int c1 = 0;
      if (previousIndex == -1 || nums[currentIndex] < nums[previousIndex]) {
        c1 = 1 + findLDSLength(nums, currentIndex + 1, currentIndex);
      }
      int c2 = findLDSLength(nums, currentIndex + 1, previousIndex);

      return max(c1, c2);
    }

    int findLDSLengthRev(const vector<int> &nums, int currentIndex, int previousIndex) {
      if (currentIndex < 0) {
        return 0;
      }

      int c1 = 0;
      if (previousIndex == -1 || nums[currentIndex] < nums[previousIndex]) {
        c1 = 1 + findLDSLengthRev(nums, currentIndex - 1, currentIndex);
      }
      int c2 = findLDSLengthRev(nums, currentIndex - 1, previousIndex);

      return max(c1, c2);
    }
};

class LBSTopDown {
  public:
    int findLBSLength(const vector<int> &nums) {
      vector<vector<int>> lds(nums.size(), vector<int>(nums.size() + 1, -1));
      vector<vector<int>> ldsRev(nums.size(), vector<int>(nums.size() + 1, -1));

      int maxLength = 0;
      for (int i = 0; i < nums.size(); i++) {
        int c1 = findLDSLength(lds, nums, i, -1);
        int c2 = findLDSLengthRev(ldsRev, nums, i, -1);
        maxLength = max(maxLength, c1 + c2 - 1);
      }

      return maxLength;
    }

  private:
    int findLDSLength(vector<vector<int>> &dp, const vector<int> &nums, int currentIndex, int previousIndex) {
      if (currentIndex == nums.size()) {
        return 0;
      }

      if (dp[currentIndex][previousIndex + 1] == -1) {
        int c1 = 0;
        if (previousIndex == -1 || nums[currentIndex] < nums[previousIndex]) {
          c1 = 1 + findLDSLength(dp, nums, currentIndex + 1, currentIndex);
        }

        int c2 = findLDSLength(dp, nums, currentIndex + 1, previousIndex);

        dp[currentIndex][previousIndex + 1] = max(c1, c2);
      }

      return dp[currentIndex][previousIndex + 1];
    }

    int findLDSLengthRev(vector<vector<int>> &dp, const vector<int> &nums, int currentIndex, int previousIndex) {
      if (currentIndex < 0) {
        return 0;
      }

      if (dp[currentIndex][previousIndex + 1] == -1) {
        int c1 = 0;
        if (previousIndex == -1 || nums[currentIndex] < nums[previousIndex]) {
          c1 = 1 + findLDSLengthRev(dp, nums, currentIndex - 1, currentIndex);
        }

        int c2 = findLDSLengthRev(dp, nums, currentIndex - 1, previousIndex);

        dp[currentIndex][previousIndex + 1] = max(c1, c2);
      }

      return dp[currentIndex][previousIndex + 1];
    }
};

class LBS {
  public:
    int findLBSLength(const vector<int> &nums) {
      vector<int> lds(nums.size());
      vector<int> ldsRev(nums.size());

      for (int i = 0; i < nums.size(); i++) {
        lds[i] = 1;
        for (int j = i - 1; j >= 0; j--) {
          if (nums[j] < nums[i]) {
            lds[i] = max(lds[i], lds[j] + 1);
          }
        }
      }

      for (int i = nums.size() - 1; i >= 0; i--) {
        ldsRev[i] = 1;
        for (int j = i + 1; j < nums.size(); j++) {
          if (nums[j] < nums[i]) {
            ldsRev[i] = max(ldsRev[i], ldsRev[j] + 1);
          }
        }
      }

      int maxLength = 0;
      for (int i = 0; i < nums.size(); i++) {
        maxLength = max(maxLength, lds[i] + ldsRev[i] - 1);
      }

      return maxLength;
    }
};