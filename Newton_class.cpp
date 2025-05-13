#include "Newton_class.h"

Newton_class::Newton_class() {}
Newton_class::~Newton_class() {}

void Newton_class::setStart(double start) {
    x0 = start;
}

void Newton_class::setTolerance(double vol_eps) {
    eps = vol_eps;
}

int Newton_class::count(double &x) {
    x = x0;
    if (x <= 0) {
            cout << "Початкова точка має бути більше 0!" << endl;
            return -1;
    };

    auto f = [](double x) {
        return x + sqrt(x) + cbrt(x) - 2.5;
    };

    auto df = [f](double x) {
        const double h = 1e-9;
        return (f(x + h) - f(x)) / h;
    };

    int max_iter = 100;
    int iter = 0;

    while (iter < max_iter) {
        double derivative = df(x);
        if (abs(derivative) < 1e-9) {
            cout << "Похідна близька до нуля — можливий розрив." << endl;
            return -1;
        }

        double next_x = x - f(x) / derivative;

        if (abs(next_x - x) < eps) {
            x = next_x;
            cout << "Кількість ітерацій: " << iter << endl;
            return 0;
        }

        x = next_x;
        iter++;
    }
    cout << "Перевищено максимальну кількість ітерацій." << endl;
    return -1;
}
