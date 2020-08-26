// Link: https://leetcode.com/problems/greatest-sum-divisible-by-three/
/*Problem
  Given an array nums of integers, we need to find the maximum possible sum of elements of the array such that it is divisible by three.
  Input: nums = [3,6,5,1,8]
  Output: 18
  Explanation: Pick numbers 3, 6, 1 and 8 their sum is 18 (maximum sum divisible by 3).*/
int maxSumDivThree(vector<int> &nums)
{
    vector<int> dp = {0, 0, 0}, dp1;
    for (auto a : nums)
    {
        dp1 = dp;
        //for every no a in vector nums we will
        //add it to the maximum sum upto 'a' with remainder i
        //and we will replace the no. which is maximum compared
        //to the i+a and already max no. present at dp at remainder(i+a)
        for (auto i : dp1)
        {
            dp[(i + a) % 3] = max(dp[(i + a) % 3], i + a);
        }
    }
    //returning the max subset Sum which is divisble by 3
    return dp[0];
}