//#define LOCAL

#ifndef LOCAL
#include <bits/stdc++.h>
#else
#include "total.h"
#endif
#define fori(n) for(long long i=0;i<n;i++)
#define forr(i,x,y) for(long long i=x;i<y;i++)
#define forj(n) for(long long j=0;j<n;j++)
#define ll long long
#define d7 1000000007
#define en cout<<"\n";

using namespace std;

void dfs(ll s, vector<bool> &v, vector<ll> adj[]){
    if(v[s]) return;
    v[s]=true;
    //cout<<s+1<<" ";
    for(auto u: adj[s]){
        if(!v
           [u]){
            dfs(u,v,adj);}
    }
}
void bfs(vector<ll> &dis, vector<ll> adj[], ll s, vector<ll> &parent){
    dis[s]=0;
    //parent[s]=-1;
    queue<ll> q;
    q.push(s);
    while(!q.empty()){
        ll z=q.front();
        //cout<<z<<" ";
        q.pop();
        for(auto v:adj[z]){
            if(dis[v]==0){
            q.push(v);
            dis[v]=dis[z]+1;
                parent[v]=z;
            }
        }
    }
}

ll modexp(ll x, ll n,ll m){
    if(n==0) return 1%m;
    ll u=modexp(x,n/2,m);
    u=(u*u)%m;
    if(n%2==1) u=(u*x)%m;
    return u;
}

ll gcd(ll a, ll b){
    if(b==0) return a;
    return gcd(b, a%b);
}

tuple<ll,ll,ll,ll> expA(tuple<ll,ll,ll,ll> v, ll n){
    if(n==0){return {1,0,1,0};}
    if(n==1){return v;}
        ll x1,y1,z1,w1;
        ll x2,y2,z2,w2;
        tie(x1,y1,z1,w1) = expA(v, n/2);
        x2=(x1*x1+y1*z1)%d7;
        y2=(x1*y1+y1*w1)%d7;
        z2=(z1*x1+w1*z1)%d7;
        w2=(z1*y1+w1*w1)%d7;
    if(n%2==0){
        return {x2,y2,z2,w2};
    }
    else{
        return {x2+z2,y2+w2,x2,y2};
    }
}

int main(){
    
    ll n=4;
    ll k;
    cin>>k;
    vector<ll> a(n,1);
    a[3]=0;
    ll v1,v2,v3,v4;
    tie(v1,v2,v3,v4)=expA({a[0],a[1],a[2],a[3]}, k);
    cout<<v2%d7<<"\n";
    
    return 0;
}
