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
    
//    ll n,k;
//    cin>>n>>k;
//    vector<ll> adj[n];
//
//    fori(k){
//        ll x,y;
//        cin>>x>>y;
//        adj[x-1].push_back(y-1);
//        adj[y-1].push_back(x-1);
//    }
//    ll no=-1;
//    vector<bool> vis(n,false);
//    vector<ll> dis(n,0);
//    vector<pair<ll,ll>> parent(n,{-1,-1});
   
    ll n,k;
    cin>>n>>k;
    vector<pair<ll,ll>> v;
    ll x;
    fori(n){cin>>x;v.push_back({x,i});}
    sort(v.begin(), v.end());
    vector<ll> s;
    fori(n) s.push_back(v[i].first);
    fori(n){
        ll u=k-v[i].first;
        vector<ll>::iterator it;
        it=lower_bound(s.begin(), s.end(), u);
        ll ui=it-s.begin();
        if(it!=s.end()&&s[ui]==u){
            if(v[ui].second!=v[i].second){
                cout<<v[ui].second+1<<" "<<v[i].second+1;return 0;
            }else{
                if((ui<n-1)&&s[ui+1]==u){
                    cout<<v[ui+1].second+1<<" "<<v[i].second+1;return 0;
                }else{
                    if(ui>0&&s[ui-1]==u){
                        cout<<v[ui-1].second+1<<" "<<v[i].second+1;return 0;
                    }else{
                        continue;
                    }
                }
            }
        }
    }
    cout<<"IMPOSSIBLE";

    return 0;
}
