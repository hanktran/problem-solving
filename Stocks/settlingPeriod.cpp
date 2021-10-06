#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int leastTime(vector<char> &stocks, int sTime) {
  vector<int> frequencies(26);
  for (int s : stocks) {
    frequencies[s - 'A']++;
  }

  sort(frequencies.begin(), frequencies.end());

  int fMax = frequencies[25];
  int idleIntervals = (fMax - 1) * sTime;

  for (int i = frequencies.size() - 2; i >= 0 && idleIntervals > 0; i--) {
    idleIntervals -= min(fMax - 1, frequencies[i]);
  }

  if (idleIntervals > 0) {
    return idleIntervals + stocks.size();
  } else {
    return stocks.size();
  }
}

int main() {
  vector<char> transaction = {'A', 'A', 'A', 'T', 'T', 'M', 'A'};
  int k = 2;
  cout << "Time requires to trade all stocks: " << to_string(leastTime(transaction, k)) << " intervals" << endl;
}