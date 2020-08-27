//Largest Number
//Link:https://leetcode.com/problems/largest-number/

class Solution {
public:
    string largestNumber(vector<int>& nums) {
        vector<string>res;
        for(int i=0;i<nums.size();i++)
            res.push_back(to_string(nums[i]));
		/*Sorting the string with the 3rd parameter..*/
        sort(res.begin(),res.end(),[](string x,string y){return x+y>y+x;});
        string ans="";
        for(string i:res)
            ans+=i;
        return ans[0]=='0'?"0":ans;
    }
};