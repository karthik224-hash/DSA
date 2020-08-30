//Fibonacci 
//Link:https://www.hackerrank.com/contests/smart-interviews/challenges/si-fibonacci-series/problem
Method 1:DP
#include<bits/stdc++.h>
using namespace std;
#define mod 1000000007
#define int long long 
int32_t main(){
    int t;
    cin>>t;
    vector<int>fib;
    fib.push_back(1);
    fib.push_back(1);
    for(int i=2;i<=10000000;i++){
        fib.push_back(((fib[i-1])%mod+(fib[i-2])%mod)%mod);
    }
    while(t--){
        int n;
        cin>>n;
        cout<<fib[n]<<"\n";
    }
    return 0;
}
Method 2:Matrix Exponentation
#include<bits/stdc++.h>
using namespace std;
#define mod 1000000007
#define int long long 
void multiply(int res[2][2],int temp[2][2]){
    int a=((res[0][0]*temp[0][0])%mod+(res[0][1]*temp[1][0])%mod)%mod;
    int b=((res[0][0]*temp[0][1])%mod+(res[0][1]*temp[1][1])%mod)%mod;
    int c=((res[1][0]*temp[0][0])%mod+(res[1][1]*temp[1][0])%mod)%mod;
    int d=((res[1][0]*temp[0][1])%mod+(res[1][1]*temp[1][1])%mod)%mod;
    res[0][0]=a;
    res[0][1]=b;
    res[1][0]=c;
    res[1][1]=d;
}
void power(int res[2][2],int n){
    if(n==0 || n==1)
        return;
    int temp[2][2]={{1,1},{1,0}};
    power(res,n/2);
    multiply(res,res);
    if(n%2)
        multiply(res,temp);
}
int fib(int n){
    int res[2][2]={{1,1},{1,0}};
    if(n==0 || n==1)
        return 1;
    power(res,n-1);
    return (res[0][0]+res[0][1])%mod;
}

int32_t main(){
    int t;
    cin>>t;
    while(t--){
        int n;
        cin>>n;
        cout<<(fib(n))%mod<<"\n";
    }
    return 0;
}
