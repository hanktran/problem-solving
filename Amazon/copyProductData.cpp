using namespace std;

#include <iostream>
#include <vector>
#include <unordered_map>

class Node {
  public:
    int prod;
    Node* next;
    Node* related;
    
    Node(int prod) {
      this->prod = prod;
      this->next = nullptr;
      this->related = nullptr;
    }

    Node(int prod, Node* next, Node* related) {
      this->prod = prod;
      this->next = next;
      this->related = related;
    }

    ~Node() {
      delete this->next;
      delete this->related;
    }
};

Node* getCloneNode(Node* node, unordered_map<Node*, Node*>& visited) {
  if (node != nullptr) {
    if (visited.find(node) != visited.end()) {
      return visited[node];
    } else {
      visited[node] = new Node(node->prod);
      return visited[node];
    }
  }
  return nullptr;
}

Node* copyProductRelations(Node* head, unordered_map<Node*, Node*> &visited) {
  if (head == nullptr) {
    return head;
  }

  Node* oldNode = head;

  Node* newNode = new Node(oldNode->prod);
  visited[oldNode] = newNode;

  while (oldNode != nullptr) {
    newNode->related = getCloneNode(oldNode->related, visited);
    newNode->next = getCloneNode(oldNode->next, visited);

    oldNode = oldNode->next;
    newNode = newNode->next;
  }

  return visited[head];
}