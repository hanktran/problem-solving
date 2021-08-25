using namespace std;

#include <iostream>
#include <limits>
#include <vector>

class CutRibbon {
  public:
    int countRibbonPieces(const vector<int> &ribbonLengths, int total) {
      int maxPieces = this->countRibbonPiecesRecursive(ribbonLengths, total, 0);
      return maxPieces == numeric_limits<int>::min() ? -1 : maxPieces;
    }

  private:
    int countRibbonPiecesRecursive(const vector<int> &ribbonLengths, int total, int currentIndex) {
      if (total == 0) {
        return 0;
      }

      if (ribbonLengths.empty() || currentIndex >= ribbonLengths.size()) {
        return numeric_limits<int>::min();
      }

      int c1 = numeric_limits<int>::min();
      if (ribbonLengths[currentIndex] <= total) {
        int result = countRibbonPiecesRecursive(ribbonLengths, total - ribbonLengths[currentIndex], currentIndex);

        if (result != numeric_limits<int>::min()) {
          c1 = result + 1;
        }
      }

      int c2 = countRibbonPiecesRecursive(ribbonLengths, total, currentIndex + 1);
      return max(c1, c2);
    }
};

class CutRibbonBottomUp {
  public:
    int countRibbonPieces(const vector<int> &ribbonLengths, int total) {
      int n = ribbonLengths.size();
      vector<vector<int>> dp(n, vector<int>(total + 1));

      for (int i = 0; i < n; i++) {
        for (int j = 0; j <= total; j++) {
          dp[i][j] = numeric_limits<int>::min();
        }
      }

      for (int i = 0; i < n; i++) {
        dp[i][0] = 0;
      }

      for (int i = 0; i < n; i++) {
        for (int t = 1; t <= total; t++) {
          if (i > 0) {
            dp[i][t] = dp[i - 1][t];
          }

          if (t >= ribbonLengths[i] && dp[i][t - ribbonLengths[i]] != numeric_limits<int>::min()) {
            dp[i][t] = max(dp[i][t], dp[i][t - ribbonLengths[i]] + 1);
          }
        }
      }

      return (dp[n - 1][total] == numeric_limits<int>::min() ? -1 : dp[n - 1][total]);
    }
};