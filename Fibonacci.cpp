/*
Below is the code for 2 possible soltions Fibonacci number

Created by
Sarthak Bansal


*/

#include <iostream>
#include <math.h>


using namespace std;

//---------------------------------------------------------Recursive Algorithmn--------------------------------------------------------------------------

int Fib(int n){
	if (n <= 2)return 1;
	return (Fib(n-1)+Fib(n-2));
}

//--------------------------------------------------Dynamic Programming solution with Memorization--------------------------------------------------------

int MemFib(int n,int * MemArray){
	if (n <= 2)return 1;
	if (MemArray[n-1]>=0)return MemArray[n-1];
	int f = MemFib(n-1,MemArray) + MemFib(n-2,MemArray);
	MemArray[n-1] = f;
	return f;
}

int Memorization(int n){
	int MemArray[n];   // Creating a memory array to store the previous calculations

	for (int i = 0; i<n ; i++){
		MemArray[i] = -32767;    	// minimum possible integrer  usually use INT_MIN
	}

	return (MemFib(n,MemArray));
}

// -------------------------------------------------- Dynamic Programming Bottom up Solution----------------------------------------------------------------

int BottomUp(int n){
	int f[n+1];
  	int i;
  	f[0] = 0;   f[1] = 1;
  	for (i = 2; i <= n; i++)
    	  f[i] = f[i-1] + f[i-2];

  	return f[n];

}


int main () {

	int n;
	cout << "Enter a number = " << endl;
	cin >> n;
	cout << "Fibonacci number1 is = " << Fib(n) << endl;
	cout << "Fibonacci number2 is = " << Fib(n) << endl;

}