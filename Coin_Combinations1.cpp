#include <bits/stdc++.h>
//#include "total.h"
 
#define fori(n) for(long long i=0;i<n;i++)
#define forr(i,x,y) for(long long i=x;i<y;i++)
#define forj(n) for(long long j=0;j<n;j++)
#define ll long long int
#define d7 1000000007
 
using namespace std;
 
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    
    ll n;
    cin>>n;
    ll k;
    cin>>k;
    vector<ll> v(1000007,0);
    v[0]=0;
    ll cn[n];
    fori(n) cin>>cn[i];
    fori(n){
        v[cn[i]]=1;
    }
    for(ll i=1;i<=k;i++){
        forj(n){
            if(i>=cn[j]){
                v[i]=(v[i]+(v[i-cn[j]]!=0? (v[i-cn[j]]) : 0))%d7;
            }
        }
        //cout<<v[i]<<" ";
    }
    cout<<v[k];
    
    return 0;
}
