#include <string>
#include <vector>
#include <queue>
#include <cstdlib>

using namespace std;

struct Now {
    public:
    int x, y, dir, cost;
};

int min_cost = 0x7fffffff;
int dir_x[4] = { 0, 1, 0, -1 };
int dir_y[4] = { 1, 0, -1, 0 };

int solution(vector<vector<int>> board) {
    int n = board.size();
    queue<Now> Q;
    Q.push({ 0, 0, 10, 0 });
    board[0][0] = 1;

    while (!Q.empty()) {
        Now now = Q.front();
        Q.pop();

        int cost = now.cost;

        if ((now.x == n - 1) && (now.y == n - 1)) {
            if (cost < min_cost) {
                min_cost = cost;
            }
            continue;
        }

        for (int i = 0;i < 4;i++) {
            int next_x = now.x + dir_x[i];
            int next_y = now.y + dir_y[i];

            if (next_x >= 0 && next_x < n && next_y >= 0 && next_y < n && board[next_x][next_y] != 0) {
                int new_cost = cost;

                if (i == now.dir || now.dir == 10) {
                    new_cost += 100;
                }
                else if(now.dir != i) {
                    new_cost += 600;
                }

                if (board[next_x][next_y] == 0 || board[next_x][next_y] >= new_cost) {
                    Q.push({ next_x, next_y, i, new_cost });
                    board[next_x][next_y] = new_cost;
                }
            }
        }
    }
    
    return min_cost;
}
