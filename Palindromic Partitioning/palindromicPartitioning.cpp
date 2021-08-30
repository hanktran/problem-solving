using namespace std;

#include <iostream>
#include <string>
#include <vector>

class MPP {
  public:
    int findMPPCuts(const string &st) {
      return this->findMPPCutsRecursive(st, 0, st.length() - 1);
    }

  private:
    int findMPPCutsRecursive(const string &st, int startIndex, int endIndex) {
      if (startIndex >= endIndex || isPalindrome(st, startIndex, endIndex)) {
        return 0;
      }

      int minimumCuts = endIndex - startIndex;
      for (int i = startIndex; i <= endIndex; i++) {
        if (isPalindrome(st, startIndex, i)) {
          minimumCuts = min(minimumCuts, 1 + findMPPCutsRecursive(st, i + 1, endIndex));
        }
      }

      return minimumCuts;
    }

    bool isPalindrome(const string &st, int x, int y) {
      while (x < y) {
        if (st[x++] != st[y--]) {
          return false;
        }
      }

      return true;
    }
};

class NPPTopDown {
  public:
    int findMPPCuts(const string &st) {
      vector<vector<int>> dp(st.length(), vector<int>(st.length(), -1));
      vector<vector<int>> dpIsPalindrome(st.length(), vector<int>(st.length() , -1));
      return this->findMPPCutsRecursive(dp, dpIsPalindrome, st, 0, st.length() - 1);
    }

  private:
    int findMPPCutsRecursive(vector<vector<int>> &dp, vector<vector<int>> &dpIsPalindrome, const string &st, int startIndex, int endIndex) {
      if (startIndex >= endIndex || isPalindrome(dpIsPalindrome, st, startIndex, endIndex)) {
        return 0;
      }

      if (dp[startIndex][endIndex] == -1) {
        int minimumCuts = endIndex - startIndex;
        for (int i = startIndex; i <= endIndex; i++) {
          if (isPalindrome(dpIsPalindrome, st, startIndex, i)) {
            minimumCuts = min(minimumCuts, 1 + findMPPCutsRecursive(dp, dpIsPalindrome, st, i, endIndex));
          }
        }
        dp[startIndex][endIndex] = minimumCuts;
      }
      return dp[startIndex][endIndex];
    }

    bool isPalindrome(vector<vector<int>> &dpIsPalindrome, const string &st, int x, int y) {
      if (dpIsPalindrome[x][y] == -1) {
        dpIsPalindrome[x][y] = 1;
        int i = x, j = y;
        while (i < j) {
          if (st[i++] != st[j--]) {
            dpIsPalindrome[x][y] = 0;
            break;
          }
          if (i < j && dpIsPalindrome[i][j] == 1) {
            dpIsPalindrome[x][y] = dpIsPalindrome[i][j];
            break;
          }
        }
      }

      return dpIsPalindrome[x][y] == 1;
    }
};

class MPPBottomUp {
  public:
    int findMMPCuts(const string &st) {
      vector<vector<bool>> isPalindrome(st.length(), vector<bool>(st.length(), false));

      for (int i = 0; i < st.length(); i++) {
        isPalindrome[i][j] = true;
      }

      for (int startIndex = st.length() - 1; startIndex >= 0; startIndex--) {
        for (int endIndex = startIndex + 1; endIndex < st.length(); endIndex++) {
          if (st[startIndex] == st[endIndex]) {
            if (endIndex - startIndex == 1 || isPalindrome[startIndex + 1][endIndex - 1]) {
              isPalindrome[startIndex][endIndex] = true;
            }
          }
        }
      }

      vector<int> cuts(st.length(), 0);
      for (int startIndex = st.length() - 1; startIndex >= 0; startIndex--) {
        int minCuts = st.length();
        for (int endIndex = st.length() - 1; endIndex >= startIndex; endIndex--) {
          if (isPalindrome[startIndex][endIndex]) {
            minCuts = (endIndex == st.length() - 1) ? 0 : min(minCuts, 1 + cuts[endIndex + 1]);
          }
        }
        cuts[startIndex] = minCuts;
      }

      return cuts[0];
    }
};