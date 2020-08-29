//0-1 Knapsack
//Link:https://practice.geeksforgeeks.org/problems/0-1-knapsack-problem/0
// Returns the maximum value that  
// can be put in a knapsack of capacity W 

// METHOD 1 Recursion
int knapSack(int W, int wt[], int val[], int n) 
{ 
   // Your code here
   
   //Thinking of a smallest valid input (Base condition)
    if(W==0 || n==0)
        return 0;
    
    // Return the maximum of two cases: 
    // (1) nth item included 
    // (2) not included 
    else if(wt[n-1]<=W){
        return max(val[n-1]+knapSack(W-wt[n-1],wt,val,n-1),
                       knapSack(W,wt,val,n-1));
    }
    
    // If weight of the nth item is more 
    // than Knapsack capacity W, then 
    // this item cannot be included 
    // in the optimal solution 
    else
        return  knapSack(W,wt,val,n-1);
}

#include<bits/stdc++.h>
using namespace std;


 // } Driver Code Ends


//Method 2: Using Bottom-up Method (By using recursion)
//Making 2D array as two parameters changes in given recursion above

int knapSack(int W, int wt[], int val[], int n) 
{ 
   // Your code here
   
    int dp[n+1][W+1];
    
    for(int i=0;i<=n;i++){
        for(int w=0;w<=W;w++){
			/*By base condition in recursion method */
            if(i==0 || w==0)
                dp[i][w]=0;
			// Return the maximum of two cases: 
			// (1) nth item included 
			// (2) not included 
            else if(wt[i-1]<=w){
                dp[i][w]=max(val[i-1]+dp[i-1][w-wt[i-1]],
                                dp[i-1][w]);
            }
			// If weight of the nth item is more 
			// than Knapsack capacity W, then 
			// this item cannot be included 
			// in the optimal solution 
            else
                dp[i][w]=dp[i-1][w];
        }
    }
    return dp[n][W];
}





