//
// This file is part of the course materials for AMATH483/583 at the University of Washington,
// Spring 2020
//
// Licensed under Creative Commons Attribution-NonCommercial-ShareAlike 4.0 International License
// https://creativecommons.org/licenses/by-nc-sa/4.0/
//
// Author: Andrew Lumsdaine
//

#include "amath583.hpp"
#include "Matrix.hpp"
#include "Vector.hpp"
#include "Tensor.hpp"
#include <cmath>
#include <cstddef>

void zeroize(Vector &x)
{
  double zeroValue = 0.0;
  for (size_t i = 0; i < x.num_rows(); ++i)
  {
    x(i) = zeroValue;
  }
}

double one_norm(const Vector& x) {
  double outputValue = 0.0;
  for (size_t i = 0; i < x.num_rows(); ++i) {
    outputValue += std::abs(x(i));
  }

  return outputValue;
}

double two_norm(const Vector& x) {
  double outputValue = 0.0;
  for (size_t i = 0; i < x.num_rows(); ++i) {
    double runningValue = x(i);
    outputValue += runningValue * runningValue;
  }

  return std::sqrt(outputValue);
}

double inf_norm(const Vector& x) {
  double outputValue = 0.0;
  for (size_t i = 0; i < x.num_rows(); ++i) {
    double runningValue = std::abs(x(i));
    if(runningValue > outputValue) {
      // Use abs of running value
      outputValue = std::abs(runningValue);
    }
  }
  
  return outputValue;
}

double dot(const Vector& x, const Vector& y) {
  double outputValue = 0.0;

  // If vectors are not equal, we can't find each corresponding index in them
  if(x.num_rows() != y.num_rows()) {
    return outputValue;
  } 

  for (size_t i = 0; i < x.num_rows(); ++i) {
    double runningValueOne = x(i);
    double runningValueTwo = y(i);
    outputValue += (runningValueOne * runningValueTwo);
  }
  
  return outputValue;
}

double two_norm_d(const Vector& x) { 
  // WRITE ME / FIX ME -- can you make the function only one line long including return?
  return std::sqrt(dot(x, x));  
}

double one_norm(const Matrix& A) {
  double sum = 0.0;
  for (size_t j = 0; j < A.num_cols(); ++j) {    // for each column
    double tmp = 0.0;
    for (size_t i = 0; i < A.num_rows(); ++i) {    // compute column sum
      tmp += std::abs(A(i, j));
    }
    sum = std::max(sum, tmp);
  }

  return sum;
}

double inf_norm(const Matrix& A) {
  double outputValue = 0.0;
  for (size_t i = 0; i < A.num_rows(); ++i) {
    double runningValue = 0.0;
    for (size_t j = 0; j < A.num_cols(); ++j) {
      runningValue += std::abs(A(i, j));
    }
    outputValue = std::max(outputValue, runningValue);
  }
  
  return outputValue;
}

double f_norm(const Matrix& A) {
  // “Frobenius” norm. Rather, the matrix two-norm is the largest singular value of the matrix A
  double outputValue = 0.0;
  for (size_t i = 0; i < A.num_rows(); ++i) {
    for (size_t j = 0; j < A.num_cols(); ++j) {
      double runningValue = std::abs(A(i, j));
      outputValue += std::pow(runningValue, 2.0);
    }
  }
  
  outputValue = std::sqrt(outputValue);

  return outputValue;
}


double tensor_sample(const Tensor& T) {
  double sum = 0.0;
  for (size_t j = 0; j < T.num_cols(); ++j) {    // for each column
    for (size_t i = 0; i < T.num_rows(); ++i) {    // for each row
      for (size_t k = 0; k < T.num_slabs(); ++k) {    // for each slab
        // Do something 
      }
    }
  }

  return sum;
}