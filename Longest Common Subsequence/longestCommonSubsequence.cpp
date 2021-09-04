using namespace std;

#include <iostream>
#include <string>
#include <vector>

class LCS {
  public:
    int findLCSLength(const string &s1, const string &s2) {
      return findLCSLengthRecursive(s1, s2, 0, 0);
    }

  private:
    int findLCSLengthRecursive(const string &s1, const string &s2, int i1, int i2) {
      if (i1 == s1.length() || i2 == s2.length()) {
        return 0;
      }

      if (s1[i1] == s2[i2]) {
        return 1 + findLCSLengthRecursive(s1, s2, i1 + 1, i2 + 1);
      }

      int c1 = findLCSLengthRecursive(s1, s2, i1, i2 + 1);
      int c2 = findLCSLengthRecursive(s1, s2, i1 + 1, i2);
      return max(c1, c2);
    }
};

class LCSTopDown {
  public:
    int findLCSLength(const string &s1, const string &s2) {
      vector<vector<int>> dp(s1.length(), vector<int>(s2.length(), -1));
      return findLCSLengthRecursive(dp, s1, s2, 0, 0);
    }

  private:
    int findLCSLengthRecursive(vector<vector<int>> &dp, const string &s1, const string &s2, int i1, int i2) {
      if (i1 == s1.length() || i2 == s2.length()) {
        return 0;
      }

      if (dp[i1][i2] == -1) {
        dp[i1][i2] = 1 + findLCSLengthRecursive(dp, s1, s2, i1 + 1, i2 + 1);
      } else {
        int c1 = findLCSLengthRecursive(dp, s1, s2, i1, i2 + 1);
        int c2 = findLCSLengthRecursive(dp, s1, s2, i1 + 1, i2);
        dp[i1][i2] = max(c1, c2);
      }

      return dp[i1][i2];
    }
};

class LCSBottomUp {
  public:
    int findLCSLength(const string &s1, const string &s2) {
      vector<vector<int>> dp(s1.length() + 1, vector<int>(s2.length() + 1));
      int maxLength = 0;
      for (int i = 1; i <= s1.length(); i++) {
        for (int j = 1; j <= s2.length(); j++) {
          if (s1[i - 1] == s2[j - 1]) {
            dp[i][j] = 1 + dp[i - 1][j - 1];
          } else {
            dp[i][j] = max(dp[i - 1][j], d[i][j - 1]);
          }

          maxLength = max(maxLength, dp[i][j]);
        }
      }

      return maxLength;
    }
};