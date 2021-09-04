using namespace std;

#include <iostream>
#include <string>
#include <vector>

class EditDistance {
  public:
    int findMinOperations(const string &s1, const string &s2) {
      return findMinOperationsRecursive(s1, s2, 0, 0);
    }

  private:
    int findMinOperationsRecursive(const string &s1, const string &s2, int i1, int i2) {
      if (i1 == s1.length()) {
        return s2.length() - i2;
      }

      if (i2 == s2.length()) {
        return s1.length() - i1;
      }

      if (s1[i1] == s2[i2]) {
        return findMinOperationsRecursive(s1, s2, i1 + 1, i2 + 1);
      }

      // delete
      int c1 = 1 + findMinOperationsRecursive(s1, s2, i1 + 1, i2);
      // insert
      int c2 = 1 + findMinOperationsRecursive(s1, s2, i1, i2 + 1);
      // replace
      int c3 = 1 + findMinOperationsRecursive(s1, s2, i1 + 1, i2 + 1);

      return min(c1, min(c2, c3));
    }
};

class EditDistanceTopDown {
  public:
    int findMinOperations(const string &s1, const string &s2) {
      vector<vector<int>> dp(s1.length() + 1, vector<int>(s2.length() + 1, -1));
      return findMinOperationsRecursive(dp, s1, s2, 0, 0);
    }

  private:
    int findMinOperationsRecursive(vector<vector<int>> &dp, const string &s1, const string &s2, int i1, int i2) {
      if (dp[i1][i2] == -1) {
        if (i1 == s1.length()) {
          dp[i1][i2] = s2.length() - i2;
        } else if (i2 == s2.length()) {
          dp[i1][i2] = s1.length() - i1;
        } else if (s1[i1] == s2[i2]) {
          dp[i1][i2] = findMinOperationsRecursive(dp, s1, s2, i1 +1, i2 + 1);
        } else {
          int c1 = findMinOperationsRecursive(dp, s1, s2, i1 + 1, i2);
          int c2 = findMinOperationsRecursive(dp, s1, s2, i1, i2 + 1);
          int c3 = findMinOperationsRecursive(dp, s1, s2, i1 + 1, i2 + 1);
          dp[i1][i2] = 1 + min(c1, min(c2, c3));
        }
      }

      return dp[i1][i2];
    }
};

class EditDistanceBottomUp {
  public:
    int findMinOperations(const string &s1, const string &s2) {
      vector<vector<int>> dp(s1.length() + 1, vector<int>(s2.length() + 1));

      for (int i1 = 0; i1 <= s1.length(); i1++) {
        dp[i1][0] = i1;
      }

      for (int i2 = 0; i2 <= s2.length(); i2++) {
        dp[0][i2] = i2;
      }

      for (int i1 = 1; i1 <= s1.length(); i1++) {
        for (int i2 = 1; i2 <= s2.length(); i2++) {
          if (s1[i1 - 1] == s2[i2 - 1]) {
            dp[i1][i2] = dp[i1 - 1][i2 - 1];
          } else {
            dp[i1][i2] = 1 + min(dp[i1 - 1][i2], min(dp[i1][i2 - 1], dp[i1 -1][i2 - 1]));
          }
        }
      }

      return dp[s1.length()][s2.length()];
    }
};