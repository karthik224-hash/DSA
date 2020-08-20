//Merge Overlapping Intervals
//Link:https://leetcode.com/problems/merge-intervals/
class Solution {
public:
    vector<vector<int>> merge(vector<vector<int>>& intervals) {
        vector<vector<int>>res;
        
        /*sort the 2-D vector so that we can iterate  array in O(n) */
        
        if(intervals.empty())
            return res;
        
        sort(intervals.begin(),intervals.end());
        vector<int>temp=intervals[0];
        for(auto i:intervals){
            if(temp[1]>=i[0]){
                temp[1]=max(temp[1],i[1]);
            }
            else{
                res.push_back(temp);
                temp=i;
            }
        }
        res.push_back(temp);
        return res;
    }
};
