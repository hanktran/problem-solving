using namespace std;

#include <iostream>
#include <unordered_map>
#include <string>

class RequestLimiter {
  private:
    unordered_map<string, int> requests;

  public:
    bool requestApprover(int timestamp, string request) {
      if (this->requests.find(request) == this->requests.end()) {
        this->requests[request] = timestamp;
        cout << "Request Accepted\n";
        return true;
      }

      int oldTimestamp = this->requests[request];
      if (timestamp - oldTimestamp >= 5) {
        this->requests[request] = timestamp;
        cout << "Request Accepted\n";
        return true;
      } else {
        cout << "Request Rejected\n";
        return false;
      }
    }
};

int main() {
  RequestLimiter obj;

  obj.requestApprover(1, "send_message");
  obj.requestApprover(2, "block");
  obj.requestApprover(3, "send_message");
  obj.requestApprover(8, "block");
  obj.requestApprover(10, "send_message");
  obj.requestApprover(11, "send_message");

  return 0;
}