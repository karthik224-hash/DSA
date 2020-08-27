//Express as a power b
//Link:https://www.hackerrank.com/contests/smart-interviews/challenges/si-express-as-a-power-b/problem


#include<bits/stdc++.h>
using namespace std;
typedef long long int ll;
int main(){
    ll t;
    scanf("%lld",&t);
    unordered_map<ll,ll>mp;
	//Precompute all the values of the power and store it...
    for(ll i=2 ; i<10001 ; i++) {
        ll res=i*i;        
        while(res<=100000000) {
            mp[res]++;
            res*=i;
        }
    }
    while(t--){
        ll n;
        scanf("%lld",&n);
        if(n==1)
            printf("No\n");
        else if(mp.find(n)!=mp.end())
            printf("Yes\n");
        else
            printf("No\n");
    }
}