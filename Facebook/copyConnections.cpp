using namespace std;

#include <iostream>
#include <vector>
#include <unordered_map>
#include <unordered_set>
#include <algorithm>
#include <random>
#include <utility>

class Node {
  public:
    int data;
    vector<Node*> friends;

    Node(int d) {
      data = d;
    }

    ~Node() {
      for (int i = 0; i < friends.size(); i++) {
        delete friends[i];
      }

      friends.clear();
    }
};

void shuffle(vector<pair<int, int>> &vec) {
  random_device rd;
  default_random_engine rng( rd() );
  shuffle(vec.begin(), vec.end(), rng);
}

class CloneGraph {
  public:
    static vector<Node*> createTestGraphDirected(int nodes_count, int edges_count) {
      vector<Node*> vertices;
      for (int i = 0; i < nodes_count; i++) {
        vertices.push_back(new Node(i));
      }

      vector<pair<int, int>> all_edges;
      for (int i = 0; i < vertices.size(); i++) {
        for (int j = i + 1; j < vertices.size(); j++) {
          all_edges.push_back(make_pair(i, j));
        }
      }

      shuffle(all_edges);

      for (int i = 0; i < edges_count && i < all_edges.size(); i++) {
        pair<int, int> edge = all_edges[i];
        vertices[edge.first]->friends.push_back(vertices[edge.second]);
        vertices[edge.second]->friends.push_back(vertices[edge.first]);
      }

      return vertices;
    }

    static void printGraph(vector<Node*> vertices) {
      for (auto n : vertices) {
        cout << to_string(n->data) + ": {";
        for (auto t : n->friends) {
          cout << to_string(t->data) + " ";
        }
        cout << "}" << endl;
      }
    }

    static void printGraph(Node* root, unordered_set<Node*> &visited_nodes) {
      if (root == nullptr || visited_nodes.find(root) != visited_nodes.end()) {
        return;
      }

      visited_nodes.insert(root);

      cout << to_string(root->data) + ": {";
      for (auto n : root->friends) {
        cout << to_string(n->data) + " ";
      }
      cout << "}" << endl;

      for (auto n : root->friends) {
        printGraph(n, visited_nodes);
      }
    }

    static void printGraph(Node* root) {
      unordered_set<Node*> visited_nodes;
      printGraph(root, visited_nodes);
    }

    static bool areGraphsEqualRec(Node* root1, Node* root2, unordered_set<Node*> &visited) {
      if (root1 == nullptr && root2 == nullptr) {
        return true;
      }

      if (root1 == nullptr || root2 == nullptr) {
        return false;
      }

      if (root1->data != root2->data) {
        return false;
      }

      if (root1->friends.size() != root2->friends.size()) {
        return false;
      }

      for (Node* nbr1 : root1->friends) {
        bool found = false;
        for (Node* nbr2 : root2->friends) {
          if (nbr1->data == nbr2->data) {
            if (visited.find(nbr1) != visited.end()) {
              visited.insert(nbr1);
              areGraphsEqualRec(nbr1, nbr2, visited);
            }
            found = true;
            break;
          }
        }

        if (!found) {
          return false;
        }
      }

      return true;
    }
};

Node* cloneRec(Node* root, unordered_map<Node*, Node*> &nodesCompleted) {
  if (root == nullptr) {
    return nullptr;
  }

  Node* newNode = new Node(root->data);
  nodesCompleted[root] = newNode;

  for (auto p : root->friends) {
    Node* x = nodesCompleted[p];
    if (x == nullptr) {
      newNode->friends.push_back(cloneRec(p, nodesCompleted));
    } else {
      newNode->friends.push_back(x);
    }
  }

  return newNode;
}

Node* clone(Node* root) {
  unordered_map<Node*, Node*> nodesCompleted;
  return cloneRec(root, nodesCompleted);
}

int main() {
  vector<Node*> vertices = CloneGraph::createTestGraphDirected(7, 18);

  CloneGraph::printGraph(vertices[0]);

  Node* cp = clone(vertices[0]);
  cout << endl;
  cout << "After copy." << endl;
  CloneGraph::printGraph(cp);

  unordered_set<Node*> set;
  cout << boolalpha << CloneGraph::areGraphsEqualRec(vertices[0], cp, set) << endl;
}