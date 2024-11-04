/*
Axel Eduardo Iparrea Ramos A00836682

This program checks if two line segments intersect in a 2D Cartesian plane.
It reads a series of points, each representing endpoints of line segments, and outputs 
"True" if two segments intersect and "False" otherwise.

Daily Use Cases:
- Geospatial systems: Detecting if paths or boundaries intersect.
- Computer graphics: Checking if lines in vector graphics or game objects intersect.
- Robotics and pathfinding: Ensuring safe movement by detecting intersections of paths.
*/

#include <iostream>
#include <vector>

using namespace std;

struct Punto {
    int x, y;
};

int orientacion(Punto p, Punto q, Punto r) {
    int val = (q.y - p.y) * (r.x - q.x) - (q.x - p.x) * (r.y - q.y);
    if (val == 0) return 0;
    return (val > 0) ? 1 : 2;
}

bool enSegmento(Punto p, Punto q, Punto r) {
    return (q.x <= max(p.x, r.x) && q.x >= min(p.x, r.x) &&
            q.y <= max(p.y, r.y) && q.y >= min(p.y, r.y));
}

bool intersectan(Punto p1, Punto q1, Punto p2, Punto q2) {
    int o1 = orientacion(p1, q1, p2);
    int o2 = orientacion(p1, q1, q2);
    int o3 = orientacion(p2, q2, p1);
    int o4 = orientacion(p2, q2, q1);

    if (o1 != o2 && o3 != o4)
        return true;

    if (o1 == 0 && enSegmento(p1, p2, q1)) return true;
    if (o2 == 0 && enSegmento(p1, q2, q1)) return true;
    if (o3 == 0 && enSegmento(p2, p1, q2)) return true;
    if (o4 == 0 && enSegmento(p2, q1, q2)) return true;

    return false;
}

int main() {
    int n;
    cout << "Ingrese el número de conjuntos : ";
    cin >> n;
    
    vector<bool> resultados;

    for (int i = 0; i < n; i++) {
        Punto p1, q1, p2, q2;
        cin >> p1.x >> p1.y >> q1.x >> q1.y >> p2.x >> p2.y >> q2.x >> q2.y;
        
        bool intersecta = intersectan(p1, q1, p2, q2);
        resultados.push_back(intersecta);
    }

    for (bool resultado : resultados) {
        cout << (resultado ? "True" : "False") << endl;
    }

    return 0;
}
