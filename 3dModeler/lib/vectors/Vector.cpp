#pragma once
#include "Vector.hpp"

/*
	CAUTION: This file gets included into a header file, don't use any using statments!
*/


template <int Rank>
Vector<Rank>::Vector(double vals[Rank]):values{} {
	for (int i = 0; i < Rank; i++) {
		values[i] = vals[i];
	}
}

template <int Rank>
/*
	Dots this vector with the given vector
*/
double Vector<Rank>::dot(Vector<Rank> v) {
	double sum{ 0 };
	for (int i = 0; i < Rank; i++) {
		sum += v.values[i] * values[i];
	}
	return sum;
}

template <int Rank>
/*
	Adds this vector and given vector tail-to-tail in a new vector
*/
Vector<Rank> Vector<Rank>::add(Vector<Rank> v) {
	double sum[Rank];
	for (int i = 0; i < Rank; i++) {
		sum[i] = values[i] + v.values[i];
	}
	return Vector<Rank>(sum);
}

template <int Rank>
/*
Returns this vector minus the given vector, or this vector plus the opposite of the given vector
*/
Vector<Rank> Vector<Rank>::subtract(Vector<Rank> v) {
	double diff[Rank]{}; //not initializing variables since they will all be set
	for (int i = 0; i < Rank; i++) {
		diff[i] = values[i] - v.values[i];
	}
	return Vector<Rank>(diff);
}

template <int Rank>
void Vector<Rank>::scale(double factor) {
	for (int i = 0; i < Rank; i++) {
		values[i] *= factor;
	}
}


#include <iostream>
template <int Rank> template <int OutRank>
/*
	Returns the vector given from multiplying this vector by a matrix. 
	Due to mathematics, the matrix must have the same number of 
*/
Vector<OutRank> Vector<Rank>::matrixMultiply(double matrix[Rank][OutRank]) {
	double outVector[OutRank]{}; //not initializing variables since they will all be set
	for (int o = 0; o < OutRank; o++) {
		double sum = 0;
		std::cout << std::endl;
		for (int r = 0; r < Rank; r++) {
			sum += values[r] * matrix[r][o];
			std::cout << "Cumulative sum: "<<sum << std::endl;
		}
		outVector[o] = sum;
	}
	std::cout << "Final Vector: "<<Vector<OutRank>{outVector}.str() << std::endl;
	return Vector<OutRank>{outVector};
}

template <int Rank>
double Vector<Rank>::getMagnitude() {
	double sum{ 0 };
	for (int i = 0; i < Rank; i++) {
		sum += values[i] * values[i];
	}
	return sqrt(sum);
}

template <int Rank>
std::string Vector<Rank>::str() {
	std::string out{ "" };
	for (int i = 0; i < Rank -1 ; i++) {
		out +=std::to_string(values[i])+" ";
	}
	out += std::to_string(values[Rank-1]);
	return out;
}