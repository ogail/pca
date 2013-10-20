#include <iostream>
#include "Eigen/Dense"
#include "pca.h"

using Eigen::MatrixXd;
using namespace std;

int main()
{
    int rows = 3;
    int columns = 3;

    MatrixXd m(rows, columns);

    m << 1, 2, 3,
         4, 5, 6,
         7, 8, 9;

    cout << PCA::Compute(m) << endl;
}