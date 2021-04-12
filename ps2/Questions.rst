
PS2 Questions
=============

Add your answers to this file in plain text after each question.  Leave a blank line between the text of the question and the text of your answer and at least two lines between your answer and the next question.

.. role:: cpp(code)
   :language: c++


Inner Product
-------------

1. How would you use :cpp:`dot` to implement :cpp:`two_norm`?

I order to achieve the same output from “dot” function as from “two_norm”, we can pass in the parameter Vector object twice.  For example: 
“dot( x, x)” will provide the same output as “two_norm(x)”


Tensors
-------

2. What is the formula that we would use for indexing if we wanted "slab-major" ordering?  Hint:  What is the size of a slab?  It might be helpful to draw a picture of the data in 3D and see what the size is of a slab.

If we would use "Tensor& T" class, we should use "T.num_slabs()" for indexing through slabs.
For example: to loop through Tensor class object we can use code as following:
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


3. (Extra credit.) I claim that there are six distinct indexing formulas.  Show that this claim is correct or that it is incorrect.

I believe that Tensor class can have six distinct indexing formulas such as:
initialization of Tensor T(10, 10, 10) that represent Tensor(size_t L, size_t M, size_t N) : num_slabs_(L), num_rows_(M), num_cols_(N)
1) T[L, M, N]
2) T[L, M, N]
3) T[L, M, N]
4) T[L, M, N]
5) T[L, M, N]
6) T[L, M, N]