//Count the Triangles
//Link:https://www.hackerrank.com/contests/smart-interviews/challenges/si-count-the-triangles/problem

//Method 1: Brute Force ...

int cntNoTrg(int a[],int n){
    int cnt=0;
    for(int i=0;i<n-2;i++){
        for(int j=i+1;j<n-1;j++){
            for(int k=j+1;k<n;k++){
                if(a[i]+a[j]>a[k] && a[j]+a[k]>a[i] && a[k]+a[i]>a[j])
                    cnt+=1;
            }
        }
    }
    return cnt;
}

//Method 2:By Sorting and Two Pointers

int cntNoTrg(int a[],int n){
    int cnt=0;
    sort(a,a+n);
    /*using Two Pointers*/
    for(int i=n-1;i>=0;i--){
        int l=0,r=i-1;
        while(l<r){
            if(a[l]+a[r]>a[i]){
                /*
                    If it is possible with a[l], a[r] and a[i] then it is
                    also possible with a[l+1]..a[r-1], a[r] and a[i] 
                    Basically fixing r and i
                */
                cnt+=r-l;
                r--;
            }
            else    
                l++;
        }
    }
    return cnt;
}