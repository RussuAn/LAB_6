#include "Dyhotomia_class.h"

Dyhotomia_class::Dyhotomia_class() {}
Dyhotomia_class::~Dyhotomia_class() {}

void Dyhotomia_class::setVolumes(double vol_a, double vol_b) {
    a = vol_a;
    b = vol_b;
}

void Dyhotomia_class::setTolerance(double vol_eps) {
    eps = vol_eps;
}

int Dyhotomia_class::count(double &x) {
    int iter = 0;

    auto f = [](double x) {
        return x + sqrt(x) + cbrt(x) - 2.5;
    };

    if (f(a) * f(b) >= 0) {
        cout << "На заданому проміжку [" << a << "; " << b << "] немає кореня або їх декілька." << endl;
        return -1;
    }

    double c;

    while ((b - a) > eps) {
        c = (a + b) / 2;
        if (f(a) * f(c) < 0)
            b = c;
        else
            a = c;
        iter++;
    }

    x = (a + b) / 2;
    cout << "Кількість ітерацій: " << iter << endl;
    return 0;
}