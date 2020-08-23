  /*
  Given an integer array of size n, find all elements that appear more than ⌊ n/3 ⌋ times.
  Note: The algorithm should run in linear time and in O(1) space.

  Input: [1,1,1,3,3,2,2,2]
  Output: [1,2]
  */
  
  vector<int> majorityElement(vector<int>& a) {
        int first=INT_MAX,second=INT_MAX;
        int cnt1=0,cnt2=0;
        for(int i=0;i<a.size();i++){
            if(first==a[i])
                cnt1++;
            else if(second==a[i])
                cnt2++;
            else if(cnt1==0){
                cnt1=1;
                first=a[i];
            }
            else if(cnt2==0){
                cnt2=1;
                second=a[i];
            }else{
                cnt1--;
                cnt2--;
            }
        }
        cnt1=cnt2=0;
        for(int i=0;i<a.size();i++){
            if(a[i]==first) cnt1++;
            else if(a[i]==second) cnt2++;
        }
        vector<int> res;
        if(cnt1>a.size()/3) res.push_back(first);
        if(cnt2>a.size()/3) res.push_back(second);
        return res;
    }