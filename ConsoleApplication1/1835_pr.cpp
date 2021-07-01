#include <string>
#include <vector>
#include <algorithm>

using namespace std;

bool isRight(char c, int dis, int num);

int solution_1835(int n, vector<string> data) {
    int answer = 0;
    string friends = "ACFJMNRT";

    do {
        bool check = true;
        for (string option : data) {
            char first = option[0];
            char second = option[2];
            int num = option[4] - '0';
            int diff = friends.find(first) - friends.find(second);
            int distance = abs(diff) - 1;

            if (isRight(option[3], distance, num)) continue;
            check = false;
            break;
        }
        if (check) answer++;

    } while (next_permutation(friends.begin(), friends.end()));

    return answer;
}

bool isRight(char c, int dis, int num) {
    if (c == '=') {
        return dis == num;
    }
    else if (c == '<') {
        return dis < num;
    }
    else {
        return dis > num;
    }
}