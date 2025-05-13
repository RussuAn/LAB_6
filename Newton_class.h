#ifndef NEWTON_CLASS_H
#define NEWTON_CLASS_H

#include <iostream>
#include <cmath>

using namespace std;

class Newton_class {
private:
    double x0;
    double eps;
    
public:
    Newton_class(void);
    ~Newton_class(void);

    void setStart(double start);
    void setTolerance(double vol_eps);
    int count(double &x);
};

#endif
