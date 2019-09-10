/*
 * EuclideanVector.cpp : Class file for Euclidean Vector.
 * Input Types : unsigned int for dimension and double type for magnitude.
 * Created different types upon constructor depending on the input parameters.
 * Created Member function to getdimension, get value, create unit vectors and Euclidean Norm.
 *  Member operator overloading are created which are member function of class.
 *  Friend operators overloading are created which are non member function of class.
 *  Created By Arvind Bahl
 *  
 */

#include "EuclideanVector.h"

namespace evec {

	// constructor, default constructors which uses delegating constructor.
	EuclideanVector::EuclideanVector(): EuclideanVector::EuclideanVector(1,0.0) {}
	EuclideanVector::EuclideanVector(unsigned int dimension): EuclideanVector::EuclideanVector(dimension, 0.0) {}
	EuclideanVector::EuclideanVector(unsigned int dimension,  double magnitude){

		dimen = new unsigned int(dimension);
		magni = new double[dimension];

		for(unsigned int count=0; count<dimension; count++ ){

			*(magni+count) = magnitude;
		}
	}

	// constructor for input as a vector. It uses for loop to assign the dimension and magnitude
	// to Euclidean vector.
	EuclideanVector::EuclideanVector(const std::vector<double>::iterator itr, const std::vector<double>::iterator ite){
		  dimen = new unsigned int(0);
		  for (auto it = itr; it != ite; ++it){
		    (*dimen) = *dimen + 1;
		  }
		  magni = new double[*dimen];
		  int count =0;
		  for (auto it = itr; it != ite; ++it){
		    *(magni+count) = *it;
		    count++;
		  }
	}
	// constructor for input as a list. It uses for loop to assign the dimension and magnitude
	// to Euclidean vector.
	EuclideanVector::EuclideanVector(const std::list<double>::iterator itr, const std::list<double>::iterator ite){
		  dimen = new unsigned int(0);
		  for (auto it = itr; it != ite; ++it){
		    (*dimen) = *dimen + 1;
		  }
		  magni = new double[*dimen];
		  int count =0;
		  for (auto it = itr; it != ite; ++it){
		    *(magni+count) = *it;
		    count++;
		  }
	}
	// constructor for input as a initializer. It uses for loop to assign the dimension and magnitude
	// to Euclidean vector.
	EuclideanVector::EuclideanVector(const std::initializer_list<double> itr){
		  dimen = new unsigned int(0);
		  for (auto it = itr.begin(); it != itr.end(); ++it){
		    (*dimen) = *dimen + 1;
		  }
		  magni = new double[*dimen];
		  int count =0;
		  for (auto it = itr.begin(); it != itr.end(); ++it){
		    *(magni+count) = *it;
		    count++;
		  }
	}

	// copy constructor, which retains the source and creates a copy:
	EuclideanVector::EuclideanVector(const EuclideanVector &source){
		dimen = new unsigned int(*(source.dimen));
		magni = new double[*(source.dimen)];
		eNorm = source.eNorm;
		for (unsigned int i = 0; i< *dimen; i++){
			*(magni+i) = *(source.magni+i);
		}
	}

	// move constructor: moves the source to destinations and keep source in valid state.
	EuclideanVector::EuclideanVector(EuclideanVector &&source){
		dimen = new unsigned int();
		magni = new double();
		eNorm = source.eNorm;

		dimen = source.dimen;
		magni = source.magni;

		source.dimen = nullptr;
		source.magni = nullptr;

	}
// Destructor called to delete the heap memory.
	EuclideanVector::~EuclideanVector() {
		   delete [] magni;
		   magni = NULL;

		   delete dimen;
		   dimen = NULL;
	}

	//getdimensions function, return the dimension.
	unsigned int EuclideanVector::getNumDimensions() const{
		return *dimen;
	}
	//get function, return the magnitude at the index.
	double EuclideanVector::get(unsigned int index) const{
		for (unsigned int i = 0; i< *dimen; i++){
			if (i == index){
				return *(magni+i);
			}
		}
		return 0;
	}

	//getEuclideanNorm() : get the double value as EuclideanNorm.
	double EuclideanVector::getEuclideanNorm() const{
		this->eNorm =0;
			for (unsigned int i=0; i<*(this->dimen); i++){
				this->eNorm += pow(*(this->magni+i), 2);
			}
			this->eNorm = sqrt(this->eNorm);
			return this->eNorm;
		}

	// Creates a Euclidean vector.
	EuclideanVector& EuclideanVector::createUnitVector() const{
		if (eNorm ==0){
			getEuclideanNorm();
		}
		EuclideanVector *tempVector = new EuclideanVector(*dimen);
		for(unsigned int i =0; i<*dimen; i++){
			*(tempVector->magni+i)= (double)*(magni+i)/eNorm;
		}
		return *tempVector;
	}

	// operator [] overloading
	double EuclideanVector::operator[](unsigned int index) const{
		double tempValue = get(index);
		return tempValue;
	}

	// operator [] overloading by reference
	double& EuclideanVector::operator[](unsigned int index) {
		return *(magni+index);
	}

	// operator += overloading
	EuclideanVector& EuclideanVector::operator+=(const EuclideanVector& rhValue){
		for(unsigned int i=0; i<*dimen; i++){
			*(magni+i) += *(rhValue.magni+i);
		}
		return *this;
	}

	// operator -= overloading
	EuclideanVector& EuclideanVector::operator-=(const EuclideanVector& rhValue){
		for(unsigned int i=0; i<*dimen; i++){
			*(magni+i) -= *(rhValue.magni+i);
		}
		return *this;
	}

