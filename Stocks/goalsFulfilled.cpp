#include <iostream>
#include <unordered_map>
#include <vector>

using namespace std;

bool goalsFulfilled(vector<int> trades) {
  unordered_map<int, int> frequencyMap;
  unordered_map<int, int> imaginedMap;

  for (int n : trades) {
    frequencyMap[n] = 1;
  }

  for (int n : trades) {
    if (frequencyMap[n] == 0) {
      continue;
    } else if ((imaginedMap.find(n) != imaginedMap.end()) && imaginedMap[n] > 0) {
      imaginedMap[n] = imaginedMap.find(n) == imaginedMap.end() ? -1 : imaginedMap[n] - 1;
      imaginedMap[n + 1] = imaginedMap.find(n) == imaginedMap.end() ? -1 : imaginedMap[n] + 1;
    } else if ((frequencyMap.find(n + 1) != frequencyMap.end()) && (frequencyMap.find(n + 2) != frequencyMap.end()) && frequencyMap[n + 1] > 0 && frequencyMap[n + 2] > 0) {
      frequencyMap[n + 1] = frequencyMap.find(n + 1) == frequencyMap.end() ? -1 : frequencyMap[n + 1] - 1;
      frequencyMap[n + 2] = frequencyMap.find(n + 2) == frequencyMap.end() ? -1 : frequencyMap[n + 2] - 1;
      imaginedMap[n + 3] = frequencyMap.find(n + 2) == frequencyMap.end() ? 1 : frequencyMap[n + 2] + 1;
    } else {
      return false;
    }
    frequencyMap[n] = frequencyMap.find(n) == frequencyMap.end() ? -1 : frequencyMap[n] - 1;
  }

  return true;
}

int main() {
  vector<int> trades = {1, 2, 3, 3, 4, 4, 5, 5};

  if (!goalsFulfilled(trades)){
    cout << "The goals have not been fulfilled!";
  } else {
    cout << "The goals have been fulfilled!";
  }
  return 0;
}