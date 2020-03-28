

This is a document file describing the initial BLAS matrix multiplication and transpose implementation. Several other BLAS features will be implemented in a successive iterations. 


Matrix Multiplication: 

1) If there are 2 Matrices NXM and MXT, the resultant matrix will have the dimensions N X T, if the values of column of Matrix 1 is not same as row value of Matrix B, the matrix cannot be multiplied

2) This case is handled using Exception Handling, where the program will not terminate abruptly and instead print the error.

3) For odd N,M and T, a naive implementation of Matrix Multiplication is implemented, but for matrices in the order of power of 2 , Strassen Matrix Multiplication algorithm is implemented. 

4) Strassen Matrix Multiplication has a time complexity of O(n^2.81) as compared to naive matrix multiplication algorithm which has O(n^3)

The quick tutorial on the algorithm can be found at : https://stanford.edu/~rezab/classes/cme323/S16/notes/Lecture03/cme323_lec3.pdf

Note: Strassen doesn't work well for the cases mentioned above for which naive algorithm is implemented, as it requires the matrix to be padded with zeros to make it in the order of  power of 2.


Transpose of a Matrix: 

It is a naive implementation of a transpose in O(n^2) time. 


Files : 

Main.cpp 

->  It contains a hard-coded matrix used for validation of the matrix multiplication algorithm.


exceptionhandler.h (included as a header file)

-> Handles exception related to incompatible matrix dimensions to one of the matrices being of 0 dimension. Can be extrapolated for other user defined exceptions as well.


MatrixOperations.h(included as a header file)

-> Contains the logic for matrix multiplication and transpose. Can be extrapolated to other matrix operations as well.

