using namespace std;

#include <iostream>
#include <unordered_map>
#include <string>
#include <vector>
#include <set>

double backtrackEvaluate(unordered_map<string, unordered_map<string, double>> &city, string currNode, string targetNode, double accSum, set<string> visited) {
  visited.insert(currNode);
  double ret = -1.0;

  unordered_map<string, double> neighbors = city[currNode];
  if (neighbors.find(targetNode) != neighbors.end()) {
    ret = accSum + neighbors[targetNode];
  } else {
    for (auto const &neighbor : neighbors) {
      string nextNode = neighbor.first;
      double val = neighbor.second;
      if (visited.find(nextNode) != visited.end()) {
        continue;
      }
      ret = backtrackEvaluate(city, nextNode, targetNode, accSum + val, visited);
      if (ret != -1.0) {
        break;
      }
    }
  }

  visited.erase(currNode);
  return ret;
}

void getTotalCost(vector<vector<string>> GMap, vector<double> pathCosts, vector<string> drivers, string user, vector<double> &results) {
  unordered_map<string, unordered_map<string, double>> city;

  for (int i = 0; i < GMap.size(); i++) {
    vector<string> checkPoints = GMap[i];
    string sourceNode = checkPoints[0];
    string destNode = checkPoints[1];
    double pathCost = pathCosts[i];

    if (city.find(sourceNode) == city.end()) {
      city[sourceNode] = unordered_map<string, double>();
    }

    if (city.find(destNode) == city.end()) {
      city[destNode] = unordered_map<string, double>();
    }

    city[sourceNode][destNode] = pathCost;
    city[destNode][sourceNode] = pathCost;
  }

  for (int i = 0; i < drivers.size(); i++) {
    string driver = drivers[i];

    if (city.find(driver) == city.end() || city.find(user) == city.end()) {
      results[i] = -1.0;
    } else {
      set<string> visited;
      results[i] = backtrackEvaluate(city, driver, user, 0, visited);
    }
  }
}

void print(vector<double> &costs) {
  int n = costs.size();
  cout << "[";
  for (int i = 0; i < n; i++) {
    cout << to_string(costs[i]);
    if (i < n - 1) {
      cout << ", ";
    }
  }
  cout << "]";
}

int main() {
    vector<vector<string>> GMap = {{"a","b"}, {"b","c"}, {"a","e"}, {"d","e"}};
    vector<double> pathCosts = {12.0,23.0,26.0,18.0};
    vector<string> drivers = {"c", "d", "e", "f"};
    string user = "a";
    vector<double> allPathCosts(drivers.size());
    getTotalCost(GMap, pathCosts, drivers, user, allPathCosts);

    print(allPathCosts);
    return 0;
}