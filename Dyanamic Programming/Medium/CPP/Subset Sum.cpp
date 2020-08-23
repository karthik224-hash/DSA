//Subset Sum
//Link:https://www.hackerrank.com/contests/smart-interviews/challenges/si-subset-sum

//Method 1 : BackTracking
bool subsets(int arr[],int n,int sum){
    //Base Condition Check if sum is zero or not
    
    if(sum==0)            return true;
    
    if(n==0 && sum!=0)    return false;
    
    /*Check for two conditions 
        Whether to include or not  Similar to Knapsack problem*/
    
    return subsets(arr,n-1,sum-arr[n-1])||subsets(arr,n-1,sum);
}


//Method  2: DP

bool subsets(int arr[],int n,int sum){
    int dp[n+1][sum+1];
    //Fill the first col with 1 as 0 is subset sum of every no.
    for(int i=0;i<=n;i++)
        dp[i][0]=1;
    //Fill the first row with 0
    for(int i=1;i<=sum;i++)
        dp[0][i]=0;
    for(int i=1;i<=n;i++){
        for(int j=1;j<=sum;j++){
            //Check two cases include or exclude 
            if(j>=arr[i-1])
                dp[i][j]=dp[i-1][j]+dp[i-1][j-arr[i-1]];
            else
                dp[i][j]=dp[i-1][j];
        }
    }
    return dp[n][sum];
}