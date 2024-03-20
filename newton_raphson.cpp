#include <bits/stdc++.h>

using namespace std;
const int lb = -1000;
const int ub = 1000;
const double error = 0.001;

class NewtonRaphson {
   public:
    double f(double x) {
        return x * x * x - 3 * x + 1;
    }

    double d_f(double x) {
        return 3 * x * x - 3;
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

    double a = 0;
    // a = 1.5;
    while (newton_raphson.f(a) >= 0) a = (rand() % (ub - lb + 1)) + lb;

    cout << a << '\n';

    cout << "the root is = " << newton_raphson.calculate_root(a) << '\n';
}