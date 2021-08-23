using namespace std;

#include <iostream>
#include <queue>
#include <string>
#include <unordered_map>
#include <vector>

class AlienDictionary {
  public:
    static string findOrder(const vector<string> &words) {
      if (words.empty()) {
        return "";
      }

      unordered_map<char, int> inDegree;
      unordered_map<char, vector<char>> graph;
      for (auto word : words) {
        for (char character : word) {
          inDegree[character] = 0;
          graph[character] = vector<char>();
        }
      }

      for (int i = 0; i < words.size() - 1; i++) {
        string w1 = words[i], w2 = words[i + 1];
        for (int j = 0; j < min(w1.length(), w2.length()); j++) {
          char parent = w1[j], child = w2[j];
          if (parent != child) {
            graph[parent].push_back(child);
            inDegree[child]++;
            break;
          }
        }
      }

      queue<char> sources;
      for (auto entry : inDegree) {
        if (entry.second == 0) {
          sources.push(entry.first);
        }
      }

      string sortedOrder;
      while (!sources.empty()) {
        char vertex = sources.front();
        sources.pop();
        sortedOrder += vertex;
        vector<char> children = graph[vertex];
        for (char child : children) {
          inDegree[child]--;
          if (inDegree[child] == 0) {
            sources.push(child);
          }
        }
      }

      if (sortedOrder.length() != inDegree.size()) {
        return "";
      }

      return sortedOrder;
    }
};

int main(int argc, char *argv[]) {
  string result = AlienDictionary::findOrder(vector<string>{"ba", "bc", "ac", "cab"});
  cout << "Character order: " << result << endl;

  result = AlienDictionary::findOrder(vector<string>{"cab", "aaa", "aab"});
  cout << "Character order: " << result << endl;

  result = AlienDictionary::findOrder(vector<string>{"ywx", "wz", "xww", "xz", "zyy", "zwz"});
  cout << "Character order: " << result << endl;
}