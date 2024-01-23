#include <bits/stdc++.h>

using namespace std;

struct Point {
    double x, y;
};

class LeastSquare {
   public:
    Point calculate(vector<Point> &v) {
        int n = v.size();
        double x = 0, y = 0, xy = 0, x_square = 0;
        for (auto it : v) {
            x += it.x;
            y += it.y;
            xy += (it.x * it.y);
            x_square += (it.x * it.x);
        }

        Point res;
        res.x = (n * xy - x * y) / (n * x_square - x * x);
        res.y = (y * x_square - x * xy) / (n * x_square - x * x);
        return res;
    }
};

int main() {
    vector<Point> v;
    double x, y;
    int n;
    cout << "numer of points: ";
    cin >> n;
    while (n--) {
        cin >> x >> y;
        v.push_back({x, y});
    }

    LeastSquare least_square;
    Point p = least_square.calculate(v);

    cout << "slope = " << p.x << '\n';
    cout << "intercept = " << p.y;
}

// 50 12
// 70 15
// 100 21
// 120 25