using namespace std;

long long solution_82612(int price, int money, int count)
{
    long long answer = 0;
    long long sum = 0;

    if (count % 2 == 0) {
        sum = (count + 1) * (count / 2);
    }
    else {
        sum = (count + 1) * (count / 2) + (count / 2 + 1);
    }
    answer = sum * price - money;

    if (answer < 0) {
        answer = 0;
    }

    return answer;
}