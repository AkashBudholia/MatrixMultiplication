#include <exception>
#include <vector>
#include <string>
#include <cmath>


using namespace std;

class MatrixOperations
{
    using Matrix2D = std::vector<std::vector<double> >;
    
public:
    Matrix2D multiply(Matrix2D A, Matrix2D B)
    {
        if(A.empty() && B.empty())
        {
            return Matrix2D();
        }
        
        if(A.empty() || B.empty())
        {
           throw new MatrixExceptions("Empty Dimensions for one of the Matrices\n");
        }
        Matrix2D C(A.size(), vector<double> (B[0].size()));

        if(A[0].size() != B.size())
        {
            throw new MatrixExceptions("Incompatible Matrix Dimensions for Multiplication\n");
        }
        
        if(sizeof(A)/sizeof(A[0]) == sizeof(B)/sizeof(B[0]) && sizeof(A)/sizeof(A[0]) > 2 && isPowerOFTwo(sizeof(A)/sizeof(A[0]))) {
            
            return strassensImplementation(A, B);
        }
        else{

        int i, j, k;
        for (i = 0; i < A.size(); i++)
        {
            for (j = 0; j < B[0].size(); j++)
            {
                for (k = 0; k < A[0].size(); k++){
                    C[i][j] += A[i][k] * B[k][j];
                }
            }
        }

      }
        return C;
    }
    
    // Matrix Transpose
    
    Matrix2D transposeMatrix(Matrix2D A)
    {
        if(A.size() == 0 || A[0].size() == 0)
        {
            throw new MatrixExceptions("The Dimension(s) of the matrix cannot be 0\n");
        }
        
        Matrix2D ATrans(A[0].size(), vector<double> (A.size()));
        
        double i, j;
        for (i = 0; i < A[0].size(); ++i)
        {
            for (j = 0; j < A.size(); ++j)
            {
                ATrans[i][j] = A[j][i];
            }
            
        }
        return ATrans;
    }
    
    
    Matrix2D subtract(Matrix2D A, Matrix2D B){
        
        int n = sizeof(A)/sizeof(A[0]);
        
        Matrix2D C(n, vector<double> (n));
        
        for (int i = 0; i < n; i++){
            for (int j = 0; j < n; j++){
                C[i][j] = A[i][j] - B[i][j];
            }
        }
        return C;
        
    }
    
    Matrix2D addition(Matrix2D A, Matrix2D B){
        
        int n = sizeof(A)/sizeof(A[0]);
        
       Matrix2D C(n, vector<double> (n));
        
        for (int i = 0; i < n; i++){
            for (int j = 0; j < n; j++){
                C[i][j] = A[i][j] + B[i][j];
            }
        }
        return C;
        
    }
    
    void split(Matrix2D P, Matrix2D C, int iB, int jB){
        
        for(int i1 = 0, i2 = iB; i1 < sizeof(C)/sizeof(C[0]); i1++, i2++){
            for(int j1 = 0, j2 = jB; j1 < sizeof(C)/sizeof(C[0]); j1++, j2++){
                C[i1][j1] = P[i2][j2];
            }
        }
        
    }
    
    void join(Matrix2D C, Matrix2D P, int iB, int jB){
        
        for(int i1 = 0, i2 = iB; i1 < sizeof(C)/sizeof(C[0]); i1++, i2++){
            for(int j1 = 0, j2 = jB; j1 < sizeof(C)/sizeof(C[0]); j1++, j2++){
                P[i2][j2] = C[i1][j1];
            }
        }
    }
    
    
    Matrix2D strassensImplementation(Matrix2D A, Matrix2D B){
        
        int n = sizeof(A)/sizeof(A[0]);
        
        Matrix2D R(n, vector<double> (n));
        
        if(n == 1){
            R[0][0] = A[0][0]*B[0][0];
        }
        else{
        
            Matrix2D A11(n/2, vector<double> (n/2));
            Matrix2D A12(n/2, vector<double> (n/2));
            Matrix2D A21(n/2, vector<double> (n/2));
            Matrix2D A22(n/2, vector<double> (n/2));
            Matrix2D B11(n/2, vector<double> (n/2));
            Matrix2D B12(n/2, vector<double> (n/2));
            Matrix2D B21(n/2, vector<double> (n/2));
            Matrix2D B22(n/2, vector<double> (n/2));
            
           
            
          /* Splitting A Matrix into halves*/
            split(A11, A, 0, 0);
            split(A, A12, 0 , n/2);
            split(A, A21, n/2, 0);
            split(A, A22, n/2, n/2);
            
            
            // Dividing B Matrix into 4 halves
            split(B, B11, 0 , 0);
            split(B, B12, 0 , n/2);
            split(B, B21, n/2, 0);
            split(B, B22, n/2, n/2);
            
            
          //  Recursive Calls to multiplications.
            
            Matrix2D M1 = strassensImplementation(addition(A11, A22), addition(B11, B22));
            Matrix2D M2 = strassensImplementation(addition(A21, A22), B11);
            Matrix2D M3 = strassensImplementation(A11, subtract(B12, B22));
            Matrix2D M4 = strassensImplementation(A22, subtract(B21, B11));
            Matrix2D M5 = strassensImplementation(addition(A11, A12), B22);
            Matrix2D M6 = strassensImplementation(subtract(A21, A11), addition(B11, B12));
            Matrix2D M7 = strassensImplementation(subtract(A12, A22), addition(B21, B22));
            
            
            Matrix2D C11 = addition(subtract(addition(M1, M4), M5), M7);
            Matrix2D C12 = addition(M3, M5);
            Matrix2D C21 = addition(M2, M4);
            Matrix2D C22 = addition(subtract(addition(M1, M3), M2), M6);
            
            
            join(C11, R, 0 , 0);
            join(C12, R, 0 , n/2);
            join(C21, R, n/2, 0);
            join(C22, R, n/2, n/2);
            
            
        }
        
         return R;
        
    }

    bool isPowerOFTwo(int n){
        
        if (n == 0){
            return false;
        }
        
        return (ceil(log(n)/log(2)) == floor(log(n)/log(2)));
    }
    
};
