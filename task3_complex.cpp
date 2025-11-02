#include <bits/stdc++.h>
using namespace std;

struct Complex {
    double re, im;
    Complex(double r = 0, double i = 0) { re = r; im = i; }

    Complex operator+(Complex z) const { return Complex(re + z.re, im + z.im); }
    Complex operator-(Complex z) const { return Complex(re - z.re, im - z.im); }
    Complex operator*(Complex z) const {
        return Complex(re * z.re - im * z.im, re * z.im + im * z.re);
    }
    Complex operator/(Complex z) const {
        double d = z.re * z.re + z.im * z.im;
        return Complex((re * z.re + im * z.im) / d, (im * z.re - re * z.im) / d);
    }
    Complex conj() const { return Complex(re, -im); }
};

int main() {
    Complex a(3, 4), b(1, -2);
    cout << fixed << setprecision(2);

    cout << "a = " << a.re << " + " << a.im << "i\n";
    cout << "b = " << b.re << " + " << b.im << "i\n";
    cout << "a + b = " << (a + b).re << " + " << (a + b).im << "i\n";
    cout << "a - b = " << (a - b).re << " + " << (a - b).im << "i\n";
    cout << "a * b = " << (a * b).re << " + " << (a * b).im << "i\n";
    cout << "a / b = " << (a / b).re << " + " << (a / b).im << "i\n";
    cout << "conj(a) = " << a.conj().re << " + " << a.conj().im << "i\n";

    return 0;
}
