// Viktorija Klavina 21426062
#include "Matrix.h"
#include <string>
using namespace std;

        /*  Initialises matrix of size m*n, assigns 0 to each element:
                Allocates memory for new matrix
                int**ptr points to array of pointers,
                Array of pointers points to new matrix array
                Loops through matrix, setting all elements to 0
            @param 'm' and 'n' are two unsigned integers representing matrix rows&columns respectively
        */
        Matrix::Matrix ( unsigned int m , unsigned int n ){
            row = m;
            column = n;
            ptr = new int*[row];               // individual rows point to positions in memory allocation
            ptr[0] = new int[row*column];     // memory allocation for entire matrix
            
            for (unsigned int i=1; i<row; i++){
                ptr[i] = ptr[0] + i * column;
            }
            
            for (unsigned int i=0; i<row; i++) {   // all elements set to 0
                for (unsigned int j=0; j<column; j++) {
                    ptr[i][j] = 0;
                }
            }
        }
        
        /*  Copies every element from matrix 'mat':
                Allocates memory for new matrix (same size as 'mat')
                Copies elements from 'mat' into the new matrix
            @param 'mat' is a Matrix object
        */
        Matrix::Matrix ( const Matrix & mat ){
            row = mat.row;
            column = mat.column;
            ptr = new int*[row];
            ptr[0] = new int[row*column]; 
            
            for (unsigned int i=1; i<row; i++){ // set up pointers
                ptr[i] = ptr[0] + i * column;
            }

            for (unsigned int i=0; i<row; i++) {   // copies from mat
                for (unsigned int j=0; j<column; j++) {
                    ptr[i][j] = mat.ptr[i][j];
                }
            }
        }
        
        /*  Initialize matrix using 2D array of size m*n:
                Allocates memory for new matrix 
                Copies elements from array into the new matrix
            @param 'array' is double pointer pointing to a dynamic 2D array
            @param row 'i' and column 'j' in matrix
        */
        Matrix::Matrix (int ** array , unsigned int m , unsigned int n ){
            row = m;
            column = n;
            ptr = new int*[row]; 
            ptr[0] = new int[row*column];    
            
            for (unsigned int i=1; i<row; i++){
                ptr[i] = ptr[0] + i * column;
            }
            
            for (unsigned int i=0; i<row; i++) {   // copies elements from 2D array
                for (unsigned int j=0; j<column; j++) {
                    ptr[i][j] = array[i][j];
                }
            }
        }
        
        /*  @return number of rows in matrix */
        unsigned int Matrix::rows () const{
            return row;
        }

        /*  @return number of columns in matrix */
        unsigned int Matrix::columns () const{
            return column;
        }

        /*  @param rows 'i' and columns 'j' of matrix
            @return const, element at row 'i' and column 'j' in matrix
        */
        int Matrix::get ( unsigned i , unsigned j ) const{
            return ptr[i][j];
        }

        /*  Updates value at row 'i' and column 'j' in matrix
            @param row 'i' and column 'j' in matrix, and value to placed at that location
        */
        void Matrix::set ( unsigned i , unsigned j , int value ){
            ptr[i][j] = value;
        }

        /*  Matrix addition operation:
                creates a new matrix ans, of the same size 
                values with the same index in both matrices are added
                ans Matrix is updated with the result
            @param mat is a reference to a constant Matrix object
            @return ans, matrix with results of 2 matrices added together
        */
        Matrix Matrix::operator +( const Matrix & mat ){
            Matrix ans(row, column);
            
            for (unsigned int i=0; i<row; i++) {  
                for (unsigned int j=0; j<column; j++) {
                    ans.ptr[i][j] = ptr[i][j] + mat.ptr[i][j];  // ptr: original matrix, mat.ptr: matrix to be added
                }
            }
            return ans;
        }

        /*  Matrix subtraction operation:
                creates a new matrix ans, of the same size 
                values with the same index in both matrices are subtracted
                ans Matrix is updated with the result
            @param mat is a reference to a constant Matrix object
            @return ans, matrix with results of 2 matrices subtracted from one another
        */
        Matrix Matrix::operator -( const Matrix & mat ){
            Matrix ans(row, column);
            
            for (unsigned int i=0; i<row; i++) {  
                for (unsigned int j=0; j<column; j++) {
                    ans.ptr[i][j] = ptr[i][j] - mat.ptr[i][j];  // ptr: original matrix, mat.ptr: matrix to be added
                }
            }
            return ans;
        }

        /*  Matrix multiplication operation:
                creates a new matrix ans, where its rows = 1st matrix's rows, and its columns = 2nd matrix's columns
                the function follows the multiplication formula AB=[cij] , where cij=ai1b1j+ai2b2j+...
                ans Matrix is updated with the result
            @param mat is a reference to a constant Matrix object
            @return ans, matrix with results of 2 matrices multiplied together
        */
        Matrix Matrix::operator *( const Matrix & mat ){
            Matrix ans(row, mat.column);    // ans = matrix1 rows * matrix2 columns
            
            for (unsigned int i=0; i<row; i++) {  
                for (unsigned int j=0; j<mat.column; j++) {
                    ans.ptr[i][j] = 0;
                    for (unsigned int k=0; k<column; k++) {
                        ans.ptr[i][j] = ans.ptr[i][j] + ptr[i][k] * mat.ptr[k][j];
                    } 
                }
            }
            return ans;
        }
        /*  Transpose matrix:
                creates a new matrix ans, with the rows & columns swapped
                copy values from old matrix at [i][j] into new matrix at [j][i]
            @return ans, transposed matrix
        */
        Matrix Matrix::operator ~(){
            Matrix ans(column, row);                //swap dimensions
            
            for (unsigned int i=0; i<row; i++) {  
                for (unsigned int j=0; j<column; j++) {
                    ans.ptr[j][i] = ptr[i][j];      //copy values into swapped dimensions
                }
            }
            return ans;
        }
            
        /*  Check if two matrices are the same:
                ensure both matrices have the same amount of rows & columns, if not return false
                check both matrices contain same element at same location, if not return false
            @param mat is a reference to a constant Matrix object            
            @return true if both are the same, false if not the same
        */
        bool Matrix::operator ==( const Matrix & mat ){
            if ((mat.row != row) || (mat.column != row)) {return false;} //check matrices are same size
            
            for (unsigned int i=0; i<row; i++) {  
                for (unsigned int j=0; j<column; j++) {
                    if (ptr[i][j] != mat.ptr[i][j]){
                        return false;
                    }
                }
            }
            return true;
        }
        
        /*  Return string representation of matrix:
                create string 's'
                for each element in a row, add its string representation to 's'
                for each row, add a new line in 's'
            @return 's' string representation of matrix
        */
        string Matrix::toStr (){
            string s;
            for (unsigned int i=0; i<row; i++) {  
                for (unsigned int j=0; j<column; j++) {
                    s = s+ to_string(ptr[i][j]) + " ";
                }
                s = s+"\n";     //new line
            }
            return s;
        }

        // Free memory
        Matrix::~Matrix() {
            delete[] ptr[0];
            delete[] ptr;
        }