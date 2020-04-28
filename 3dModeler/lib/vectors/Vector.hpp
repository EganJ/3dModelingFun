/*
	A generic Vector class
*/
#pragma once
#include <string>
template <int Rank>
class Vector {
public:
	Vector() = default;
	Vector(double vals[Rank]);                      // Constructs the vector with given vallues
	double dot(Vector<Rank> v);                     // Computes the dot produce for another same-rank vector
	Vector<Rank> add(Vector<Rank> v);               // Computes the result of tail-to-tail vector addition
	Vector<Rank> subtract(Vector<Rank> v);          // Computes the result of this vector minus the given vector
	void scale(double factor);                      // scales this vector in-place by the given factor
	template <int OutRank>
	Vector<OutRank> matrixMultiply(double matrix[Rank][OutRank]);   // Multiplies this vector and a matrice with the same rank as the vector. The matrice must be in [row][col] format
												
	double getMagnitude();                          // Calculates the length of the vector in Rank-dimensional space
	std::string str();                              // outputs this vector in the format val1 + " " + val2 + " " +... + " " + valN
	double values[Rank];                            // stores the values of this vector 
};

#include "Vector.cpp"