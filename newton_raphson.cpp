#include <bits/stdc++.h>

using namespace std;
const int lb = -1000;
const int ub = 1000;
const double error = 0.001;

class NewtonRaphson {
   public:
    double f(double x) {
        return x * x * x - x * x + 2;
    }

    double d_f(double x) {
        return 3 * x * x - 2 * x;
    }

    double calculate_root(double a) {
        double h = 1;
        while (abs(h) >= error) {
            h = f(a) / d_f(a);
            a = a - h;
        }

        return a;
    }
};

int main() {
    cout << fixed << setprecision(4);
    srand(time(0));
    NewtonRaphson newton_raphson;

    double a = rand();

    cout << a << '\n';

    cout << "the root is = " << newton_raphson.calculate_root(a) << '\n';
}