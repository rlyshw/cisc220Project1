#include<iostream>
#include"BigInt.h"
using namespace std;


//BigInt operator+(const BigInt& intA, const BigInt& intB){
    //return new BigInt(100);
//}

int main(){
    BigInt a = 100;
    BigInt b = 1983728574;
    BigInt c = 394857;
    BigInt d = 89273;
    BigInt e = 225;
    BigInt f = 45;
    BigInt g = 8;
    BigInt result = 0;
    
    cout << "Test 1: subtraction" << endl;
    result = b - c;
    if(result != 1983333717){
        cout << "ERROR: Test 1 failed." << endl;
    }
    else{
        cout << "Test 1 passed" << endl;
    }
    
    cout << "Test 2: addition" << endl;
    result = a + b;
    if(result != 1983728674){
        cout << "ERROR: Test 2 failed." << endl;
    }
    else{
        cout << "Test 2 passed" << endl;
    }
    
    cout << "Test 3: multiplication" << endl;
    result = d * e;
    if(result != 20086425){
        cout << "ERROR: Test 3 failed." << endl;
    }
    else{
        cout << "Test 3 passed" << endl;
    }
    
    cout << "Test 4: division" << endl;
    result = 225/45;
    if(result != 5){
        cout << "ERROR: Test 4 failed." << endl;
    }
    else{
        cout << "Test 4 passed" << endl;
    }
    
    cout << "Test 5: negative subtraction" << endl;
    result = 45-225;
    if(result != -180){
        cout << "ERROR: Test 5 failed." << endl;
    }
    else{
        cout << "Test 5 passed" << endl;
    }
    
    cout << "Test 6: double division" << endl;
    result = a/g;
    if(result != 12.5){
        cout << "ERROR: Test 6 failed." << endl;
    }
    else{
        cout << "Test 6 passed" << endl;
    }
    
    cout << "End of Tests." << endl;
    
}

