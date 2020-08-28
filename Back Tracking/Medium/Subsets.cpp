//Subsets
//Link:https://leetcode.com/problems/subsets/

Method 1:Back Tracking
class Solution {
public:
    void bt(vector<int>&nums,vector<int>&v,vector<vector<int>>&res,int idx){
         //To store the empty set
        if(v.empty())
            res.push_back(v);
        for(int i=idx;i<nums.size();i++){
            v.push_back(nums[i]);
            res.push_back(v);
            bt(nums,v,res,i+1);
            //Pop the last element  in vector V
            v.pop_back();
        }
    }
    vector<vector<int>> subsets(vector<int>& nums) {
        vector<vector<int>>res;
        vector<int>v;
        sort(nums.begin(),nums.end());
        bt(nums,v,res,0);
        return res;
    }
};

Method 2:Bit Manipulation

class Solution {
public:
    /*
        Consider the example nums = [1,2,3]
        Now total no of subsets are 8.
        0---000-----[]
        1---001-----[1]
        2---010-----[2]
        3---011-----[1,2]
        4---100-----[3]
        5---101-----[1,3]
        6---110-----[2,3]
        7---111-----[1,2,3]
        Checking for the set bit and if found then insert the element in it
    */
    vector<vector<int>> subsets(vector<int>& nums) {
        int n=nums.size(),tot=1<<n;
        vector<vector<int>>res(tot);
        for(int i=0;i<tot;i++){
            for(int j=0;j<n;j++){
                if((i>>j)&1){
                    res[i].push_back(nums[j]);
                }
            }
        }
        return res;
    }
};
