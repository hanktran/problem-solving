#include <iostream>
#include <vector>
#include <unordered_map>
#include <algorithm>

using namespace std;

bool isHandOfStraights(vector<int> hand, int k) {
  if (hand.size() % k != 0) {
    return false;
  }

  unordered_map<int, int> counts;
  for (int i : hand) {
    counts[i] = counts.find(i) == counts.end() ? 1 : counts[i] + 1;
  }

  sort(hand.begin(), hand.end());
  int i = 0;
  int n = hand.size();
  while (i < n) {
    int current = hand[i];
    for (int j = 0; j < k; j++) {
      if (counts.find(current + j) == counts.end() || (counts[current + j] == 0)) {
        return false;
      }
      counts[current + j]--;
    }

    while (i < n && counts[hand[i]] == 0) {
      i++;
    }
  }
  
  return true;
}

int main() {
  vector<int> hand = {5,2,4,4,1,3,5,6,3};
  int k = 3;
  cout << boolalpha << isHandOfStraights(hand, k) << endl;
  
  vector<int> hand2 = {1,9,3,5,7,4,2,9,11};
  k = 2;
  cout << boolalpha << isHandOfStraights(hand2, k) << endl;
  return 0;
}