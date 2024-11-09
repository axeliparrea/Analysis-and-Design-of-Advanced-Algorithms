#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>

struct Point {
    int x, y;
};

int orientation(Point p, Point q, Point r) {
    int val = (q.y - p.y) * (r.x - q.x) - (q.x - p.x) * (r.y - q.y);
    if (val == 0) return 0;
    return (val > 0) ? 1 : 2;
}

bool compare(Point p1, Point p2, Point p0) {
    int o = orientation(p0, p1, p2);
    if (o == 0)
        return (std::hypot(p1.x - p0.x, p1.y - p0.y) < std::hypot(p2.x - p0.x, p2.y - p0.y));
    return (o == 2);
}

std::vector<Point> grahamScan(std::vector<Point> &points) {
    Point p0 = *min_element(points.begin(), points.end(), [](Point a, Point b) {
        return (a.y < b.y) || (a.y == b.y && a.x < b.x);
    });

    sort(points.begin(), points.end(), [p0](Point p1, Point p2) {
        return compare(p1, p2, p0);
    });

    std::vector<Point> hull;
    for (Point p : points) {
        while (hull.size() > 1 && orientation(hull[hull.size() - 2], hull.back(), p) != 2) {
            hull.pop_back();
        }
        hull.push_back(p);
    }

    return hull;
}

int main() {
    int n;
    std::cout << "numero de puntos: ";
    std::cin >> n;

    std::vector<Point> points(n);
    std::cout << "Dame en formato'x y' (por ejemplo: 0 2):\n";
    for (int i = 0; i < n; i++) {
        std::cin >> points[i].x >> points[i].y;
    }

    std::vector<Point> hull = grahamScan(points);

    std::cout << "Puntos del poligono:\n";
    for (const auto &p : hull) {
        std::cout << p.x << " " << p.y << "\n";
    }

    return 0;
}
