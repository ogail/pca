#ifndef PCA_H
#define PCA_H

#include "Eigen/Dense"

using namespace Eigen;
using namespace std;

class PCA
{
public:
	static VectorXd Compute(MatrixXd D)
	{
		// The first step in PCA is to move the origin to mean of the data
		// we achieve this by finding a mean image by averaging the columns of D
		// We then subtract the mean image from each image of the data
		// set (ie each row of D) to create the mean centered data vector which we write as U.


	}
};

#endif // PCA_H