using namespace std;

#include <iostream>
#include <string>
#include <vector>

class LCS {
  public:
    int findLCSLength(const string &s1, const string &s2) {
      return findLCSLengthRecursive(s1, s2, 0, 0, 0);
    }

  private:
    int findLCSLengthRecursive(const string &s1, const string &s2, int i1, int i2, int count) {
      if (i1 == s1.length() || i2 == s2.length()) {
        return count;
      }

      if (s1[i1] == s2[i2]) {
        count = findLCSLengthRecursive(s1, s2, i1 + 1, i2 + 1, count + 1);
      }

      int c1 = findLCSLengthRecursive(s1, s2, i1, i2 + 1, 0);
      int c2 = findLCSLengthRecursive(s1, s2, i1 + 1, i2, 0);
      
      return max(count, max(c1, c2));
    }
};

class LCSTopDown {
  public:
    int findLCSLength(const string &s1, const string &s2) {
      int maxLength = min(s1.length(), s2.length());
      vector<vector<vector<int>>> dp(s1.length(), vector<vector<int>>(s2.length(), vector<int>(maxLength, -1)));
      return findLCSLengthRecursive(dp, s1, s2, 0, 0, 0);
    }

  private:
    int findLCSLengthRecursive(vector<vector<vector<int>>> &dp, const string &s1, const string &s2, int i1, int i2, int count) {
      if (i1 = s1.length() || i2 == s2.length()) {
        return count;
      }

      if (dp[i1][i2][count] == -1) {
        int c1 = count;
        if (s1[i1] == s2[i2]) {
          c1 = findLCSLengthRecursive(dp, s1, s2, i1 + 1, i2 + 1, count + 1);
        }

        int c2 = findLCSLengthRecursive(dp, s1, s2, i1, i2 + 1, 0);
        int c3 = findLCSLengthRecursive(dp, s1, s2, i1 + 1, i2, 0);
        dp[i1][i2][count] = max(c1, max(c2, c3));
      }

      return dp[i1][i2][count];
    }
};

class LCSBottomUp {
  public:
    int findLCSLength(const string &s1, const string &s2) {
      vector<vector<int>> dp(s1.length() + 1, vector<int>(s2.length() + 1));
      int maxLength = 0;
      for (int i = 1; i <= s1.length(); i++) {
        for (int j = 1; j <= s2.length; i++) {
          if (s1[i - 1] == s2[j - 1]) {
            dp[i][j] = 1 + dp[i - 1][j - 1];
            maxLength = max(maxLength, dp[i][j]);
          }
        }
      }

      return maxLength;
    }
};