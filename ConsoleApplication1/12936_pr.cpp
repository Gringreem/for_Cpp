#include <string>
#include <vector>
#include <set>

using namespace std;

vector<int> solution_12936(int n, long long k) {
    vector<int> answer;

    set<int> s;
    vector<long long>fact(n + 1);
    long long a = 1;
    for (long long i = 1;i <= n;i++) {
        s.insert(i);
        a *= i;
        fact[i] = a;
    }

    k--;

    vector<int> check(n, 0);
    for (int i = n;i >= 2;i--) {
        if (k >= fact[i - 1]) {
            long long q = k / fact[i - 1];
            k -= q * fact[i - 1];
            check[i - 1] = q;
        }
    }

    for (int i = n;i >= 1;i--) {
        auto it = s.begin();
        if (check[i - 1] != 0) {
            advance(it, check[i - 1]);
        }
        answer.push_back(*it);
        s.erase(it);
    }

    return answer;
}