	// operator *= overloading
	EuclideanVector& EuclideanVector::operator*=(const double rhs){
		for(unsigned int i=0; i<*dimen; i++){
			*(magni+i) *= rhs;
		}
		return *this;
	}

	// operator /= overloading
	EuclideanVector& EuclideanVector::operator/=(const double rhs){
		for(unsigned int i=0; i<*dimen; i++){
			*(magni+i) /= rhs;
		}
		return *this;
	}

	//conversion/casting to vector for given Euclidean vector
	EuclideanVector::operator std::vector<double> () const{
		std::vector<double> tempVector;
		for(unsigned int i=0; i<*dimen; i++){
			tempVector.push_back(*(magni+i)) ;
		}
		return tempVector;
	}

	//conversion/casting to list for given Euclidean vector
	EuclideanVector::operator std::list<double> () const{
		std::list<double> tempList;
		for(unsigned int i=0; i<*dimen; i++){
			tempList.push_back(*(magni+i)) ;
		}
		return tempList;
	}

	//(Friend/Non Member) operator overloading ==
	bool operator==(const EuclideanVector& lVector, const EuclideanVector& rVector){
		if (*(lVector.dimen) == *(rVector.dimen)){
			bool result;
			for (unsigned int i=0; i< *(lVector.dimen); i++){
				if (*(lVector.magni+i) == *(rVector.magni+i)){
					result = true;
				}
				else{
					result = false;
					break;
				}
			}
			return result;
		}
		return false;
	}

		//(Friend/Non Member) operator overloading !=
	bool operator!=(const EuclideanVector& lVector, const EuclideanVector& rVector){
		if (*(lVector.dimen) == *(rVector.dimen)){
			bool result;
			for (unsigned int i=0; i< *(lVector.dimen); i++){
				if (*(lVector.magni+i) == *(rVector.magni+i)){
				result = false;
				}
				else{
					result = true;
					break;
				}
			}
			return result;
		}
		return true;
	}

	//Friend/Non Member) operator overloading +
	EuclideanVector& operator+(const EuclideanVector& fVector, const EuclideanVector& sVector){
		EuclideanVector *rVector= new EuclideanVector(*(fVector.dimen));
		if (*(fVector.dimen) != *(sVector.dimen)){
			abort();
		}
		else{
			*(rVector->dimen) = *(fVector.dimen);
			for(unsigned int i=0; i<*(fVector.dimen); i++){
				*(rVector->magni+i)= *(fVector.magni+i) + *(sVector.magni+i);
			}
		}
		return *rVector;
	}

	//Friend/Non Member) operator overloading -
	EuclideanVector& operator-(const EuclideanVector& fVector, const EuclideanVector& sVector){
		EuclideanVector *rVector= new EuclideanVector(*(fVector.dimen));
		if (*(fVector.dimen) != *(sVector.dimen)){
			abort();
		}
		else{
			*(rVector->dimen) = *(fVector.dimen);
			for(unsigned int i=0; i<*(fVector.dimen); i++){
				*(rVector->magni+i)= *(fVector.magni+i) - *(sVector.magni+i);
			}
		}
		return *rVector;

	}
	//Friend/Non Member) operator - overloading, output double
	double operator*(const EuclideanVector &fVector, const EuclideanVector &sVector){
		double rDotProduct=0;
		if (*(fVector.dimen) != *(sVector.dimen)){
			abort();
		}
		else{
			for(unsigned int i=0; i<*(fVector.dimen); i++){
				rDotProduct= rDotProduct + (*(fVector.magni+i)) * (*(sVector.magni+i));
			}
		}
		return rDotProduct;
	}

	//Friend/Non Member) operator * overloading, output EuclideanVector
	EuclideanVector& operator*(const EuclideanVector & fVector, const double sNum){
		EuclideanVector *rVector= new EuclideanVector(*(fVector.dimen));
		for(unsigned int i=0; i<*(fVector.dimen); i++){
			*(rVector->magni+i)= *(fVector.magni+i) * (sNum);
		}
		return *rVector;
	}

	//Friend/Non Member) operator * output EuclideanVector
	EuclideanVector& operator*(const double sNum, const EuclideanVector & fVector){
		EuclideanVector *rVector= new EuclideanVector(*(fVector.dimen));
		for(unsigned int i=0; i<*(fVector.dimen); i++){
			*(rVector->magni+i)= *(fVector.magni+i) * (sNum);
		}
		return *rVector;
	}

	//Friend/Non Member) operator / output EuclideanVector
	EuclideanVector& operator/(const EuclideanVector & fVector, const double sNum){
		EuclideanVector *rVector= new EuclideanVector(*(fVector.dimen));
		for(unsigned int i=0; i<*(fVector.dimen); i++){
			*(rVector->magni+i)= *(fVector.magni+i) / (sNum);
		}
		return *rVector;
	}

	//Friend/Non Member) operator << overloading
	std::ostream& operator<<(std::ostream &output, const EuclideanVector &fVector){
		if (fVector.dimen == nullptr){
			output<<"[]";
			return output;
		}

		output<< "[";
		for (unsigned int i =0; i<*(fVector.dimen); i++){
			output<<*(fVector.magni+i);
			if (i!=(*(fVector.dimen)-1))
			output<< " ";
		}
		output<< "]";

		return output;

	}
} /* namespace evec */

//----------------------------------------
