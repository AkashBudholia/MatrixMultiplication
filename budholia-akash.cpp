//
//  main.cpp

#include <iostream>
#include <array>
#include "exceptionHandler.h"
#include "matrixOperations.h"


int main()
{
    std::vector<std::vector<double> > A =  {{ 1, 2, 3, 4 },{ 5, 6, 7, 8 },{ 9, 10, 11, 12},{ 13, 14, 15, 16}};
    
    MatrixOperations mat;
    
    vector<vector<double> > C;
    
    vector<vector<double> > B = {{ 1, 2, 3, 4},
                                { 5, 6, 7, 8 },
                                { 9, 10, 11, 12}};

        try
        {
           vector<vector<double> > res = mat.transposeMatrix(A);
            
      for (int i = 0; i < res.size(); i++) {
            for (int j = 0; j < res[i].size(); j++)
                cout << res[i][j] << " ";
            cout << endl;
        }
            
           C = mat.multiply(A, B);
            
            
            for (int i = 0; i < C.size(); i++) {
                       for (int j = 0; j < C[i].size(); j++)
                           cout << C[i][j] << " ";
                       cout << endl;
                   }
        }
    
        catch(MatrixExceptions *e)
        {
            cout<<e->to_string();
        }
        catch (...)
        {
            cout<<"Default";
        }
    
        return 0;
}
