using namespace std;

#include <iostream>
#include <vector>

class RodCutting {
  public:
    int solveRodCutting(const vector<int> &lengths, vector<int> &prices, int n) {
      if (n <= 0 || prices.empty() || prices.size() != lengths.size()) {
        return 0;
      }

      int lengthCount = lengths.size();
      vector<vector<int>> dp(lengthCount, vector<int>(n + 1));

      for (int i = 0; i < lengthCount; i++) {
        for (int len = 1; len <= n; len++) {
          int p1 = 0, p2 = 0;
          if (lengths[i] <= len) {
            p1 = prices[i] + dp[i][len - lengths[i]];
          }

          if (i > 0) {
            p2 = dp[i - 1][len];
          }

          dp[i][len] = max(p1, p2);
        }
      }

      return dp[lengthCount - 1][n];
    }
};