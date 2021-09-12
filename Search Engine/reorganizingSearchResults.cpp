using namespace std;

#include <iostream>
#include <vector>
#include <unordered_map>
#include <queue>

struct Comparator {
  bool operator()(vector<int> const &a, vector<int> const &b) const {
    return a[1] < b[1];
  }
};

string reorganizeResults(string initialOrder) {
  unordered_map<char, int> map;
  for (char c : initialOrder) {
    int freq = map.find(c) == map.end() ? 1 : map[c] + 1;
    if (freq > (initialOrder.length() + 1) / 2) {
      return initialOrder;
    }
    map[c] = freq;
  }

  priority_queue<vector<int>, vector<vector<int>>, Comparator> pq;
  for (auto it : map) {
    pq.push({it.first, map[it.first]});
  }

  string result = "";
  while (!pq.empty()) {
    vector<int> first = pq.top();
    pq.pop();
    if (result.length() == 0 || first[0] != result[result.length() - 1]) {
      result += (char) first[0];
      first[1]--;
      if (first[1] > 0) {
        pq.push(first);
      }
    } else {
      vector<int> second = pq.top();
      pq.pop();
      result += (char) second[0];
      second[1]--;
      if (second[1] > 0) {
        pq.push(second);
      }
      pq.push(first);
    }
  }

  return result;
}

int main() {
  string initialOrder = "bbbnnc";
  cout << reorganizeResults(initialOrder);
}