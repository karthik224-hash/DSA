//Quadruples of XOR

//Link:https://www.hackerrank.com/contests/smart-interviews/challenges/si-quadruples-of-xor

Method 1:

#include<bits/stdc++.h>
using namespace std;
typedef long long int ll;
int main() {
    /* Enter your code here. Read input from STDIN. Print output to STDOUT */   
    ll t;
    cin>>t;
    while(t--){
        int n;
        cin>>n;
        int a[n],b[n],c[n],d[n];
        for(int i=0;i<n;i++)
            cin>>a[i];
        for(int i=0;i<n;i++)
            cin>>b[i];
        for(int i=0;i<n;i++)
            cin>>c[i];
        for(int i=0;i<n;i++)
            cin>>d[i];
        ll cnt=0;
        for(int i=0;i<n;i++){
            for(int j=0;j<n;j++){
                for(int k=0;k<n;k++){
                    for(int l=0;l<n;l++){
                        int res=a[i]^b[j]^c[k]^d[l];
                        if(res==0)
                            cnt++;
                    }
                }
            }
        }
        cout<<cnt<<"\n";
    }
    return 0;
}


Method 2:

#include<bits/stdc++.h>
using namespace std;
typedef long long int ll;
int main() {
    /* Enter your code here. Read input from STDIN. Print output to STDOUT */   
    ll t;
    scanf("%d",&t);
    while(t--){
        int n;
        scanf("%d",&n);
        int a[n],b[n],c[n],d[n];
        for(int i=0;i<n;i++)
            scanf("%d",&a[i]);
        for(int i=0;i<n;i++)
            scanf("%d",&b[i]);
        for(int i=0;i<n;i++)
            scanf("%d",&c[i]);
        for(int i=0;i<n;i++)
            scanf("%d",&d[i]);
        ll cnt=0;
        vector<ll>x;
        vector<ll>y;
        for(int i=0;i<n;i++){
            for(int j=0;j<n;j++){
                x.push_back(a[i]^b[j]);
                y.push_back(c[i]^d[j]);
            }
        }
        sort(x.begin(),x.end());
        for(int i=0;i<y.size();i++){
			/*c1 gives the first index of the element
            auto c1=lower_bound(x.begin(),x.end(),y[i]);
			/*c2 gives the next index after that element
            auto c2=upper_bound(x.begin(),x.end(),y[i]);
            cnt+=c2-c1;
        }
        printf("%lld\n",cnt);
    }
    return 0;
}


Method 3:

#include<bits/stdc++.h>
using namespace std;
typedef long long int ll;
int main() {
    /* Enter your code here. Read input from STDIN. Print output to STDOUT */   
    ll t;
    scanf("%d",&t);
    while(t--){
        int n;
        scanf("%d",&n);
        int a[n],b[n],c[n],d[n];
        for(int i=0;i<n;i++)
            scanf("%d",&a[i]);
        for(int i=0;i<n;i++)
            scanf("%d",&b[i]);
        for(int i=0;i<n;i++)
            scanf("%d",&c[i]);
        for(int i=0;i<n;i++)
            scanf("%d",&d[i]);
        ll cnt=0;
        map<ll,ll>x;
        map<ll,ll>y;
        for(int i=0;i<n;i++){
            for(int j=0;j<n;j++){
                x[a[i]^b[j]]++;
                y[c[i]^d[j]]++;
            }
        }
        for(auto i=x.begin();i!=x.end();i++){
            auto j=y.find(i->first);
            if(j!=y.end())
                cnt=cnt+(j->second)*(i->second);
        }
        printf("%lld\n",cnt);
    }
    return 0;
}
