//Link: https://leetcode.com/problems/number-of-dice-rolls-with-target-sum/
/*
You have d dice, and each die has f faces numbered 1, 2, ..., f.

Return the number of possible ways (out of fd total ways) modulo 10^9 + 7 to roll the dice so the sum of the face up numbers equals target.

Input: d = 1, f = 6, target = 3
Output: 1
Explanation: 
You throw one die with 6 faces.  There is only one way to get a sum of 3.
*/
//By Recursion
int numRollsToTarget(int d, int f, int target, int res = 0)
{
    if (d == 0 || target <= 0)
        return d == target;
    for (auto i = 1; i <= f; ++i)
        res = (res + numRollsToTarget(d - 1, f, target - i, 0)) % 1000000007;
    return res;
}
//Bottom up
int numRollsToTarget(int d, int f, int target)
{
    const int M = 1e9 + 7;
    int t[d + 1][target + 1];
    for (int i = 0; i < d + 1; i++)
    {
        for (int j = 0; j < target + 1; j++)
        {
            //if d=0 and target =0 then ans is 1
            //if d=0 and target>0 then ans is 0
            //if d>0 and target=0 then ans is 0 (because the quesion requires to use up every die)
            if (i == 0 || j == 0)
            {
                t[i][j] = (j == 0 && i == 0) ? 1 : 0;
            }
            else
            {
                //initializing
                t[i][j] = 0;
                //for every face if it is less than target sum j then
                //t[i][j]= t[i][j] +  t[i-1][j-k] (with only i-1 dice the no of ways of getting j-k sum)
                for (int k = 1; k <= f && k <= j; k++)
                {
                    t[i][j] = (t[i][j] + t[i - 1][j - k] % M) % M;
                }
            }
        }
    }
    return t[d][target];
}
