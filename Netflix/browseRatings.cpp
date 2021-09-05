using namespace std;

#include <iostream>
#include <stack>

class maxStack {
  int maxSize;
  stack<int> mainStack;
  stack<int> maximumStack;

  public:
    maxStack(int maxSize) {
      this->maxSize = maxSize;
    }

    int pop() {
      maximumStack.pop();
      auto top = mainStack.top();
      mainStack.pop();
      return top;
    }

    void push(int value) {
      mainStack.push(value);
      if (!maximumStack.empty() && maximumStack.top() > value) {
        maximumStack.push(maximumStack.top());
      } else {
        maximumStack.push(value);
      }
    }

    int maxRating() {
      return maximumStack.top();
    }
};

int main() {
  maxStack stack(7);
  stack.push(5);
  stack.push(0);
  stack.push(2);
  stack.push(4);
  stack.push(6);
  stack.push(3);
  stack.push(10);

  cout << "Maximum Rating: " << to_string(stack.maxRating()) << endl;

  stack.pop();
  cout << "\nAfter clicking back button\n" ;

  cout << "\nMaximum Rating: " << to_string(stack.maxRating()) << endl; 

}