#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
// ====================================================
// ��Ǯ��
bool check(int n) {

    vector<int> num;

    while (n != 0) {
        int a = n % 10;
        n /= 10;
        num.push_back(a);
    }

    reverse(num.begin(), num.end());
    int d = num[0] - num[1];
    if (d < 0) {
        d = -d;
    }

    for (size_t i = 0; i < num.size() - 1; i++) {
        int sum = d + num[i];
        if (num[i + 1] != sum) {
            return false;
        }
    }
    

    return true;
}

int solution(int n) {
    int answer = 99;
    
    if (n == 1 || n < 100) {
        return n;
    }
    
    for (int i = 100; i <= n; i++) {
        if (check(i) == true) {
            cout << "�� Ǯ�� i �� :" << i << endl;
            answer++;
        }
    }

    return answer;
}

// ====================================================
// �ٸ� ��� Ǯ��
int hanNumber(int n) {
    int answer = 0;
    if (n < 100) {
        return n;
    }

    for (int i = 100; i <= n; i++) {
        int hundred = i / 100;
        int ten = (i % 100) / 10;
        int one = (i % 100) % 10;

        if (hundred - ten == ten - one) {
            cout << "�ٸ� Ǯ�� i ��:" << i << endl;
            answer++;
        }
    }
    return 99 + answer;
}

// ====================================================
int main() {
    int n = 0;

    cin >> n;
    cout << solution(n) << endl;

    cout << "=============�ٸ� Ǯ��============" << endl;

    cout << hanNumber(n) << endl;
    
    return 0;
}