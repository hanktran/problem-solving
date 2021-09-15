using namespace std;

#include <iostream>
#include <vector>
#include <queue>

class Location {
  public:
    int x;
    int y;

    Location(int x, int y) {
      this->x = x;
      this->y = y;
    }

    int distFromOrigin() {
      return (x * x) + (y * y);
    }
};

struct CompareLocation {
  bool operator()(Location &p1, Location &p2) {
    return p2.distFromOrigin() - p1.distFromOrigin();
  }
};

void findClosestDrivers(vector<Location> &locations, int k, vector<Location> &res) {
  priority_queue<Location, vector<Location>, CompareLocation> maxHeap;
  for (int i = 0; i < k; i++) {
    maxHeap.push(locations[i]);
  }

  for (int i = k; i < locations.size(); i++) {
    auto top = maxHeap.top();
    if (locations[i].distFromOrigin() < top.distFromOrigin()) {
      maxHeap.pop();
      maxHeap.push(locations[i]);
    }
  }

  while (!maxHeap.empty()) {
    res.push_back(maxHeap.top());
    maxHeap.pop();
  }
}

int main() {
  vector<Location> locations = { Location(1, 3), Location(3, 4), Location(2, -1) };
  vector<Location> result;
  findClosestDrivers(locations, 2, result);
  cout << "Here are the k drivers locations closest to the user in the Seattle area: ";
  for (auto p : result) {
    cout << "["  <<  to_string(p.x) << ", " << to_string(p.y) << "] ";
  }

  return 0;
}