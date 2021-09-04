using namespace std;

#include <iostream>
#include <string>
#include <vector>

class SPM {
  public:
    int findSPMCount(const string &str, const string &pat) {
      return findSPMCountRecursive(str, pat, 0, 0);
    }

  private:
    int findSPMCountRecursive(const string &str, const string &pat, int strIndex, int patIndex) {
      if (patIndex == pat.length()) {
        return 1;
      }

      if (strIndex == str.length()) {
        return 0;
      }

      int c1 = 0;
      if (str[strIndex] == pat[patIndex]) {
        c1 = findSPMCountRecursive(str, pat, strIndex + 1, patIndex + 1);
      }

      int c2 = findSPMCountRecursive(str, pat, strIndex + 1, patIndex);

      return c1 + c2;
    }
};

class SPMTopDown {
  public:
    int findSPMCount(const string &str, const string &pat) {
      vector<vector<int>> dp(str.length(), vector<int>(path.length(), -1));
      return findSPMCountRecursive(dp, str, pat, 0, 0);
    }

  private:
    int findSPMCountRecursive(vector<vector<int>> &dp, const string &str, const string &pat, int strIndex, int patIndex) {
      if (patIndex == pat.length()) {
        return 1;
      }

      if (strIndex == str.length()) {
        return 0;
      }

      if (dp[strIndex][patIndex] == -1) {
        int c1 = 0
        if (str[strIndex] == pat[patIndex]) {
          c1 = findSPMCountRecursive(dp, str, pat, strIndex + 1, patIndex + 1);
        }
        int c2 = findSPMCountRecursive(dp, str, pat, strIndex + 1, patIndex);

        dp[strIndex][patIndex] = c1 + c2;
      }

      return dp[strIndex][patIndex];
    }
};

class SPMBottomUp {
  public:
    int findSPMCount(const string &str, const string &pat) {
      if (pat.length() == 0) {
        return 1;
      }

      if (str.length() == 0 || pat.length() > str.length()) {
        return 0;
      }

      vector<vector<int>> dp(str.length() + 1, vector<int>(pat.length() + 1));

      for (int i = 0; i <= str.length(); i++) {
        dp[i][0] = 1;
      }

      for (int strIndex = 1; strIndex <= str.length(); strIndex++) {
        for (int patIndex = 1; patIndex <= pat.length(); patIndex++) {
          if (str[strIndex] == pat[patIndex]) {
            dp[strIndex][patIndex] = dp[strIndex - 1][patIndex - 1];
          }
          dp[strIndex][patIndex] += dp[strIndex - 1][patIndex];
        }
      }

      return dp[str.length()][pat.length()];
    }
};