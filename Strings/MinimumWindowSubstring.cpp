#include<bits/stdc++.h>
using namespace std;
// link: https://leetcode.com/problems/minimum-window-substring/submissions/

    /*
    To check if a window is valid, we use a map to store (char, count) for chars in t. And use counter for the number of chars of t to be found in s. The key part is m[s[end]]--;. We decrease count for each char in s. If it does not exist in t, the count will be negative.*/
    string minWindow(string s, string t) {
        vector<int> m(128,0);
        for(auto c:t) m[c]++;
        int start,end,minStart,minLen=INT_MAX;
        start=end=minStart=0;
        int counter=t.size();
        while(end<s.size()){
            if(m[s[end]]>0){
                counter--;
            }
            m[s[end]]--;
            end++;
            //a valid window is reached now minimizing it
            while(counter==0){
                //updating the better answer
                if(end-start<minLen){
                    minLen=end-start;
                    minStart=start;
                }
                //resetting the char of s in map
                m[s[start]]++;
                //if window becomes invalid the next loop breaks
                if(m[s[start]]>0) counter++;
                start++;
            }
        }
        return (minLen==INT_MAX)?"":s.substr(minStart,minLen);
        
    }
