#include "matrix.hpp"


void Matrix::sweep() {
    enum Color { white = 0, green = 1, red = 2, black = 3 };
    for (int i = 1; i < matrix_.size(); i++)
    {
        for (int j = 0; j < matrix_.size(); j++)
        {
            if (matrix_[i][j] > 1) { matrix_[i][j]++; };
            if (matrix_[i][j] == 1) {
                if (i == 0) {
                    if (j == 0) {
                        if ((matrix_[i][j + 1] == red)) { matrix_[i][j] = red; };
                    }
                    else if (j == matrix_.size() - 1) {
                        if ((matrix_[i][j - 1] == red)) { matrix_[i][j] = red; };
                    }
                    else {
                        if ((matrix_[i][j - 1] == red) || (matrix_[i][j + 1] == red)) { matrix_[i][j] = red; }
                    }
                }
                else if (i == matrix_.size() - 1) {
                    if (j == 0) {
                        if ((matrix_[i][j + 1] == red) || (matrix_[i - 1][j] == red)) { matrix_[i][j] = red; };
                    }
                    else if (j == matrix_.size() - 1) {
                        if ((matrix_[i][j - 1] == red) || (matrix_[i - 1][j] == red)) { matrix_[i][j] = red; };
                    }
                    else {
                        if ((matrix_[i][j - 1] == red) || (matrix_[i][j + 1] == red) || (matrix_[i - 1][j] == red)) { matrix_[i][j] = red; }
                    }
                }
                else {
                    if (j == 0) {
                        if ((matrix_[i][j + 1] == red) || (matrix_[i - 1][j] == red) || (matrix_[i + 1][j] == red)) { matrix_[i][j] = red; };
                    }
                    else if (j == matrix_.size() - 1) {
                        if ((matrix_[i][j - 1] == red) || (matrix_[i - 1][j] == red) || (matrix_[i + 1][j] == red)) { matrix_[i][j] = red; };
                    }
                    else {
                        if ((matrix_[i][j - 1] == red) || (matrix_[i][j + 1] == red) || (matrix_[i - 1][j] == red) || (matrix_[i + 1][j] == red)) { matrix_[i][j] = red; }
                    }
                }
            }
        }
    }
}

void Matrix::setFire() {
    std::fill(matrix_[0].begin(), matrix_[0].end(), 2);
}