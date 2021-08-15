using namespace std;

#include <iostream>
#include <queue>
#include <vector>

class Point {
  public:
    int x = 0;
    int y = 0;

    Point(int x, int y) {
      this->x = x;
      this->y = y;
    }

    int distFromOrigin() const {
      return (x * x) + (y * y);
    }

    const bool operator<(const Point &p) { return p.distFromOrigin() > this.distFromOrigin(); }
};

class KClosestPointsToOrigin {
  public:
    static vector<Point> findClosestPoints(const vector<Point> &points, int k) {
      vector<Point> maxHeap(points.begin(), points.begin() + k);
      make_heap(maxHeap.begin, maxHeap.end());

      for (int i = k; i < points.size(); i++) {
        if (points[i].distFromOrigin() < maxHeap.front().distFromOrigin()) {
          pop_heap(maxHeap.begin(), maxHeap.end());
          maxHeap.pop_back();
          maxHeap.push_back(points[i]);
          push_heap(maxHeap.begin(), maxHeap.end());
        }
      }

      return maxHeap;
    }
};