#include <iostream>
#include "Eigen/Dense"
#include "pca.h"

using Eigen::MatrixXd;
using namespace std;

/*
 * This is the main entry for the PCA program.
*/ 
int main()
{
    // The number of rows in the input matrix
    int rows = 3;

    // The number of columns in the input matrix
    int columns = 3;

    // Initialize the matrix
    MatrixXd m(rows, columns);

    // Set the matrix values.
    m << 1, 2, 3,
         4, 5, 6,
         7, 8, 9;

    // Compute the principal component and show results.
    cout << PCA::Compute(m) << endl;
}