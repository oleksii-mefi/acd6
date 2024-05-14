#include <iostream>
#include <cmath>
using namespace std;

bool doSegmentsIntersect(int x1, int y1, int x2, int y2, int x3, int y3, int x4, int y4) {
    int det = (x1 - x2) * (y3 - y4) - (y1 - y2) * (x3 - x4);
    int det1 = (x1 - x3) * (y2 - y1) - (y1 - y3) * (x2 - x1);
    int det2 = (x1 - x4) * (y2 - y1) - (y1 - y4) * (x2 - x1);

    if (det == 0) {
        if (det1 == 0 && det2 == 0) {
            return true;
        }
        return false;
    }
    if (det1 * det2 >= 0) {
        return false;
    }
    return true;
}

bool doLinesIntersect(int x1, int y1, int x2, int y2, int x3, int y3, int x4, int y4) {
    double a1 = y2 - y1;
    double b1 = x1 - x2;
    double c1 = a1 * x1 + b1 * y1;

    double a2 = y4 - y3;
    double b2 = x3 - x4;
    double c2 = a2 * x3 + b2 * y3;

    double delta = a1 * b2 - a2 * b1;

    if (delta == 0) {
        return false;
    }

    double x = (b2 * c1 - b1 * c2) / delta;
    double y = (a1 * c2 - a2 * c1) / delta;

    if (x < min(x1, x2) || x > max(x1, x2) || y < min(y1, y2) || y > max(y1, y2) ||
        x < min(x3, x4) || x > max(x3, x4) || y < min(y3, y4) || y > max(y3, y4)) {
        return false;
    }

    return true;
}

int main() {
    setlocale(LC_ALL, "Ukrainian");
    int x1, y1, x2, y2, x3, y3, x4, y4;
    cout << "Введіть координати відрізка AB: ";
    cin >> x1 >> y1 >> x2 >> y2;
    cout << "Введіть координати відрізка CD: ";
    cin >> x3 >> y3 >> x4 >> y4;
    if (doSegmentsIntersect(x1, y1, x2, y2, x3, y3, x4, y4)) {
        cout << "Відрізки перетинаються" << endl;
    }
    else {
        cout << "Відрізки не перетинаються" << endl;
    }
    if (doLinesIntersect(x1, y1, x2, y2, x3, y3, x4, y4)) {
        cout << "Прямі перетинаються" << endl;
    }
    else {
        cout << "Прямі не перетинаються" << endl;
    }
    return 0;
}
