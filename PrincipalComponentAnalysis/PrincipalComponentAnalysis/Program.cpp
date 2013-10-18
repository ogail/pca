#include <iostream>
#include "Eigen/Dense"
#include "pca.h"

using Eigen::MatrixXd;
using namespace std;

int main()
{
	MatrixXd m(3, 3);

	m << 1, 2, 3,
		 4, 5, 6,
		 7, 8, 9;

	cout << PCA::Compute(m) << endl;
}