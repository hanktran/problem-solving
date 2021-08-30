using namespace std;

#include <iostream>
#include <string>
#include <vector>

class LPS {
  public:
    int findLPSLength(const string &st) {
      return findLPSLengthRecursive(st, 0, st.length() - 1);
    }

  private:
    int findLPSLengthRecursive(const string &st, int startIndex, int endIndex) {
      if (startIndex > endIndex) {
        return 0;
      }

      if (startIndex == endIndex) {
        return 1;
      }

      int c1 = 0;
      if (st[startIndex] == st[endIndex]) {
        int remainingLength = endIndex - startIndex - 1;
        if (remainingLength == findLPSLengthRecursive(st, startIndex + 1, endIndex - 1)) {
          c1 = remainingLength + 2;
        }
      }

      int c2 = findLPSLengthRecursive(st, startIndex + 1, endIndex);
      int c3 = findLPSLengthRecursive(st, startIndex, endIndex - 1);
      return max(c1, max(c2, c3));
    }
};

class LPSTopDown {
  public:
    int findLPSLength(const string &st) {
      vector<vector<int>> dp(st.length(), vector<int>(st.length(), -1));
      return findLPSLengthRecursive(dp, st, 0, st.length() - 1);
    }

  private:
    int findLPSLengthRecursive(vector<vector<int>> &dp, const string &st, int startIndex, int endIndex) {
      if (startIndex > endIndex) {
        return 0;
      }

      if (startIndex == endIndex) {
        return 1;
      }

      if (dp[startIndex][endIndex] == -1) {
        int c1 = 0;
        if (st[startIndex] == st[endIndex]) {
          int remainingLength = endIndex - startIndex - 1;
          if (remainingLength == findLPSLengthRecursive(dp, st, startIndex + 1, endIndex - 1)) {
            c1 = remainingLength + 2;
          }
        }

        int c2 = findLPSLengthRecursive(dp, st, startIndex + 1, endIndex);
        int c3 = findLPSLengthRecursive(dp, st, startIndex, endIndex - 1);
        dp[startIndex][endIndex] = max(c1, max(c2, c3));
      }

      return dp[startIndex][endIndex];
    }
};

class LPSBottomUp {
  public:
    int findLPSLength(const strng &st) {
      vector<vector<bool>> dp(st.length(), vector<bool>(st.length()));

      for (int i = 0; i < st.length(); i++) {
        dp[i][i] = true;
      }

      int maxLength = 1;
      for (int startIndex = st.length() - 1; startIndex >= 0; startIndex--) {
        for (int endIndex = startIndex + 1; endIndex < st.length(); endIndex++) {
          if (st[startIndex] == st[endIndex]) {
            if (endIndex - startIndex == 1 || dp[startIndex + 1][endIndex - 1]) {
              dp[startIndex][endIndex] = true;
              maxLength = max(maxLength, endIndex - startIndex + 1);
            }
          }
        }
      }

      return maxLength;
    }
};