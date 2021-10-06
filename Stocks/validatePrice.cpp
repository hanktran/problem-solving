#include <iostream>
#include <string>

using namespace std;

enum STATE {START, INTEGER, DECIMAL, UNKNOWN, AFTERDECIMAL};

STATE getNextState(STATE currentState, char ch) {
  switch (currentState) {
    case START:
    case INTEGER:
      if (ch == '.') {
        return DECIMAL;
      } else if (ch >= '0' && ch <= '9') {
        return INTEGER;
      } else {
        return UNKNOWN;
      }
    case DECIMAL:
      if (ch >= '0' && ch <= '9') {
        return AFTERDECIMAL;
      } else {
        return UNKNOWN;
      }
    case AFTERDECIMAL:
      if (ch >= '0' && ch <= '9') {
        return AFTERDECIMAL;
      } else {
        return UNKNOWN;
      }
  }
  return UNKNOWN;
}

bool isPriceValid(string s) {
  if (s.empty()) {
    return true;
  }

  int i = 0;
  if (s[i] == '+' || s[i] == '-') {
    i++;
    STATE currentState = START;
    while (i < s.length()) {
      currentState = getNextState(currentState, s[i]);

      if (currentState == UNKNOWN) {
        return false;
      }

      i++;
    }

    if (currentState == DECIMAL) {
      return false;
    }

    return true;
  }

  return false;
}

int main() {
  cout << "Is the price valid +40.325? " << boolalpha << isPriceValid("+40.325") << endl;
  cout << "Is the price valid -1.1.1? " << boolalpha << isPriceValid("-1.1.1") << endl;
  cout << "Is the price valid -222? " << boolalpha << isPriceValid("-222") << endl;
  cout << "Is the price valid ++22? " << boolalpha << isPriceValid("++22") << endl;
  cout << "Is the price valid 10.1? " << boolalpha << isPriceValid("10.1") << endl;
  cout << "Is the price valid +22.22.? " << boolalpha << isPriceValid("22.22.") << endl;
  cout << "Is the price valid .100? " << boolalpha << isPriceValid(".100") << endl;
}