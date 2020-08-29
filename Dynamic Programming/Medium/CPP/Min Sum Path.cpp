
//	Minimum Sum Path
// Link:https://leetcode.com/problems/minimum-path-sum/
class Solution
{
public:
    int minPathSum(vector<vector<int>> &grid)
    {
        int rows = grid.size(), col = grid[0].size();
        vector<vector<int>> dp(rows, vector<int>(col, 0));

        //First element is the starting point

        dp[0][0] = grid[0][0];

        //Fill the first row

        for (int i = 1; i < col; i++)
        {
            dp[0][i] = dp[0][i - 1] + grid[0][i];
        }

        //Fill the first column

        for (int i = 1; i < rows; i++)
        {
            dp[i][0] = dp[i - 1][0] + grid[i][0];
        }

        // For the other cells in the matrix it has two choices

        for (int i = 1; i < rows; i++)
        {
            for (int j = 1; j < col; j++)
            {
                dp[i][j] = grid[i][j] + min(dp[i - 1][j], dp[i][j - 1]);
            }
        }

        return dp[rows - 1][col - 1];
    }
};