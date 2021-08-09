#include <string>
#include <vector>

using namespace std;

int max(int a, int b) {
    return a > b ? a : b;
}

int solution_70130(vector<int> a) {
    int answer = -1;
    vector<int> V(a.size() + 1, 0);

    for (int i = 0;i < a.size();i++) {
        V[a[i]]++;// a에 있는 원소 개수 확인
    }

    for (int i = 0;i < V.size();i++) {
        if (V[i] == 0) {
            continue;
        }
        if (V[i] <= answer) {
            continue;
        }
        int cnt = 0;

        for (int j = 0;j < a.size() - 1;j++) {
            if (a[j] != i && a[j + 1] != i) {
                continue;
            }
            if (a[j] == a[j + 1]) {
                continue;
            }
            cnt++;
            j++;
        }
        answer = max(answer, cnt);
    }

    return answer * 2; // 같은 원소 2개일 경우 -> 크기 4까지 가능
}