// CS264 Assignment 2, Viktorija Klavina 21426062
#include <iostream>
#include <string>
#include <cstring>
using namespace std;

/* Length function returns only positive integers, and takes in an
    unmodifiable char pointer.
    Firstly it checks whether str is nullptr, if not it loops through
    each character in str while adding to count.
    The count is then returned. */
unsigned int length (const char* str){
    int count = 0;
    if(str == nullptr){
        return 0;
    }
    for(int i=0; str[i] != '\0'; i++){
        count++;
    }
    return count;
}
/* Copy function returns an unmodifiable char pointer, and it takes
    in 2 values: char pointer to a destination, and a constant char
    pointer pointing to the source string.
    The function finds the sizes of both the destination and source.
    If the destination is big enough to store the copied source string,
    it will copy and return the destination string.
    If not, a null pointer is returned. */
char* copy (char* dest, const char* src){
    int destSize = strlen(dest);
    int srcSize = strlen(src);
    
    if(destSize >= srcSize+1){  // if destination can fit source string
        strcpy(dest,src);
        return dest;
    } else {
        return nullptr;
    }
}
/* indexOf outputs an integer, and takes in a character c and an unmodifiable
    char pointer 'str'.
    The for loop compares whether each character in str matches c.
    If a match is found, the index is returned, if not a minus 1 is returned. */
int indexOf (char c, const char* str){
    for(int i=0; str[i]!='\0'; i++){
        if(str[i]==c){
            return i;
        }
    }
    return -1;
}

/* Substring returns a character pointer and takes in 3 values: integers i and j,
    and a constant char pointer 'str'.
    The length of string is found and 2 new char pointers are made,
    'ptr' points to a single char used in the for loop,
    and 'copy' used to copy the new substring into.
    The function checks if i and j are in range,
    if they are, all the characters from i to j in 'str' are copied into 'copy'
    and copy is returned.
    If i and j are not in range, a null pointer is returned. */
char* substring (int i, int j, const char* str){
    int len = length(str);
    char* ptr = new char[1];    // size 1 to hold single char
    char* copy = new char[len];     // new string the size of old string
    
    if((i>=0 && i<=len) && (j>=i && j<=len)){ // check if i&j is in range
        for(i; i<j; i++){       // only copy from i to j
            ptr[0] = str[i];
            strcat(copy,ptr);    // (strcat): concatenate two c strings
        }
    } else {
        return nullptr;
    }
    return copy;
}
/* Replace takes in 3 values: characters c and p, and an unmodifiable
    character pointer 'str'.
    A new char pointer 'newStr' is created with the same length of str.
    All characters of string str are compared with c,
    if a character equals to c,  the char at newStr[i] is swapped with p.
    Otherwise the char at newStr[i] is swapped with str[i] (if nothing is
    swapped, this returns an exact copy of the string at the end).
    newStr is then returned. */
char* replace (char c, char p, const char* str){
    char* newStr = new char[length(str)];
    for(int i=0; str[i]!='\0'; i++){
        if(str[i]==c){
            newStr[i] = p;
        } else {
            newStr[i] = str[i];
        }
    }
    return newStr;  // if nothing was changed, it still returns a copy
}
