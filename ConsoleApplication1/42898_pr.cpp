#include <string>
#include <vector>

using namespace std;

int solution_42898(int m, int n, vector<vector<int>> puddles) {
    vector<vector<int>> map(n + 1, vector<int>(m + 1, 1));

    for (int i = 0; i < puddles.size(); i++) {
        int y = puddles[i][1];
        int x = puddles[i][0];

        map[y][x] = 0;

        if (x == 1) {
            for (int j = y; j <= n; j++)
                map[j][1] = 0;
        }

        if (y == 1) {
            for (int j = x; j <= m; j++)
                map[1][j] = 0;
        }
    }

    for (int y = 2; y <= n; y++) {
        for (int x = 2; x <= m; x++) {
            if (map[y][x] == 0)
                continue;

            map[y][x] = (map[y - 1][x] + map[y][x - 1]) % 1000000007;
        }
    }

    return map[n][m];
}