#include<iostream>
#include"BigInt.h"
#include <time.h>
#include <string>
using namespace std;


int main(){
    BigInt A = 0;
    BigInt B = 0;
    
    clock_t begin;
	clock_t end;
	begin = clock();
    
    cout << "Enter a number for A: " << endl;
    cin >> A;
    cout << "Enter a number for B: " << endl;
    cin >> B;
    
    cout << "A + B = " << A + B << endl;
    cout << "A - B = " << A - B << endl;
    cout << "A * B = " << A * B << endl;
    cout << "A/B = " << A/B << endl;
    end = clock();
	cout << "Runtime to complete all operations: " << (double)(end - begin)/ CLOCKS_PER_SEC << " seconds"<< endl; 
    /*
    //Unit Testing code for each overloaded arithmetic operator
    BigInt a = 100;
    BigInt b = 1983728574;
    BigInt c = 394857;
    BigInt d = 89273;
    BigInt e = 225;
    BigInt f = 45;
    BigInt g = 8;
    BigInt result = 0;
    
    string resultVal = "";
    string test1 = "1983333717";
    string test2 = "1983728674";
    string test3 = "20086425";
    string test4 = "5";
    
    cout << "Test 1: subtraction" << endl;
    result = b - c;
    for(int i = 0; result.arr[i] != 20; i++){
        resultVal.push_back(result.arr[i]);
    }
    if(resultVal == test1){
        cout << "Test 1 passed" << endl;
    }
    else{
        cout << "ERROR: Test 1 failed." << endl;
    }
    
    cout << "Test 2: addition" << endl;
    result = a + b;
    for(int i = 0; result.arr[i] != 20; i++){
        resultVal.push_back(result.arr[i]);
    }
    if(resultVal == test2){
        cout << "Test 2 passed" << endl;
    }
    else{
        cout << "ERROR: Test 2 failed." << endl;
    }
    
    cout << "Test 3: multiplication" << endl;
    result = d*e;
    for(int i = 0; result.arr[i] != 20; i++){
        resultVal.push_back(result.arr[i]);
    }
    if(resultVal == test3){
        cout << "Test 3 passed" << endl;
    }
    else{
        cout << "ERROR: Test 3 failed." << endl;
    }
    
    cout << "Test 4: division" << endl;
    result = e/f;
    for(int i = 0; result.arr[i] != 20; i++){
        resultVal.push_back(result.arr[i]);
    }
    if(resultVal == test4){
        cout << "Test 4 passed" << endl;
    }
    else{
        cout << "ERROR: Test 4 failed." << endl;
    }
    
    
    cout << "End of Tests." << endl;
    */
    
}
