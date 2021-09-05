using namespace std;

#include <iostream>
#include <unordered_map>

class LinkedListNode {
  public:
    int key;
    int data;
    LinkedListNode* next;
    LinkedListNode* prev;

    LinkedListNode(int data) {
      this->data = data;
      this->next = nullptr;
      this->prev = nullptr;
    }

    LinkedListNode(int key, int data) {
      this->key = key;
      this->data = data;
      this->next = nullptr;
      this->prev = nullptr;
    }

    LinkedListNode(int data, LinkedListNode* next) {
      this->data = data;
      this->next = next;
      this->prev = nullptr;
    }

    LinkedListNode(int data, LinkedListNode* next, LinkedListNode* prev) {
      this->data = data;
      this->next = next;
      this->prev = prev;
    }

    ~LinkedListNode() {
      delete this->next;
      delete this->prev;
    }
};

class LinkedList {
  public:
    LinkedListNode* head;
    LinkedListNode* tail;
    int size;

    LinkedList() {
      this->head = nullptr;
      this->tail = nullptr;
      this->size = 0;
    }

    void insertAtHead(int key, int data) {
      LinkedListNode* newNode = new LinkedListNode(key, data);
      if (this->head == nullptr) {
        this->head = newNode;
        this->tail = newNode;
      } else {
        newNode->next = head;
        this->head->prev = newNode;
        this->head = newNode;
      }

      this->size++;
    }

    void insertAtTail(int key, int data) {
      LinkedListNode* newNode = new LinkedListNode(key, data);
      if (this->tail == nullptr) {
        this->tail = newNode;
        this->head = newNode;
        newNode->next = nullptr;
        newNode->prev = nullptr;
      } else {
        this->tail->next = newNode;
        newNode->prev = this->tail;
        newNode->next = nullptr;
        this->tail = newNode;
      }

      this->size++;
    }

    LinkedListNode* getHead() {
      return this->head;
    }

    LinkedListNode* getTail() {
      return this->tail;
    }

    LinkedListNode* removeNode(LinkedListNode* node) {
      if (node == nullptr) {
        return nullptr;
      }

      if (node->prev != nullptr) {
        node->prev->next = node->next;
      }

      if (node->next != nullptr) {
        node->next->prev = node->prev;
      }

      if (node == this->head) {
        this->head = this->head->next;
      }

      if (node == this->tail) {
        this->tail = this->tail->prev;
      }

      this->size--;
      return node;
    }

    void remove(int data) {
      auto i = this->getHead();
      while (i != nullptr) {
        if (i->data == data) {
          this->removeNode(i);
        }
        i = i->next;
      }
    }

    LinkedListNode* removeHead() {
      return this->removeNode(this->head);
    }

    LinkedListNode* removeTail() {
      return this->removeNode(this->tail);
    }
};

class LRUCache {
  int capacity;
  unordered_map<int, LinkedListNode*> cache;
  LinkedList cacheVals;

  public:
    LRUCache(int capacity) {
      this->capacity = capacity;
    }

    LinkedListNode* get(int key) {
      if (cache.find(key) == cache.end()) {
        return nullptr;
      } else {
        int value = cache[key]->data;
        cacheVals.removeNode(cache[key]);
        cacheVals.insertAtTail(key, value);
        return cacheVals.getTail();
      }
    }

    void set(int key, int value) {
      if (cache.find(key) == cache.end()) {
        if (cacheVals.size >= capacity) {
          cacheVals.insertAtTail(key, value);
          cache[key] = cacheVals.getTail();
          cache.erase(cacheVals.getHead()->key);
          cacheVals.removeHead();
        } else {
          cacheVals.insertAtTail(key, value);
          cache[key] = cacheVals.getTail();
        }
      } else {
        cacheVals.removeNode(cache[key]);
        cacheVals.insertAtTail(key, value);
        cache[key] = cacheVals.getTail();
      }
    }

    void print() {
      auto curr = cacheVals.head;
      while (curr != nullptr) {
        cout << "(" + to_string(curr->key) + "," + to_string(curr->data) + ")";
        curr = curr->next;
      }
      cout << "\n";
    }
};

int main() {
  LRUCache cache(3);
  cout << "The most recently watched titles are: (key, value)\n";
  cache.set(10, 20);
  cache.print();

  cache.set(15, 25);
  cache.print();

  cache.set(20, 30);
  cache.print();

  cache.set(25, 35);
  cache.print();

  cache.set(5, 50);
  cache.print();

  cache.get(25);
  cache.print();

  return 0;
}