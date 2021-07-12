#include <vector>
#include <algorithm>
#include <queue>

using namespace std;

bool map[100][100];
int dx[] = { 0,0,1,-1 };
int dy[] = { 1,-1,0,0 };

int check(vector<vector<int>> picture, int x, int y, int m, int n) {
    int k = picture[x][y];
    int size = 1;
    queue<pair<int, int>> q;

    q.push(make_pair(x, y));
    map[x][y] = true;

    while (!q.empty()) {
        int a = q.front().first;
        int b = q.front().second;
        q.pop();

        for (int i = 0;i < 4;i++) {
            int nx = a + dx[i];
            int ny = b + dy[i];
            if (nx >= 0 && ny >= 0 && nx < m && ny < n) {
                if (picture[nx][ny] == k && !map[nx][ny]) {
                    map[nx][ny] = true;
                    q.push(make_pair(nx, ny));
                    size++;
                }
            }
        }
    }
    return size;
}

vector<int> solution_1829(int m, int n, vector<vector<int>> picture) {
    int number_of_area = 0;
    int max_size_of_one_area = 0;

    vector<int> answer(2);

    for (int i = 0;i < m;i++) {
        for (int j = 0;j < n;j++) {
            map[i][j] = false;
        }
    }
    for (int i = 0;i < m;i++) {
        for (int j = 0;j < n;j++) {
            if (picture[i][j] != 0 && !map[i][j]) {
                int size = check(picture, i, j, m, n);
                if (size > max_size_of_one_area) {
                    max_size_of_one_area = size;
                }
                number_of_area++;
            }
        }
    }

    answer[0] = number_of_area;
    answer[1] = max_size_of_one_area;
    
    return answer;
}