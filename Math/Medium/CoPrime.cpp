//CoPrime
//Link:https://atcoder.jp/contests/abc177/tasks/abc177_e
#include<bits/stdc++.h>
using namespace std;
#define FIO ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0)
#define int long long
int gcd(int a,int b){
 	if(b==0) 
  		return a;
  	return gcd(b,a%b);
} 
bool setwise_coprime(int a[],int n){
  	int res=a[0];
  	for(int i=1;i<n;i++)
      	res=gcd(a[i],res);
  	if(res==1)
      return true;
  	else
      return false;
}
bool pairwise_coprime(int a[],int n){
  	map<int,int>mp;
  	for(int i=0;i<n;i++){
      int x=a[i];
      for(int j=2;j*j<=x;j++){
          if(x%j==0){
              mp[j]++;
              while(x%j==0)
                  x/=j;
          }
      }
      if(x!=1)
        mp[x]++;
  	}
      for(auto i:mp)
      {
        if(i.second>=2)
            return false;
      }
      return true;
}
int32_t main(){
      FIO;
      int n;cin>>n;
      int a[n];
      for(int i=0;i<n;i++)
        cin>>a[i];
      if(pairwise_coprime(a,n))
        cout<<"pairwise coprime"<<"\n";
      else if(setwise_coprime(a,n))
        cout<<"setwise coprime"<<"\n";
      else
        cout<<"not coprime"<<"\n";
      return 0;
}
