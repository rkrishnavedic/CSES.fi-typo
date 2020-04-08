#include <bits/stdc++.h>
//#include "total.h"

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
void bfs(vector<ll> &dis, vector<ll> adj[], ll s, vector<ll> &parent){
    dis[s]=0;
    parent[s]=-1;
    queue<ll> q;
    q.push(s);
    while(!q.empty()){
        ll z=q.front();
        //cout<<z<<" ";
        q.pop();
        for(ll v:adj[z]){
            if(dis[v]==-1){
            q.push(v);
            dis[v]=dis[z]+1;
                parent[v]=z;}
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
    vector<bool> vis(n,false);
    vector<ll> vc;

    fori(n){
        if(!vis[i]){
        vc.push_back(i+1);
            dfs(i, vis, adj);}
    }
    cout<<vc.size()-1<<endl;
    fori(vc.size()-1){
        cout<<vc[i]<<" "<<vc[i+1]<<endl;
    }

    return 0;
}
