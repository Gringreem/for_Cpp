#include <cmath>

using namespace std;

long long gcd(int x, int y) {
    long z;
    while (y != 0) {
        z = x % y;
        x = y;
        y = z;
    }
    return x;
}

long long solution_62048(int w, int h) {
    long long width = w;
    long long height = h;

    long long scale = (w + h) - gcd(w, h);

    long long answer = width * height - scale;

    return answer;
}