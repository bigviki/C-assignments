// CS264 Assignment 2, Viktorija Klavina 21426062
#include <iostream>
#include <string>
#include "stringFunctions.cpp"
using namespace std;


int main(){
    cout <<"/////////  1  //////////"<<endl;   
    int length_test_case_1 = length("string");
    int length_test_case_2 = length("string\0");
    int length_test_case_3 = length("count white space chars");
    int length_test_case_4 = length(nullptr);
    int length_test_case_5 = length("");


    cout <<"Length test1: "<< length_test_case_1 <<endl;
    cout <<"Length test2: "<< length_test_case_2 <<endl;
    cout <<"Length test3: "<< length_test_case_3 <<endl;
    cout <<"Length test4: "<< length_test_case_4 <<endl;
    cout <<"Length test5: "<< length_test_case_5 <<endl;

    //////////////////////////////////////////////////////////////////
    cout <<"/////////  2  //////////"<<endl;   
    cout <<"Test cases of copy giving errors"<<endl;
    // const char* copy_test_case_1 = copy("hello", "hi");
    // char array1[20];
    // char* dest1= array1;
    // const char* copy_test_case_2 = copy(dest1, "hi");
    // const char* copy_test_case_3 = copy("", "hello");
    // const char* copy_test_case_4 = copy("hi", "nullptr");
    // const char* copy_test_case_5 = copy("hello", "");
    
    //cout <<"Copy test1: "<< copy_test_case_1 <<endl;
    //cout <<"Copy test2: "<< copy_test_case_2 <<endl;
    //cout <<"Copy test3: "<< copy_test_case_3 <<endl;
    //cout <<"Copy test4: "<< copy_test_case_4 <<endl;
    //cout <<"Copy test5: "<< copy_test_case_5 <<endl;
    
    //////////////////////////////////////////////////////////////////
    cout <<"/////////  3  //////////"<<endl;   
    int indexOf_test_case_1 = indexOf('i',"string");
    int indexOf_test_case_2 = indexOf('a',"string");
    int indexOf_test_case_3 = indexOf('s',"string");
    int indexOf_test_case_4 = indexOf('g',"string");
    int indexOf_test_case_5 = indexOf('\0',"string");
    cout <<"indexOf test1: "<< indexOf_test_case_1 <<endl;
    cout <<"indexOf test2: "<< indexOf_test_case_2 <<endl;
    cout <<"indexOf test3: "<< indexOf_test_case_3 <<endl;
    cout <<"indexOf test4: "<< indexOf_test_case_4 <<endl;
    cout <<"indexOf test5: "<< indexOf_test_case_5 <<endl;
    
    //////////////////////////////////////////////////////////////////
    cout <<"/////////  4  //////////"<<endl;   
    char* substring_test_case_1 = substring(0, 3, "string");
    char* substring_test_case_2 = substring(3, 9, "hello, john");
    char* substring_test_case_3 = substring(0, 0, "string");
    char* substring_test_case_4 = substring(0, 11, "hello, john");
    char* substring_test_case_5 = substring(2, 10, "string");
    char* substring_test_case_6 = substring(10, 2, "string");
    cout <<"Substring test1: "<< substring_test_case_1 <<endl;
    cout <<"Substring test2: "<< substring_test_case_2 <<endl;
    cout <<"Substring test3: "<< substring_test_case_3 <<endl;
    cout <<"Substring test4: "<< substring_test_case_4 <<endl;
    //cout <<"Substring test5: "<< substring_test_case_5 <<endl;
    //cout <<"Substring test6: "<< substring_test_case_6 <<endl;
    
    //////////////////////////////////////////////////////////////////
    cout <<"/////////  5  //////////"<<endl;   
    char* replace_test_case_1 = replace('i','x', "string");
    char* replace_test_case_2 = replace('x','i', "string");
    char* replace_test_case_3 = replace('i','x', "");
    char* replace_test_case_4 = replace('a','b', "string");
    char* replace_test_case_5 = replace(' ','_', "hi again john");
    cout <<"Replace test1: "<< replace_test_case_1 <<endl;
    cout <<"Replace test2: "<< replace_test_case_2 <<endl;
    cout <<"Replace test3: "<< replace_test_case_3 <<endl;
    cout <<"Replace test4: "<< replace_test_case_4 <<endl;
    cout <<"Replace test5: "<< replace_test_case_5 <<endl;

}