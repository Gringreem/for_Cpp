#include <string>
#include <vector>
#include <stack>

using namespace std;

string solution(int n, int k, vector<string> cmd) {
    string answer = "";

    int now = k;
    stack<int> st;
    int size = n;

    vector<bool> check;

    for (int i = 0; i < n; i++) {
        check.push_back(true);
    }

    for (int i = 0;i < cmd.size();i++) {
        char first = cmd[i][0];

        if (first == 'D') {
            int v = stoi(cmd[i].substr(2));
            now += v;
        }
        else if (first == 'U') {
            int v = stoi(cmd[i].substr(2));
            now -= v;
        }
        else if (first == 'C') {
            check[now] = false;
            st.push(now);
            if (now == size - 1) {
                now--;
            }
            size--;
        }
        else { // Z
            int before = st.top();
            st.pop();
            check[before] = true;
            size++;
            if (before < now) {
                now++;
            }
        }
    }

    for (int i = 0;i < check.size();i++) {
        if (check[i]) {
            answer += 'O';
        }
        else {
            answer += 'X';
        }
    }

    return answer;
}