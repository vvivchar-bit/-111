#include <bits/stdc++.h>
using namespace std;

long long sumDiv(long long n) {
    if (n == 1) return 0;
    long long s = 1;
    for (long long d = 2; d * d <= n; ++d) {
        if (n % d == 0) {
            s += d;
            if (d * d != n) s += n / d;
        }
    }
    return s;
}

int main() {
    long long a, b;
    cout << "Enter range [a, b]: ";
    cin >> a >> b;
    if (a > b) swap(a, b);

    for (long long m = a; m <= b; ++m) {
        long long n = sumDiv(m);
        if (m < n && n <= b && sumDiv(n) == m)
            cout << m << " " << n << endl;
    }
    return 0;
}
