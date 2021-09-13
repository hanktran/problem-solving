using namespace std;

#include <iostream>
#include <vector>

class Node{
  public:
    int start;
    int end;
    Node* leftChild;
    Node* rightChild;
    Node(int start, int end){
      this->start = start;
      this->end = end;
    }
};

class BST {
  Node* root;

  public:
    BST(){
      this->root = nullptr;
    } 

    bool insert(int start, int end) {
      if (this->root == nullptr) {
          root = new Node(start, end);
          return true;
      }
      Node* newNode = new Node(start, end);
      return addNode(this->root, newNode);
    }

    bool addNode(Node* currentNode, Node* newNode) {
      if (newNode->start >= currentNode->end){
        if (currentNode->rightChild == nullptr){
            currentNode->rightChild = newNode;
            return true;
        }
        return addNode(currentNode->rightChild, newNode);
      } else if (newNode->end <= currentNode->start){
        if (currentNode->leftChild == nullptr){
            currentNode->leftChild = newNode;
            return true;
        }
        return addNode(currentNode->leftChild, newNode);
      } else {
        return false;
      }
    }
};

bool checkMeeting(vector<vector<int>>& meetingTimes, vector<int>& newMeeting){
    BST tree;
    for(auto meeting: meetingTimes){
        tree.insert(meeting[0], meeting[1]);
    }
    return tree.insert(newMeeting[0], newMeeting[1]);
}

int main() {
  vector<vector<int>> meetingTimes = {{1, 3}, {4, 6}, {8, 10}, {10, 12}, {13, 15}};
  
  vector<int> newMeeting = {7, 8};
  cout << boolalpha << checkMeeting(meetingTimes, newMeeting) <<endl;
  
  vector<int> newMeeting2 = {9, 11};
  cout << boolalpha << checkMeeting(meetingTimes, newMeeting2)<<endl;
  
  return 0;
}