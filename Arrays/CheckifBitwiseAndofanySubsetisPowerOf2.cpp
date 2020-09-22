// CPP Program to check if Bitwise AND of any 
// subset is power of two 
#include <bits/stdc++.h> 
using namespace std; 

//link: https://www.geeksforgeeks.org/check-bitwise-subset-power-two/
const int NUM_BITS = 32; 

// Check for power of 2 or not 
bool isPowerOf2(int num) 
{ 
	return (num && !(num & (num - 1))); 
} 

// Check if there exist a subset whose bitwise AND 
// is power of 2. 
bool checkSubsequence(int arr[], int n) 
{ 
	// if there is only one element in the set. 
	if (n == 1) 
	return isPowerOf2(arr[0]); 

	// Finding a number with all bit sets. 
	int total = 0; 
	for (int i = 0; i < NUM_BITS; i++) 
		total = total | (1 << i); 

	// check all the positions at which the bit is set. 
	for (int i = 0; i < NUM_BITS; i++) { 

		int ans = total; 
		for (int j = 0; j < n; j++) { 

			// include all those elements whose 
			// i-th bit is set 
			if (arr[j] & (1 << i)) 
				ans = ans & arr[j]; 
		} 

		// check for the set contains elements 
		// make a power of 2 or not 
		if (isPowerOf2(ans)) 
			return true; 
	} 
	return false; 
} 

// Driver Program 
int main() 
{ 
	int arr[] = { 12, 13, 7 }; 
	int n = sizeof(arr) / sizeof(arr[0]); 
	if (checkSubsequence(arr, n)) 
		printf("YES\n"); 
	else
		printf("NO\n"); 
	return 0; 
} 
