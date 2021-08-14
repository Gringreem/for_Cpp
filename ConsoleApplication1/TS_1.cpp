#include <string>
#include <vector>
#include <cmath>

using namespace std;

long long solution(long long orderAmount, long long taxFreeAmount, long long serviceFee) {
    // orderAmount : �ֹ��ݾ�
    // taxFreeAmount : ������ݾ�
    // serviceFee : �����    
    long long answer = 0;

    // allAmount : ���޴밡
    long long allAmount = orderAmount - serviceFee;
    if (allAmount - taxFreeAmount == 1) {
        return 0;
    }

    answer = ceil((double)(orderAmount - serviceFee - taxFreeAmount) / 11);

    return answer;
}