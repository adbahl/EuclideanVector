/*
 * EuclideanVector.h : Header file
 * Contains the variable declaration and class method declaration
 * Class in included in the namespace evec.
 * *  Created on: Aug 31, 2017
 *    zid: 5129975
 */

#ifndef EUCLIDEANVECTOR_H_
#define EUCLIDEANVECTOR_H_

// header files
#include<iterator>
#include<vector>
#include<list>
#include<initializer_list>
#include<algorithm>
#include<cmath>
#include<iostream>

//namespace evec.
namespace evec {

	// EuclideanVector class
	class EuclideanVector {

		private:
			unsigned int* dimen;
			double* magni;
			mutable double eNorm =0;

		public:

			//default constructor
			EuclideanVector();
			//constructor with as dimension as input
			EuclideanVector(unsigned int);
			//constructor with as dimension and magni as input
			EuclideanVector(unsigned int, double);

			//constructor with as vector as input
			EuclideanVector(const std::vector<double>::iterator it, const std::vector<double>::iterator end);
			//constructor with as list as input
			EuclideanVector(const std::list<double>::iterator it, const std::list<double>::iterator end);
			//constructor with as initializer list as input
			EuclideanVector(const std::initializer_list<double> itr);
			//copy constructor
			EuclideanVector(const EuclideanVector&);
			// move constructor
			EuclideanVector(EuclideanVector &&);

			// destructor
			virtual ~EuclideanVector();

			// Member function , get, getdimension, get EuclideanNorm and create unit vector.
			unsigned int getNumDimensions() const;
			double get(unsigned int) const;
			double getEuclideanNorm() const;
			EuclideanVector& createUnitVector() const;

			// Member operator overloading
			double operator[](unsigned int index) const;
			double& operator[](unsigned int index);
			EuclideanVector& operator+=(const EuclideanVector&);
			EuclideanVector& operator-=(const EuclideanVector&);
			EuclideanVector& operator*=(const double);
			EuclideanVector& operator/=(const double);

			// casting from Euclidean vector to list and vector
			operator std::vector<double>() const;
			operator std::list<double>() const;

			//friend functions: Does the operator overloading.
			friend bool operator==(const EuclideanVector&, const EuclideanVector&);
			friend bool operator!=(const EuclideanVector&, const EuclideanVector&);
			friend EuclideanVector& operator+(const EuclideanVector&, const EuclideanVector&);
			friend EuclideanVector& operator-(const EuclideanVector&, const EuclideanVector&);
			friend double operator*(const EuclideanVector &, const EuclideanVector &);
			friend EuclideanVector& operator*(const EuclideanVector &, const double);
			friend EuclideanVector& operator*(const double, const EuclideanVector &);
			friend EuclideanVector& operator/(const EuclideanVector &, const double);
			friend std::ostream& operator<<(std::ostream &, const EuclideanVector &);
	};

} /* namespace evec */

#endif /* EUCLIDEANVECTOR_H_ */

//----------------------------------------
