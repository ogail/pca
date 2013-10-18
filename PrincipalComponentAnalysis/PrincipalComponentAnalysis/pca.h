#ifndef PCA_H
#define PCA_H

#include <iostream>
#include <assert.h>
#include <vector>
#include "Eigen/Dense"
#include "Eigen/Eigenvalues"

using namespace Eigen;
using namespace std;

class PCA
{
public:

	static VectorXd Compute(MatrixXd D)
	{
		// The matrix must be square matrix.
		assert(D.rows() == D.cols());
		int N = D.rows();

		// 1. Compute the mean image
		MatrixXd mean(1, D.cols());
		mean.setZero();

		for (int i = 0; i < D.rows(); i++)
		{
			for (int j = 0; j < D.cols(); j++)
			{
				mean(0, j) += D(i, j);
			}
		}

		// 2. Subtract mean image from the data set to get mean centered data vector
		MatrixXd U = D;

		for (int i = 0; i < D.rows(); i++)
		{
			for (int j = 0; j < D.cols(); j++)
			{
				U(i, j) -= mean(0, j) / D.rows();
			}
		}

		// 3. Compute the covariance matrix from the mean centered data matrix
		MatrixXd covariance = (U.transpose() * U) / (double)(N - 1);

		// cout << covariance << endl;

		// 4. Calculate the eigenvalues and eigenvectors for the covariance matrix
		EigenSolver<MatrixXd> solver(covariance);
		MatrixXd eigenVectors = solver.eigenvectors().real();
		VectorXd eigenValues = solver.eigenvalues().real();

		// 5. Normalize the eigen vectors
		eigenVectors.normalize();

		// cout << eigenVectors << endl;
		// cout << eigenValues << endl;

		// 6. Find out an eigenvector with the largest eigenvalue
		//    which distingushes the data
		sort(eigenValues.derived().data(), eigenValues.derived().data() + eigenValues.derived().size());
		short index = eigenValues.size() - 1;
		VectorXd featureVector = eigenVectors.row(index);

		return featureVector;
	}
};

#endif // PCA_H