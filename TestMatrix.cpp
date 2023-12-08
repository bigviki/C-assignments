#include "Matrix.h"
#include <iostream>
#include <string>
using namespace std;

//- Global declarations --------------------------//
Matrix matrix1(3,3);
int** arrayExample1(){
    int** arr = new int*[3];
    for (unsigned int i = 0; i < 3; ++i) {
        arr[i] = new int[4] {1, 2, 3, 4};
    }
    return arr;
}
int** arrayExample2(){
    int** arr = new int*[3];
    for (unsigned int i = 0; i < 3; ++i) {
        arr[i] = new int[4] {1, 2, 1, 2};
    }
    return arr;
}
Matrix arr1(arrayExample1(),3,4);
Matrix arr2(arrayExample2(),3,4);
//------------------------------------------------//

// test case 1 for initializing matrix method
void Test_Case_1_Initialize(){
    cout<<matrix1.toStr()<<endl;
}
// test case 1 for copy method
void Test_Case_1_Copy(){
    cout<<"original=\n"<<arr1.toStr()<<endl;
    Matrix copy1(arr1);
    cout<<"copy=\n"<<copy1.toStr()<<endl;
}
// test case 1 for initializing matrix with array
void Test_Case_1_Array(){
    int** arr1 = new int*[2];
    for (unsigned int i = 0; i < 2; ++i) {
        arr1[i] = new int[5] {2,3,2,3,2};
    }
    Matrix test(arr1, 2, 5);
    cout<<test.toStr()<<endl;
}
// test case 1 for get rows method
void Test_Case_1_Rows(){
    cout<<arr1.toStr();
    cout<<"rows= "<<arr1.rows()<<endl;
}
// test case 1 for get columns method 
void Test_Case_1_Columns(){
    cout<<arr1.toStr();
    cout<<"columns= "<<arr1.columns()<<endl;
}
// test case 1 for get element at [i,j]
void Test_Case_1_GetElement(){
   cout<<arr1.toStr();
   cout<<"element at [1,2]= "<< arr1.get(1,2)<<endl;
}
// test case 1 for set element at [i,j]
void Test_Case_1_SetElement(){
    arr1.set(1,2,0);
    cout<<"set element at [1,2] to 0=\n"<< arr1.toStr() <<endl;
}
// test case 1 for matrix + operator
void Test_Case_1_Plus(){
    Matrix result = arr1 + arr2;
    cout<<result.toStr()<<endl;
}

// test case 1 for matrix - operator
void Test_Case_1_Minus(){
    Matrix result = arr1 - arr2;
    cout<<result.toStr()<<endl;
}

// test case 1 for matrix * operator
void Test_Case_1_Multiply(){
    Matrix result = arr1 * arr2;
    cout<<result.toStr()<<endl;
}

// test case 1 for matrix ~ operator
void Test_Case_1_Transpose(){
    Matrix result = ~arr1;
    cout<<result.toStr()<<endl;
}

// test case 1 for check if 2 matrices are the same
void Test_Case_1_Same(){
    Matrix copy1(arr1);
    bool result = arr1==copy1;
    cout<<"Is copy of arr1 == arr1? "<< result << endl;
}

// test case 2 for check if 2 matrices are the same
void Test_Case_2_Same(){
    bool result = arr1==arr2;
    cout<<"Is arr1 == arr2? "<< result << endl;
}

// test case 1 for to String method
void Test_Case_1_String(){
    cout<<matrix1.toStr()<<endl;
}

int main() {
    cout<<"TC1: initialize 3x3 matrix"<<endl;
    Test_Case_1_Initialize();
    cout<<"\nTC2: copy a matrix"<<endl;
    Test_Case_1_Copy();
    cout<<"\nTC3: copy array into matrix"<<endl;
    Test_Case_1_Array();
    cout<<"\nT4: return rows"<<endl;
    Test_Case_1_Rows();
    cout<<"\nT5: return columns"<<endl;
    Test_Case_1_Columns();
    cout<<"\nT6: get elemnt at [i,j]"<<endl;
    Test_Case_1_GetElement();
    cout<<"\nT7: set element at [i,j]"<<endl;
    Test_Case_1_SetElement();
    cout<<"\nT2: add two matrices"<<endl;
    Test_Case_1_Plus();
    cout<<"\nT2: minus two matrices"<<endl;
    Test_Case_1_Minus();
    cout<<"\nT2: multiply two matrices"<<endl;
    Test_Case_1_Multiply();
    cout<<"\nT2: tranpose a matrix"<<endl;
    Test_Case_1_Transpose();
    cout<<"\nT2: check if 2 matrices are the same"<<endl;
    Test_Case_1_Same();
    cout<<"\nT2: check if 2 matrices are the same"<<endl;
    Test_Case_2_Same();
    cout<<"\nT2: matrix to string method"<<endl;
    Test_Case_1_String();

    return 0;
}
