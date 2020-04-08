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

using namespace std;

void dfs(ll s, vector<bool> &v, vector<ll> adj[]){
    if(v[s]) return;
    v[s]=true;
    //cout<<s+1<<" ";
    for(auto u: adj[s]){
        dfs(u,v,adj);
    }
}
void bfs(vector<ll> &dis, vector<ll> adj[], ll s, vector<pair<ll,ll>> &parent, ll no){
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
                parent[v].first=z;
            }
            else{
                        no=v;
                }
        }
    }
}

int main(){
    ll n;
    cin>>n;
    ll a[n];
    fori(n){
        cin>>a[i];
    }
    bool p=false;
    
    fori(n) if(a[i]>=0){p=true;break;}
    if(!p){
        ll m=-d7;
        fori(n) m=max(m,a[i]);
        cout<<m;
    }else{
        ll sum=0;
        ll mx=a[0];
        fori(n){
            if(sum<0){sum=a[i];}
            else{sum+=a[i];}
            mx=max(sum,mx);
        }
        cout<<mx;
    }

    return 0;
}
