//Equal Subset Sum
//Link:https://leetcode.com/problems/partition-equal-subset-sum/
class Solution {
public:
    /*
        Break the problem into knapsack and subset sum
        And any odd number cannot be divided into equal halves
    */
    bool subsetsum(vector<int>& nums,long long int sum,int n){
            int dp[n+1][sum+1];
            for(int i=1;i<=sum;i++){
                dp[0][i]=0;
            }
            for(int i=0;i<=n;i++){
                dp[i][0]=1;
            }
            for(int i=1;i<=n;i++){
                for(int j=1;j<=sum;j++){
                    dp[i][j]=dp[i-1][j];
                    if(j>=nums[i-1])
                        dp[i][j]=dp[i][j] || dp[i-1][j-nums[i-1]];
                }
            }
            return dp[n][sum];
    }
    bool canPartition(vector<int>& nums) {
        long long int sum=0;
        int n=nums.size();
        for(int i=0;i<n;i++){
            sum+=nums[i];
        }
        if(sum%2)
            return false;
        else
            return subsetsum(nums,sum/2,n);
    }
};