#include <bits/stdc++.h>

using namespace std;

struct Point {
    double x, y;
};

class LagrangeInterpolation {
   public:
    double calculate(vector<Point> &v, double value) {
        int n = v.size();
        double up = 1, down = 1;
        double ans = 0;
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                if (j == i) continue;
                up *= value - v[j].x;
                down *= v[i].x - v[j].x;
            }
            ans += ((up / down) * v[i].y);
            up = 1, down = 1;
        }

        return ans;
    }
};

int main() {
    int n;
    cout << "number of inputs: ";
    cin >> n;

    double value;
    cin >> value;

    vector<Point> p(n);
    double x, y;
    for (int i = 0; i < n; i++) {
        cin >> x >> y;
        p[i] = {x, y};
    }

    LagrangeInterpolation li;
    cout << li.calculate(p, value) << '\n';
}

/*
323.5
321.0 2.50651
322.8 2.50893
324.2 2.51081
325.0 2.51188
ans -> 2.50987
*/