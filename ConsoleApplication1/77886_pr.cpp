#include <string>
#include <vector>
#include <deque>

using namespace std;

vector<string> solution_77886(vector<string> s) {
    vector<string> answer;

    for (int i = 0;i < s.size();++i) {
        deque<char> c;
        int cnt = 0;

        for (int j = 0;j < s[i].length();++j) {
            c.push_back(s[i][j]);
            int n = c.size();
            if (n >= 3 && c[n - 3] == '1' && c[n - 2] == '1' && c[n - 1] == '0') {
                ++cnt;
                c.pop_back();
                c.pop_back();
                c.pop_back();
            }
        }

        if (cnt == 0) {
            answer.push_back(s[i]);
            continue;
        }

        int idx = c.size();
        string str = "";
        bool check = false;
        for (int i = c.size() - 1;i >= 0;--i) {
            if (!check && c[i] == '1') {
                --idx;
            }
            else {
                check = true;
            }
            str = c[i] + str;
        }

        while (cnt-- > 0) {
            str.insert(idx, "110");
        }
        answer.push_back(str);
    }


    return answer;
}