#include <iostream>
#include <vector>
#include <cmath>
#include <algorithm>

struct Punto {
    int x, y;
};

double distancia(const Punto& p1, const Punto& p2) {
    return sqrt(pow(p1.x - p2.x, 2) + pow(p1.y - p2.y, 2));
}

bool compararPorX(const Punto& p1, const Punto& p2) {
    return p1.x < p2.x;
}

bool compararPorY(const Punto& p1, const Punto& p2) {
    return p1.y < p2.y;
}

double distanciaMinimaEnFranja(std::vector<Punto>& franja, double d) {
    double minDist = d;
    std::sort(franja.begin(), franja.end(), compararPorY);
    for (size_t i = 0; i < franja.size(); ++i) {
        for (size_t j = i + 1; j < franja.size() && (franja[j].y - franja[i].y) < minDist; ++j) {
            minDist = std::min(minDist, distancia(franja[i], franja[j]));
        }
    }
    return minDist;
}

double distanciaMasCercana(std::vector<Punto>& puntos, int izq, int der) {
    if (der - izq <= 3) {
        double minDist = std::numeric_limits<double>::max();
        for (int i = izq; i < der; ++i) {
            for (int j = i + 1; j < der; ++j) {
                minDist = std::min(minDist, distancia(puntos[i], puntos[j]));
            }
        }
        return minDist;
    }
    int mid = izq + (der - izq) / 2;
    double dIzq = distanciaMasCercana(puntos, izq, mid);
    double dDer = distanciaMasCercana(puntos, mid, der);
    double d = std::min(dIzq, dDer);
    std::vector<Punto> franja;
    for (int i = izq; i < der; ++i) {
        if (abs(puntos[i].x - puntos[mid].x) < d) {
            franja.push_back(puntos[i]);
        }
    }
    return std::min(d, distanciaMinimaEnFranja(franja, d));
}

int main() {
    int n;
    std::cout << "Pon los vectores" << std::endl;
    std::cin >> n;
    std::vector<Punto> puntos(n);
    for (int i = 0; i < n; ++i) {
        char coma;
        std::cin >> puntos[i].x >> coma >> puntos[i].y;
    }
    std::sort(puntos.begin(), puntos.end(), compararPorX);
    double resultado = distanciaMasCercana(puntos, 0, n);
    std::cout << "La distancia mas corta es: " << resultado << std::endl;
    return 0;
}
