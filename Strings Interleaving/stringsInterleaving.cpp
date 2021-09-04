using namespace std;

#include <iostream>
#include <string>
#include <vector>
#include <unordered_map>

class SI {
  public:
    bool findSI(const string &m, const string &n, const string &p) {
      return findSIRecursive(m, n, p, 0, 0, 0);
    }

  private:
    bool findSIRecursive(const string &m, const string &n, const string &p, int mIndex, int nIndex, int pIndex) {
      if (mIndex == m.length() && nIndex == n.length() && pIndex == p.length()) {
        return true;
      }

      if (pIndex == p.length()) {
        return false;
      }

      bool b1 = false, b2 = false;
      if (mIndex < m.length() && m[mIndex] == p[pIndex]) {
        b1 = findSIRecursive(m, n, p, mIndex + 1, nIndex, pIndex + 1);
      }

      if (nIndex < n.length() && n[nIndex] == p[pIndex]) {
        b2 = findSIRecursive(m, n, p, mIndex, nIndex + 1, pIndex + 1);
      }

      return b1 || b2;
    }
};

class SITopDown {
  public:
    bool findSI(const string &m, const string &n, const string &p) {
      unordered_map<string, bool> dp;
      return findSIRecursive(dp, m, n, p, 0, 0, 0);
    }

  private:
    bool findSIRecursive(unorderd_map<string, bool> &dp, const string &m, const string &n, const string &p, int mIndex, int nIndex, int pIndex) {
      if (mIndex == m.length() && nIndex == n.length() && pIndex == p.length()) {
        return true;
      }

      if (pIndex == p.length()) {
        return false;
      }

      string subProblemKey = to_string(mIndex) + "-" + to_string(nIndex) + "-" + to_string(pIndex);
      if (dp.find(subProblemKey) == dp.end()) {
        bool b1 = false, b2 = false;
        if (mIndex < m.length() && m[mIndex] == p[pIndex]) {
          b1 = findSIRecursive(dp, m, n, p, mIndex + 1, nIndex, pIndex + 1);
        }

        if (nIndex < n.length() && n[nIndex] == p[pIndex]) {
          b2 = findSIRecursive(dp, m, n, p, mIndex, nIndex + 1, pIndex + 1);
        }

        dp.emplace(subProblemKey, b1 || b2);
      }

      return dp[subProblemKey];
    }
};

class SIBottomUp {
  public:
    bool findSI(const string &m, const string &n, const string &p) {
      vector<vector<bool>> dp(m.length() + 1, vector<bool>(n.length() + 1));

      if (m.length() + n.length() != p.length()) {
        return false;
      }

      for (int mIndex = 0; mIndex <= m.length(); mIndex++) {
        for (int nIndex = 0; nIndex <= n.length(); nIndex++) {
          if (mIndex == 0 && nIndex == 0) {
            dp[mIndex][nIndex] = true;
          } else if (mIndex == 0 && n[nIndex - 1] == p[mIndex + nIndex - 1]) {
            dp[mIndex][nIndex] = dp[mIndex][nIndex - 1];
          } else if (nIndex == 0 && m[mIndex - 1] == p[mIndex + nIndex - 1]) {
            dp[mIndex][nIndex] = dp[mIndex - 1][nIndex];
          } else {
            if (mIndex > 0 && m[mIndex - 1] == p[mIndex + nIndex - 1]) {
              dp[mIndex][nIndex] = dp[mIndex - 1][nIndex];
            }

            if (nIndex > 0 && n[nIndex - 1] == p[mIndex + nIndex - 1]) {
              dp[mIndex][nIndex] = dp[mIndex][nIndex] || dp[mIndex][nIndex - 1];
            }
          }
        }
      }

      return dp[m.length()][n.length()];
    }
};