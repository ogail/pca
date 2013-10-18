#include <iostream>
#include "Eigen/Dense"

using Eigen::MatrixXd;
using namespace std;

int main()
{
	MatrixXd m(3, 3);
	double number = 1;

	for (int i = 0; i < m.rows(); i++)
	{
		for (int j = 0; j < m.cols(); j++)
		{
			m(i, j) = number++;
		}
	}

	cout << m << endl;
}