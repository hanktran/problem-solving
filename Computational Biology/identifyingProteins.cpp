#include <iostream>
#include <string>

using namespace std;

bool isProtein(string sequence) {
  if (sequence.length() <= 1) {
    return true;
  } else {
    if (sequence[0] == sequence[sequence.length() - 1]) {
      return isProtein(sequence.substr(1, sequence.length() - 2));
    }
  }

  return false;
}

int main() {
  string protein = "acbca";
  cout << "Is \"" << protein << "\" a Protein? = " << boolalpha << isProtein(protein) << endl;
}