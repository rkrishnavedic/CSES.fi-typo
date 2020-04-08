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
void bfs(vector<ll> &dis, vector<ll> adj[], ll s, bool &b){
    dis[s]=-1;
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
            dis[v]=-dis[z];
                //parent[v]=z;
            }
            else{
                    if(dis[v]==dis[z]){
                        b=false;
                    }
                }
        }
    }
}

int main(){
    ios_base::sync_with_stdio(false);
    
    ll n,k;
    cin>>n>>k;
    vector<ll> adj[n];
    
    fori(k){
        ll x,y;
        cin>>x>>y;
        adj[x-1].push_back(y-1);
        adj[y-1].push_back(x-1);
    }
    //ll cn=0;
   // vector<bool> vis(n,false);
    vector<ll> dis(n,0);
    bool gh=true;
    fori(n){
        if(dis[i]==0){
            bfs(dis, adj, i, gh);
        }
        if(!gh){break;}
    }
    
    if(gh){
        fori(n){cout<<(dis[i]==-1? 1:2)<<" ";}
    }else{
        cout<<"IMPOSSIBLE";
    }

    return 0;
}
