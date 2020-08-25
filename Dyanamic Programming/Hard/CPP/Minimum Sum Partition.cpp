//Minumum Sum Partition
//Link:https://practice.geeksforgeeks.org/problems/minimum-sum-partition/0
Method 1: Recursion
#include <bits/stdc++.h>
using namespace std;
#define int long long 
/*
    let us consider the two partitions namely S1,S2;
    Name the sum of all elements as range
    Now we have to check the partition such that S1-S2==Minimum
    From this we can conclude Range-2*S1 must be min
    We can include or exclude the element Same as the Subset sum
*/
int MinSum(int a[],int n,int sum,int range){
    if(n==0)
        return abs(range-2*sum);
    // For every item a[i], we have two choices 
    // (1) We do not include it first set 
    // (2) We include it in first set 
    // We return minimum of two choices 
    return min(MinSum(a,n-1,sum+a[n-1],range),
                MinSum(a,n-1,sum,range));
}
int32_t main() {
	//code
	int t;cin>>t;
	while(t--){
	    int n;
	    cin>>n;
	    int a[n],range=0;
	    for(int i=0;i<n;i++){
	        cin>>a[i];
	        range+=a[i];
	    }
	    int res=MinSum(a,n,0,range);
	    cout<<res<<"\n";
	}
	return 0;
}


Method 2: DP

#include <bits/stdc++.h>
using namespace std;
#define int long long 
/*
    let us consider the two partitions namely S1,S2;
    Name the sum of all elements as range
    Now we have to check the partition such that S1-S2==Minimum
    From this we can conclude Range-2*S1 must be min
    We can include or exclude the element Same as the Subset sum
*/
int MinSum(int a[],int n,int range){
    bool dp[n+1][range+1];
    //Similar to Subset Sum
    for(int i=0;i<=n;i++)
        dp[i][0]=1;
    for(int j=1;j<=range;j++)
        dp[0][j]=0;
    for(int i=1;i<=n;i++){
        for(int j=1;j<=range;j++){
            dp[i][j]=dp[i-1][j];
            if(j>=a[i-1])
                dp[i][j]|=dp[i-1][j-a[i-1]];
        }
    }
    int res=INT_MAX;
    for(int j=0;j<=range/2;j++){
        if(dp[n][j])
            res=min(res,range-2*j);
    }
    return res;
}
int32_t main() {
	//code
	int t;cin>>t;
	while(t--){
	    int n;
	    cin>>n;
	    int a[n],range=0;
	    for(int i=0;i<n;i++){
	        cin>>a[i];
	        range+=a[i];
	    }
	    int res=MinSum(a,n,range);
	    cout<<res<<"\n";
	}
	return 0;
}