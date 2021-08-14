#include <string>
#include <vector>

using namespace std;

string solution(string input) {
    string answer = "";

    int M = input[0];
    int N = input[2];
    int count = 0;
    int day = 1;

    for (int i = 0;i < input.size();i++) {
        if (input[i] == 'S') {
            if (count < N) {
                answer += '1';
                count++;
            }
            else {
                answer += '0';
            }
            i += 4;
        }
        else if (input[i] == 'N') {
            if (input[i + 2] == 'G') {
                answer += '0';
                count = 100001;
                i += 8;
            }
            else {
                answer += '-';
                count = 0;
                i += 4;
            }
        }
        else if (input[i] == 'E') {
            answer += "BYE";
            break;
        }

        answer += input[i];
    }

    return answer;
}