#include <string>
#include <vector>
#include <cmath>

using namespace std;

long long solution(long long orderAmount, long long taxFreeAmount, long long serviceFee) {
    // orderAmount : 주문금액
    // taxFreeAmount : 비과세금액
    // serviceFee : 봉사료    
    long long answer = 0;

    // allAmount : 공급대가
    long long allAmount = orderAmount - serviceFee;
    if (allAmount - taxFreeAmount == 1) {
        return 0;
    }

    answer = ceil((double)(orderAmount - serviceFee - taxFreeAmount) / 11);

    return answer;
}