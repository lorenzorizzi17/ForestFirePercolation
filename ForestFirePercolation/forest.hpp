#include "matrix.hpp"

class Forest {
private:
	Matrix forest_;

public:
    Forest(int n) : forest_{ Matrix(n, 0) } {};
    double get(const int, const int) const;
    double& set(const double, const double);
    void fillRandom(double const);
    void sweep();
    void setFire();
    bool fireStatus();
};
