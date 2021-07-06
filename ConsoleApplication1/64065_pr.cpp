#include <string>
#include <vector>
#include <map>
#include <algorithm>

using namespace std;

vector<int> solution_64065(string s) {
   
    map<int ,int> mp;
    string str;

    for (int i = 2; i < s.size() - 1; i++) {
        if (s[i] >= '0' && s[i] <= '9') {
            str += s[i];
        }
        else {
            if (str.size()) {
                mp[stoi(str)]++;
                str.clear();
            }
        }
    }

    vector<int> answer(mp.size());
    
    for (auto a : mp) {
        answer[abs(int(a.second - mp.size()))] = a.first;
    }
    
    return answer;
}