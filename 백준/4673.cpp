#include <iostream>
#include <vector>

using namespace std;

int d(int n) {
    int answer = n;
    while (n != 0) {
        answer = answer + n % 10;
        n = n / 10;
    }
    return answer;
}

int main() {
    vector<bool> selfNumber(10001, true);
    for (int i = 1; i <= 10000; i++) {
        int notSelfNumber = d(i);
        if (notSelfNumber > 10000)
            continue;
        selfNumber[notSelfNumber] = false;
    }
    for (int i = 0; i <= 10000; i++) {
        if (selfNumber[i])
            cout << i << '\n';
    }
    return 0;
}