/*Set Matrix Zeroes*/

/* Link:https://leetcode.com/problems/set-matrix-zeroes/solution/ */

class Solution {
public:
    void setZeroes(vector<vector<int>>& matrix) {
        int R=matrix.size(),C=matrix[0].size();
        bool col0=0;
        for(int i=0;i<R;i++){
            
            /*To check the col0 condition */

            if(matrix[i][0]==0) col0=1;
            for(int j=1;j<C;j++){
                
                /*To check the row0 condition*/
                
                if(matrix[i][j]==0)
                    matrix[i][0]=matrix[0][j]=0;
            }
        }
        
        /*On basis of col0 and row0 check whether matrix[i][j] should be zero or not*/
        
        for(int i=R-1;i>=0;i--){
            for(int j=C-1;j>=1;j--){
                if(matrix[i][0]==0 || matrix[0][j]==0)
                    matrix[i][j]=0;
            }
            if(col0)
                matrix[i][0]=0;
        }
    }
};