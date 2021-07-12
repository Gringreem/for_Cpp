#include <string>
#include <vector>

using namespace std;

vector<int> solution_81302(vector<vector<string>> places) {
    vector<int> answer;

    for (int i = 0;i < places.size();i++) {
        int check = 1;
        vector<string> room = places[i];

        room.push_back("XXXXXXX");
        room.push_back("XXXXXXX");

        for (int j = 0;j < 5;j++) {
            room[j] += "XX";
            if (j == 0) {
                for (int k = 0;k < 5;k++) {
                    if (room[j][k] == 'P') {
                        if (room[j + 1][k] == 'P' || room[j][k + 1] == 'P') {
                            check = 0;
                            break;
                        }
                        else if (room[j + 2][k] == 'P' && room[j + 1][k] != 'X') {
                            check = 0;
                            break;
                        }
                        else if (room[j][k + 2] == 'P' && room[j][k + 1] != 'X') {
                            check = 0;
                            break;
                        }
                        else if (room[j + 1][k + 1] == 'P' && (room[j + 1][k] != 'X' || room[j][k + 1] != 'X')) {
                            check = 0;
                            break;
                        }
                    }
                }
            }
            else {

                for (int k = 0;k < 5;k++) {
                    if (room[j][k] == 'P') {
                        if (room[j + 1][k] == 'P' || room[j][k + 1] == 'P') {
                            check = 0;
                            break;
                        }
                        else if (room[j + 2][k] == 'P' && room[j + 1][k] != 'X') {
                            check = 0;
                            break;
                        }
                        else if (room[j][k + 2] == 'P' && room[j][k + 1] != 'X') {
                            check = 0;
                            break;
                        }
                        else if (room[j + 1][k + 1] == 'P' && (room[j + 1][k] != 'X' || room[j][k + 1] != 'X')) {
                            check = 0;
                            break;
                        }
                        else if (room[j - 1][k + 1] == 'P' && (room[j-1][k] != 'X' || room[j][k+1] != 'X')) {
                            check = 0;
                            break;
                        }
                    }
                }
            }
        }

        answer.push_back(check);
    }

    return answer;
}