#include <string>
#include <vector>
#include <algorithm>

using namespace std;

long long solution_67257(string expression) {
    long long answer = 0;

    vector<long long> check;
    string num = "";
    vector<char> option, order; // option : 중복제거된 연산자, order : 모든 연산자

    for (int i = 0;i < expression.size();i++) {
        if (expression[i] == '+' || expression[i] == '-' || expression[i] == '*') {
            check.push_back(stoi(num));
            num = "";
            if (find(option.begin(), option.end(), expression[i]) == option.end()) {
                option.push_back(expression[i]);
            }
            order.push_back(expression[i]);
        }
        else {
            num += expression[i];
        }
    }
    check.push_back(stoi(num));
    sort(option.begin(), option.end());

    do {
        vector<long long> temp = check;
        vector<char> temp_order = order;

        for (int i = 0;i < option.size();i++) {
            for (int j = 0;j < temp_order.size();j++) {
                if (temp_order[j] == option[i]) {
                    if (temp_order[j] == '+') {
                        temp[j] = temp[j] + temp[j + 1];
                    }
                    else if (temp_order[j] == '-') {
                        temp[j] = temp[j] - temp[j + 1];
                    }
                    else if (temp_order[j] == '*') {
                        temp[j] = temp[j] * temp[j + 1];
                    }

                    temp.erase(temp.begin() + j + 1);
                    temp_order.erase(temp_order.begin() + j);
                    j--;
                }
            }
        }
        if (answer < abs(temp[0])) {
            answer = abs(temp[0]);
        }

    } while (next_permutation(option.begin(), option.end())); // 우선순위를 변경하면서 반복
    
    return answer;
}