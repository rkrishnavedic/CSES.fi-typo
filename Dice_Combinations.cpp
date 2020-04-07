#include <bits/stdc++.h>
//#include "total.h"
 
#define fori(n) for(long long i=0;i<n;i++)
#define forr(i,x,y) for(long long i=x;i<y;i++)
#define forj(n) for(long long j=0;j<n;j++)
#define ll long long int
#define MOD 1000000007
 
using namespace std;
 
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    
    ll n;
    cin>>n;
    ll k;
    k=max(n+1,(ll)7);
    vector<ll> v(k,0);
    v[1]=1;
    v[2]=2;
    v[3]=4;
    v[4]=8;
    v[5]=16;
    v[6]=32;
    forr(i,7,n+1){
        ll x=1;
        while(x<7){
            v[i]=(v[i]+v[i-x])%MOD;
            x++;
        }
    }
    cout<<v[n];
    
    return 0;
}
