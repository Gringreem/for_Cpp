#include <string>
#include <vector>
#include <map>
#include <algorithm>
#include <sstream>

using namespace std;

string solution_84325(vector<string> table, vector<string> languages, vector<int> preference) {
    string answer = "";
    map<string, int> m;

    for (int i = 0;i < languages.size();i++) {
        int like = preference[i];
        string lang = languages[i];
        for (int j = 0;j < table.size();j++) {
            vector<string> tmp;
            istringstream ss(table[j]);
            string stringBuffer;
            while (getline(ss, stringBuffer, ' ')) {
                tmp.push_back(stringBuffer);
            }

            auto n = find(tmp.begin(), tmp.end(), lang);
            if (n == tmp.end()) {
                continue;
            }
            else {
                int cnt = n - tmp.begin();
                m[tmp[0]] += like * (6 - cnt);
            }
        }
    }
    int max = 0;

    for (auto it : m) {
        if (it.second > max) {
            max = it.second;
            answer = it.first;
        }
    }

    return answer;
}