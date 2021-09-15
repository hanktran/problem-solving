using namespace std;

#include <iostream>
#include <string>

string ones(int fare) {
  switch(fare) {
    case 1: return "One";
    case 2: return "Two";
    case 3: return "Three";
    case 4: return "Four";
    case 5: return "Five";
    case 6: return "Six";
    case 7: return "Seven";
    case 8: return "Eight";
    case 9: return "Nine";
  }
  return "";
}

string teens(int fare) {
  switch(fare) {
    case 10: return "Ten";
    case 11: return "Eleven";
    case 12: return "Twelve";
    case 13: return "Thirteen";
    case 14: return "Fourteen";
    case 15: return "Fifteen";
    case 16: return "Sixteen";
    case 17: return "Seventeen";
    case 18: return "Eighteen";
    case 19: return "Nineteen";
  }
  return "";
}

string tens(int fare) {
  switch(fare) {
    case 2: return "Twenty";
    case 3: return "Thirty";
    case 4: return "Forty";
    case 5: return "Fifty";
    case 6: return "Sixty";
    case 7: return "Seventy";
    case 8: return "Eighty";
    case 9: return "Ninety";
  }
  return "";
}

string two(int fare) {
  if (fare == 0) {
    return "";
  } else if (fare < 10) {
    return ones(fare);
  } else if (fare < 20) {
    return teens(fare);
  } else {
    int tenner = fare / 10;
    int rest = fare - tenner * 10;
    if (rest != 0) {
      return tens(tenner) + " " + ones(rest);
    } else {
      return tens(tenner);
    }
  }
}

string three(int fare) {
  int hundred = fare / 100;
  int rest = fare - hundred * 100;
  string res = "";

  if (hundred * rest != 0) {
    res = ones(hundred) + " Hundred " + two(rest);
  } else if ((hundred == 0) && (rest != 0)) {
    res = two(rest);
  } else if ((hundred != 0) && (rest == 0)) {
    res = ones(hundred) + " Hundred";
  }

  return res;
}

string fareInWords(int fare) {
  if (fare == 0) {
    return "Zero";
  }

  int billion = fare / 1000000000;
  int million = (fare - billion * 100000000) / 1000000;
  int thousand = (fare - billion * 1000000000 - million * 1000000) / 1000;
  int rest = fare - billion * 1000000000 - million * 1000000 - thousand * 1000;

  string result = "";
  if (billion != 0) {
    result = three(billion) + " Billion";
  }

  if (million != 0) {
    if (!result.empty()) {
      result += " ";
    }
    result += three(million) + " Million";
  }

  if (thousand != 0) {
    if (!result.empty()) {
      result += " ";
    }
    result += three(thousand) + " Thousand";
  }

  if (rest != 0) {
    if (!result.empty()) {
      result += " ";
    }
    result += three(rest);
  }

  return result;
}

int main() {
  int fare = 5648;
  cout << "The fare is: " + fareInWords(fare) + " dollars";
  return 0;
}