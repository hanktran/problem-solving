using namespace std;

#include <iostream>
#include <unordered_map>

class LinkedListNode {
  public:
    int key, val, freq;
    LinkedListNode* next;
    LinkedListNode* prev;
    LinkedListNode(int key, int value, int freq) {
      this->key = key;
      this->val = value;
      this->freq = freq;
      this->next = nullptr;
      this->prev = nullptr;
    }
};

class LinkedList {
  public:
    LinkedListNode* head;
    LinkedListNode* tail;
    LinkedList() {
      this->head = nullptr;
      this->tail = nullptr;
    }

    void append(LinkedListNode* node) {
      node->next = nullptr;
      node->prev = nullptr;
      if (this->head == nullptr) {
        this->head = node;
      } else {
        this->tail->next = node;
        node->prev = this->tail;
      }
      this->tail = node;
    }

    void deleteNode(LinkedListNode* node) {
      if (node->prev != nullptr) {
        node->prev->next = node->next;
      } else {
        this->head = node->next;
      }

      if (node->next != nullptr) {
        node->next->prev = node->prev;
      } else {
        this->tail = node->prev;
      }

      node->next = nullptr;
      node->prev = nullptr;
    }
};

class LFUStructure {
  public:
    int capacity;
    int size;
    int minFreq;
    unordered_map<int, LinkedList*> freqDict;
    unordered_map<int, LinkedListNode*> keyDict;
    LFUStructure(int capacity) {
      this->capacity = capacity;
      this->size = 0;
      this->minFreq = 0;
    }

    LinkedListNode* get(int key) {
      if (this->keyDict.find(key) == this->keyDict.end()) {
        return nullptr;
      }

      auto temp = this->keyDict[key];
      this->freqDict[temp->freq]->deleteNode(temp);
      if (this->freqDict[this->keyDict[key]->freq]->head == nullptr) {
        this->freqDict.erase(this->keyDict[key]->freq);
        if (this->minFreq == this->keyDict[key]->freq) {
          this->minFreq++;
        }
      }

      this->keyDict[key]->freq++;
      if (this->freqDict.find(this->keyDict[key]->freq) == this->freqDict.end()) {
        this->freqDict[this->keyDict[key]->freq] = new LinkedList();
      }
      this->freqDict[this->keyDict[key]->freq]->append(this->keyDict[key]);
      return this->keyDict[key];
    }

    void set(int key, int value) {
      if (this->get(key) != nullptr) {
        this->keyDict[key]->val = value;
        return;
      }

      if (this->size == this->capacity) {
        this->keyDict.erase(this->freqDict[this->minFreq]->head->key);
        this->freqDict[this->minFreq]->deleteNode(this->freqDict[this->minFreq]->head);
        if (this->freqDict[this->minFreq]->head == nullptr) {
          this->freqDict.erase(this->minFreq);
        }
        this->size--;
      }

      this->minFreq = 1;
      this->keyDict[key] = new LinkedListNode(key, value, this->minFreq);
      if (this->freqDict.find(this->keyDict[key]->freq) == this->freqDict.end()) {
        this->freqDict[this->keyDict[key]->freq] = new LinkedList();
      }
      this->freqDict[this->keyDict[key]->freq]->append(this->keyDict[key]);
      this->size++;
    }

    void print() {
      for (auto it : this->keyDict) {
        cout << "(" << it.first << ", " << it.second->val << ")";
      }
      cout << "\n";
    }
};

int main(){
    LFUStructure obj(2);
    std::cout <<"The most frequently watched titles are: (key, value)\n";
    obj.set(1, 1);
    obj.set(2, 2);
    obj.print();
    obj.get(1);
    obj.set(3, 3);
    obj.print();
    obj.get(2);
    obj.set(4, 4);

    obj.get(1);
    obj.get(3);
    obj.get(4);
    obj.print();
    return 0;
}