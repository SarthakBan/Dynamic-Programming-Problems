/* 
Below is the code for 3 possible soltions to the cut rod Problem 

Created by 
Sarthak Bansal 


*/

#include <iostream>
#include <math.h>


using namespace std;

int max(int a, int b) { return (a > b)? a : b;} // MAX VAL function



//------------------------------------------------- Recursive call for CutRope is O(2^n) Very Time Inefficient---------------------------------------------------------------------------------

int RecursiveCutRope (int * array ,int length){
	if (length == 0) return 0;
	int max_val = -32767;    // minimum possible integrer  usually use INT_MIN

	for (int i =0 ; i<length ; i++){
		max_val = max(max_val,array[i] + RecursiveCutRope(array, length- i - 1) );
	}

	return max_val;
}


//--------------------------------------------------------Top-Down Dynamic Programming With Memorization O(n^2) Solution----------------------------------------------------------------------

int MemorizationCutRope(int *array ,int length ,int *MemArray){

	if (length == 0) return 0; // base case
	if (MemArray[length-1] >= 0) return MemArray[length -1]; // if it exists just return that value

	int max_val = -32767;    	// minimum possible integrer  usually use INT_MIN

	for (int i =0 ; i<length ; i++){
		max_val = max(max_val,array[i] + MemorizationCutRope(array, length- i -1,MemArray)  );
		}

	MemArray[length-1] = max_val;   // Storing the value in Memory for lookup to reduce complexity
	return max_val;
}

int Memorization(int * array , int length){
	int MemArray[length];   // Creating a memory array to store the previous calculations

	for (int i = 0; i<length ; i++){
		MemArray[i] = -32767;    	// minimum possible integrer  usually use INT_MIN
	}

	return (MemorizationCutRope(array,length,MemArray));
}

//-----------------------------------------------------------Bottom-Up Dynamic Programming solution O(n^2) Solution ----------------------------------------------------------------------------


int BottomUP(int *array ,int length){
	int MemArray[length+1]; 
	MemArray[0]=0;
	int max_val;

	// Creating a table to store the values for lookup again to reduce number of calculation
	
	for (int j =0 ; j <= length ; j++){
        max_val = -32767;		// minimum possible integer  usually use INT_MIN
		for(int i =0 ; i < j ;i++){
			max_val = max(max_val,array[i]+MemArray[j-i-1]);
            MemArray[j] = max_val;
		}
	}
	return MemArray[length];
}



//------------------------------------------------------------------------MAIN FUNCTION -------------------------------------------------------------------------------------------------------------




int main (){
	int array [8] ={1, 5, 8, 9, 10, 17, 17, 20};

	int revenue = RecursiveCutRope(array,8);
	int revenue1 = Memorization(array,8);
	int revenue2 = BottomUP(array,8);

	cout<<"Renvenue0 is = " << revenue << endl ;
	cout<<"Renvenue1 is = " << revenue1 << endl ;
	cout<<"Renvenue2 is = " << revenue2 << endl ;
	return 0;
}
