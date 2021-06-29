#include <string>
#include <vector>
#include <map>

using namespace std;

string solution_42576(vector<string> participant, vector<string> completion) {
    
    map<string, int> m;
    
    for (auto c : completion) {
        m[c]++;
    }

    for (auto p : participant) {
        m[p]--;
        if (m[p] < 0) {
            return p;
        }
    }

}