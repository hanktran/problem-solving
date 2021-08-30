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

      if (st[startIndex] == st[endIndex]) {
        return 2 + findLPSLengthRecursive(st, startIndex + 1, endIndex - 1);
      }

      int c1 = findLPSLengthRecursive(st, startIndex + 1, endIndex);
      int c2 = findLPSLengthRecursive(st, startIndex, endIndex - 1);
      return max(c1, c2);
    }
};

class LPSTopDown {
  public:
    int findLPSLength(const string &st) {
      vector<vector<int>> dp(st.length(), vector<int>(st.length(), -1));
      return findLPSLengthRecursive(dp, st, 0, st.length() -1);
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
        if (st[startIndex] == st[endIndex]) {
          dp[startIndex][endIndex] = 2 + findLPSLengthRecursive(dp, st, startIndex + 1, endIndex - 1);
        } else {
          int c1 = findLPSLengthRecursive(dp, st, startIndex + 1, endIndex);
          int c2 = findLPSLengthRecursive(dp, st, startIndex, endIndex - 1);
          dp[startIndex][endIndex] = max(c1, c2);
        }
      }

      return dp[startIndex][endIndex];
    }
};

class LPSBottomUp {
  public:
    int findLPSLength(const stirng &st) {
      vector<vector<int>> dp(st.length(), vector<int>(st.length(), 0));


      for (int i = 0; i < st.length(); i++) {
        dp[i][i] = 1;
      }

      for (int startIndex = st.length() - 1; startIndex >= 0; startIndex --) {
        for (int endIndex = startIndex + 1; endIndex < st.length(); endIndex++) {
          if (st[startIndex] == st[endIndex]) {
            dp[startIndex][endIndex] = 2 + dp[startIndex + 1][endIndex - 1];
          } else {
            dp[startIndex][endIndex] = max(dp[startIndex + 1][endIndex], dp[startIndex][endIndex - 1]);
          }
        }
      }

      return dp[0][st.length() - 1];
    }
};