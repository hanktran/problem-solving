using namespace std;

#include <iostream>
#include <vector>
#include <string>

class SCS {
  public:
    int findSCSLength(const string &s1, const string &s2) {
      return findSCSLengthRecursive(s1, s2, 0, 0);
    }

  private:
    int findSCSLengthRecursive(const string &s1, const string &s2, int i1, int i2) {
      if (i1 == s1.length()) {
        return s2.length() - i2;
      }

      if (i2 == s2.length()) {
        return s1.length() - i1;
      }

      if (s1[i1] == s2[i2]) {
        return 1 + findSCSLengthRecursive(s1, s2, i1 + 1, i2 + 1);
      }

      int length1 = 1 + findSCSLengthRecursive(s1, s2, i1, i2 + 1);
      int length2 = 1 + findSCSLengthRecursive(s1, s2, i1 + 1, i2);

      return min (length1, length2);
    }
};

class SCSTopDown {
  public:
    int findSCSLength(const string &s1, const string &s2) {
      vector<vector<int>> dp(s1.length(), vector<int>(s2.length(), -1));
      return findSCSLengthRecursive(dp, s1, s2, 0, 0);
    }

  private:
    int findSCSLengthRecursive(vector<vector<int>> &dp, const string &s1, const string &s2, int i1, int i2) {
      if (i1 == s1.length()) {
        return s2.length() - i2;
      }

      if (i2 == s2.length()) {
        return s1.length() - i1;
      }

      if (dp[i1][i2] == -1) {
        if (s1[i1] == s2[i2]) {
          dp[i1][i2] = 1 + findSCSLengthRecursive(dp, s1, s2, i1 + 1, i2 + 1);
        } else {
          int length1 = 1 + findSCSLengthRecursive(dp, s1, s2, i1, i2 + 1);
          int length2 = 1 + findSCSLengthRecursive(dp, s1, s2, i1 + 1, i2);
          dp[i1][i2] = min(length1, length2);
        }
      }

      return dp[i1][i2];
    }
};

class SCSBottomUp {
  public:
    int findSCSLength(const string &s1, const string &s2) {
      vector<vector<int>> dp(s1.length() + 1, vector<int>(s2.length() + 1));

      for (int i = 0; i <= s1.length(); i++) {
        dp[i][0] = i;
      }

      for (int j = 0; j <= s2.length(); j++) {
        dp[0][j] = j;
      }

      for (int i = 1; i <= s1.length(); i++) {
        for (int j = 1; j <= s2.length(); j++) {
          if (s1[i - 1] == s2[j - 1]) {
            dp[i][j] = 1 + dp[i - 1][j - 1];
          } else {
            dp[i][j] = 1 + min(dp[i - 1][j], dp[i][j - 1]);
          }
        }
      }

      return dp[s1.length()][s2.length()];
    }
};