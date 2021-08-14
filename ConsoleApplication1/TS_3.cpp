#include <string>
#include <vector>

using namespace std;

bool solution(string amountText) {
    bool answer = true;

    for (int i = 0;i < amountText.size();i++) {
        if ((amountText[i] >= '0' && amountText[i] <= '9') || amountText[i] == ',') {
            continue;
        }
        else {
            return false;
        }
    }

    if (amountText.size() != 1 && amountText[0] == '0') {
        return false;
    }

    int cnt = 1;
    bool check = false;
    for (int i = amountText.size() - 1;i >= 0;i--) {
        if (check) {
            if (cnt % 3 == 1 && amountText[i] != ',') {
                return false;
            }
            cnt++;
        }
        else {
            if (amountText[i] == ',') {
                check = true;
                if (cnt % 3 != 1) {
                    return false;
                }
            }
            cnt++;
        }
    }

    if (amountText[amountText.size() - 1] == ',' || amountText[0] == ',') {
        return false;
    }

    return answer;
}