#include <string>

using namespace std;

int solution_17682(string dartResult) {
    int answer = 0;
    int score = 0;
    int prev_score = 0;

    for (int i = 0;i < dartResult.size();i++) {
        if(dartResult[i] == 'S' || dartResult[i] == 'D' || dartResult[i] == 'T'){
            if (dartResult[i + 1] == '#' || dartResult[i + 1] == '*') {
                if (dartResult[i] == 'S') {
                    score = score;
                }
                else if (dartResult[i] == 'D') {
                    score = score  * score;
                }
                else {
                    score = score * score * score;
                }
            }
            else {
                if (dartResult[i] == 'S') {
                    answer += score;
                    prev_score = score;
                }
                else if (dartResult[i] == 'D') {
                    answer += score * score;
                    prev_score = score * score;
                }
                else {
                    answer += score * score * score;
                    prev_score = score * score * score;
                }
            }
        
        }
        else if (dartResult[i] == '#' || dartResult[i] == '*') {
            if (dartResult[i] == '#') {
                score = -score;
                answer += score;
                prev_score = score;
            }
            else {
                if (i == 2) {
                    score *= 2;
                    answer += score;
                    prev_score = score;
                }
                else {
                    answer -= prev_score;
                    prev_score *= 2;
                    answer += prev_score;
                    score *= 2;
                    answer += score;
                    prev_score = score;
                }
            }
        }
        else {
            if (dartResult[i + 1] == '0') {
                score = 10;
                i++;
            }
            else {
                score = dartResult[i] - '0';
            }
        }
    }

    return answer;
}