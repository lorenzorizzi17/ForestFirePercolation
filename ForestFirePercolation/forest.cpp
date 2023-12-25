#include"forest.hpp"




double Forest::get(const int i, const int j) const
{
    return forest_.get(i, j);
}

double& Forest::set(const double i, const double j)
{
    return forest_.set(i, j);
}

void Forest::fillRandom(double const p) {
    int n = forest_.size();
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            double a = double(rand()) / RAND_MAX;
            if (a > p) {
                forest_.set(i,j) = 0;
            }
            else {
                forest_.set(i,j) = 1;
            }
        }
    }
}

void Forest::sweep() {
    enum Color { white = 0, green = 1, red = 2, black = 3 };
    for (int i = 1; i < forest_.size(); i++)
    {
        for (int j = 0; j < forest_.size(); j++)
        {
            if (this->get(i,j) > 1) { this->set(i,j)++; };
            if (this->get(i,j) == 1) {
                if (i == 0) {
                    if (j == 0) {
                        if ((this->get(i,j+1) == red)) { this->set(i,j) = red; };
                    }
                    else if (j == forest_.size() - 1) {
                        if ((this->get(i,j-1) == red)) { this->set(i,j) = red; };
                    }
                    else {
                        if ((this->get(i,j-1) == red) || (this->get(i,j+1) == red)) { this->set(i,j) = red; }
                    }
                }
                else if (i == forest_.size() - 1) {
                    if (j == 0) {
                        if ((this->get(i,j+1) == red) || (this->get(i-1,j) == red)) { this->set(i,j) = red; };
                    }
                    else if (j == forest_.size() - 1) {
                        if ((this->get(i,j-1) == red) || (this->get(i-1,j) == red)) { this->set(i,j) = red; };
                    }
                    else {
                        if ((this->get(i,j-1) == red) || (this->get(i,j+1) == red) || (this->get(i-1,j) == red)) { this->set(i,j) = red; }
                    }
                }
                else {
                    if (j == 0) {
                        if ((this->get(i,j+1) == red) || (this->get(i-1,j) == red) || (this->get(i+1,j) == red)) { this->set(i,j) = red; };
                    }
                    else if (j == forest_.size() - 1) {
                        if ((this->get(i,j-1) == red) || (this->get(i-1,j) == red) || (this->get(i+1,j) == red)) { this->set(i,j) = red; };
                    }
                    else {
                        if ((this->get(i,j-1) == red) || (this->get(i,j+1) == red) || (this->get(i-1,j) == red) || (this->get(i+1,j) == red)) { this->set(i,j) = red; }
                    }
                }
            }
        }
    }
}

void Forest::setFire() {
    for (int i = 0; i < forest_.size(); i++) {
        forest_.set(0, i) = 2;
    }
}


bool Forest::fireStatus() {
    for (int i = 1; i < forest_.size(); i++) {
        for (int j = 0; j < forest_.size(); j++) {
            if (forest_.get(i, j) == 2) { return true; };
        }
    }
    return false;
}