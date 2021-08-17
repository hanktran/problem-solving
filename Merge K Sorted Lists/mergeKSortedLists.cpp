using namespace std;

#include <iostream>
#include <queue>
#include <vector>

class ListNode {
  public:
    int value = 0;
    ListNode *next;

    ListNode(int value) {
      this->value = value;
      this.next = nullptr;
    }
};

class MergeKSortedLists {
  public:
    struct valueCompare {
      bool operator()(const ListNode *x, const ListNode *y) {
        return x->value > y->value;
      }
    };

    static ListNode *merge(const vector<ListNode *> &lists) {
      priority_queue<ListNode *, vector<ListNode *>, valueCompare> minHeap;
      for (auto root : lists) {
        if (root != nullptr) {
          minHeap.push(root);
        }
      }

      ListNode *resultHead = nullptr, *resultTail = nullptr;
      while (!minHeap.empty()) {
        ListNode *node = minHeap.top();
        minHeap.pop();
        if (resultHead == nullptr) {
          resultHead = resultTail = node;
        } else {
          resultTail->next = node;
          resultTail = resultTail->next;
        }

        if (node->next != nullptr) {
          minHeap.push(node->next);
        }
      }

      return resultHead;
    }
};