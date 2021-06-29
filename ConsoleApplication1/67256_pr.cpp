#include <string>
#include <vector>

using namespace std;

string solution_67256(vector<int> numbers, string hand) {
    string answer = "";
    int before_left = 10;
    int before_right = 12;

    for (int i = 0;i < numbers.size();i++) {
        int check = numbers[i];
        int check_left, check_right = 0;

        if (check == 1 || check == 4 || check == 7) {
            answer += "L";
            before_left = check;
        }
        else if (check == 3 || check == 6 || check == 9) {
            answer += "R";
            before_right = check;
        }
        else {

            if (check == 0) {
                check = 11;
            }

            check_left = abs(before_left-check);
            check_right = abs(before_right-check);
            check_left = (check_left / 3) + (check_left % 3);
            check_right = (check_right / 3) + (check_right % 3);

            if (check_left == check_right) {
                if (hand == "left") {
                    answer += "L";
                    before_left = check;
                }
                else {
                    answer += "R";
                    before_right = check;
                }
            }
            else if (check_left < check_right) {
                answer += "L";
                before_left = check;
            }
            else {
                answer += "R";
                before_right = check;
            }
        }
    }

    return answer;
}