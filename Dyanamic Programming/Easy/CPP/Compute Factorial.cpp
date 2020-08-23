
//ComputeFactorial
//Link:https://www.hackerrank.com/contests/smart-interviews/challenges/si-compute-factorial
#include<bits/stdc++.h>
using namespace std;
void ComputeFactorial(vector<long long int>&fact){
    fact[0]=1;
    fact[1]=1;
    int mod=1e9+7;
    for(int i=2;i<=1e6;i++)
        fact[i]=(fact[i-1]*i)%mod;
}
int main(){
    ios_base::sync_with_stdio(0); 
    cin.tie(0);
    cout.tie(0);
    vector<long long int>fact(1e6+6);
    ComputeFactorial(fact);
    int t;
    cin>>t;
    while(t--){
        int n;
        cin>>n;
        cout<<fact[n]<<"\n";
    }
}
