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
        V[a[i]]++;// a�� �ִ� ���� ���� Ȯ��
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

    return answer * 2; // ���� ���� 2���� ��� -> ũ�� 4���� ����
}