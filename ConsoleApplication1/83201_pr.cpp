#include <string>
#include <vector>

using namespace std;

string solution_83201(vector<vector<int>> scores) {
    string answer = "";

    for (int i = 0;i < scores.size();i++) {
        int self = scores[i][i];
        int num = scores.size();
        int min = 101;
        int max = -1;
        int sum = 0, cnt_min = 0, cnt_max = 0;

        for (int j = 0;j < scores.size();j++) {
            sum += scores[j][i];

            if (max == scores[j][i]) {
                cnt_max++;
            }
            else if (max < scores[j][i]) {
                max = scores[j][i];
                cnt_max = 1;
            }
            if (min == scores[j][i]) {
                cnt_min++;
            }
            else if (min > scores[j][i]) {
                min = scores[j][i];
                cnt_min = 1;
            }
        }

        if (cnt_max == 1 && max == self) {
            sum -= self;
            num--;
        }
        if (cnt_min == 1 && min == self) {
            sum -= self;
            num--;
        }

        int avg = sum / num;
        
        if (avg >= 90) {
            answer.push_back('A');
        }
        else if (avg >= 80) {
            answer.push_back('B');
        }
        else if (avg >= 70) {
            answer.push_back('C');
        }
        else if (avg >= 50) {
            answer.push_back('D');
        }
        else{
            answer.push_back('F');
        }
    }

    return answer;
}