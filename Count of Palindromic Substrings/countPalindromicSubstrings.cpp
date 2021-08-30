using namespace std;

#include <iostream>
#include <string>
#include <vector>

class CPS {
  public:
    int findCPS(const string &st) {
      vector<vector<bool>> dp(st.length(), vector<bool>(st.length()));
      int count = 0;

      for (int i = 0; i < st.length(); i++) {
        dp[i][i] = true;
        count ++;
      }

      for (int startIndex = st.length() - 1; startIndex >= 0; startIndex --) {
        for (int endIndex = startIndex + 1; endIndex < st.length(); endIndex++) {
          if (st[startIndex] == st[endIndex]) {
            if (endIndex - startIndex == 1 || dp[startIndex + 1][endIndex - 1]) {
              dp[startIndex][endIndex] = true;
              count++;
            }
          }
        }
      }

      return count;
    }
};