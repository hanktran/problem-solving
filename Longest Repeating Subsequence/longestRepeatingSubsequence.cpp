using namespace std;

#include <iostream>
#include <string>
#include <vector>

class LRS {
  public:
    int findLRSLength(const string &str) {
      return findLRSLengthRecursive(str, 0, 0);
    }

  private:
    int findLRSLengthRecursive(const string &str, int i1, int i2) {
      if (i1 == str.length() || i2 == str.length()) {
        return 0;
      }

      if (i1 != i2 && str[i1] == str[i2]) {
        return 1 + findLRSLengthRecursive(str, i1 + 1, i2 + 1);
      }

      int c1 = findLRSLengthRecursive(str, i1, i2 + 1);
      int c2 = findLRSLengthRecursive(str, i1 + 1, i2);

      return max(c1, c2);
    }
};

class LRSTopDown {
  public:
    int findLRSLength(const string &str) {
      vector<vector<int>> dp(str.length(), vector<int>(str.length(), -1));
      return findLRSLengthRecursive(dp, str, 0, 0);
    }

  private:
    int findLRSLengthRecursive(vector<vector<int>> &dp, const string &str, int i1, int i2) {
      if (i1 == str.length() || i2 == str.length()) {
        return 0;
      }

      if (dp[i1][i1] == -1) {
        if (i1 != i2 && str[i1] == str[i2]) {
          dp[i1][i2] = 1 + findLRSLengthRecursive(dp, str, i1 + 1, i2 + 1);
        } else {
          int c1 = findLRSLengthRecursive(dp, str, i1, i2 + 1);
          int c2 = findLRSLengthRecursive(dp, str, i1 + 1, i2);
          dp[i1][i2] = max(c1, c2);
        }
      }

      return dp[i1][i2];
    }
};

class LRSBottomUp {
  public:
    int findLRSLength(const string &str) {
      vector<vector<int>> dp(str.length() + 1, vector<int>(str.length() + 1));
      int maxLength = 0;
      
      for (int i1 = 1; i1 <= str.length(); i1++) {
        for (int i2 = 1; i2 <= str.length(); i2++) {
          if (i1 != i2 && str[i1 - 1] == str[i2 - 1]) {
            dp[i1][i2] = 1 + dp[i1 - 1][i2 - 1];
          } else {
            dp[i1][i2] = max(dp[i1 - 1][i2], dp[i1][i2 - 1]);
          }

          maxLength = max(maxLength, dp[i1][i2]);
        }
      }

      return maxLength;
    }
};