#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
// ====================================================
// 내풀이
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
            cout << "내 풀이 i 값 :" << i << endl;
            answer++;
        }
    }

    return answer;
}

// ====================================================
// 다른 사람 풀이
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
            cout << "다른 풀이 i 값:" << i << endl;
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

    cout << "=============다른 풀이============" << endl;

    cout << hanNumber(n) << endl;
    
    return 0;
}