#include <string>
#include <vector>
#define MAX 501

using namespace std;

int answer, grade, a[MAX][MAX], d[MAX][MAX];

int max(int a, int b) {
    return a > b ? a : b;
}

int solution_43105(vector<vector<int>> triangle) {
    answer = d[0][0] = triangle[0][0];

    grade = triangle.size();

    for (int i = 1;i < grade;i++) {
        for (int j = 0;j <= i;j++) {
            if (j == 0) {
                d[i][j] = d[i - 1][j] + triangle[i][j];
            }
            else if (j == i) {
                d[i][j] = d[i - 1][j - 1] + triangle[i][j];
            }
            else {
                d[i][j] = max(d[i - 1][j], d[i - 1][j - 1]) + triangle[i][j];
            }
            answer = max(answer, d[i][j]);
        }
    }

    return answer;
}