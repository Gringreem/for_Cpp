#include <string>
#include <iostream>
#include <stack>

using namespace std;

bool solution_12909(string s)
{
    bool answer = false;
    stack<char> check;

    for (int i = 0;i < s.length();i++) {
        if (s[i] == '(') {
            check.push(s[i]);
        }
        else {
            if (check.empty()) {
                return false;
            }
            else {
                check.pop();
            }
        }
    }

    if (check.empty()) {
        answer = true;
    }

    return answer;
}