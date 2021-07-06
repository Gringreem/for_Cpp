#include <string>
#include <vector>
#include <stack>

using namespace std;

int solution_64061(vector<vector<int>> board, vector<int> moves) {
    int answer = 0;
    int size = board.size();
    stack<int> st;

    for (int i = 0; i < moves.size(); i++) {
        int check = moves[i] - 1;
        if (st.empty()) {
            for (int j = 0;j < size;j++) {
                if (board[j][check] == 0) {
                    continue;
                }
                else {
                    st.push(board[j][check]);
                    board[j][check] = 0;
                    break;
                }
            }
        }
        else {
            int now = 0;
            for (int j = 0;j < size;j++) {
                if (board[j][check] == 0) {
                    continue;
                }
                else {
                    now = board[j][check];
                    board[j][check] = 0;
                    break;
                }
            }
            if (now == st.top()) {
                st.pop();
                answer++;
            }
            else {
                st.push(now);
            }
        }
    }


    return answer * 2;
}