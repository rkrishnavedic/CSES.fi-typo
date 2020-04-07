#include <bits/stdc++.h>
//#include "total.h"

#define fori(n) for(long long i=0;i<n;i++)
#define forr(i,x,y) for(long long i=x;i<y;i++)
#define forj(n) for(long long j=0;j<n;j++)
#define ll long long int
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

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    
    ll n;
    cin>>n;
    ll k;
    cin>>k;
    vector<bool> vis(n*k,false);
    string s[n];
    fori(n) cin>>s[i];
    vector<ll> adj[k*n];
    fori(n){
        forj(k){
            if(s[i][j]=='.'){
                if(i>0&&s[i-1][j]=='.'){adj[(i-1)*k+j].push_back(i*k+j);}
                if(j>0&&s[i][j-1]=='.'){adj[(i)*k+j-1].push_back(i*k+j);}
                if(i<n-1&&s[i+1][j]=='.'){adj[(i+1)*k+j].push_back(i*k+j);}
                  if(j<k-1&&s[i][j+1]=='.'){adj[(i)*k+j+1].push_back(i*k+j);}
            }else{
                vis[i*k+j]=true;
            }
        }
    }
    ll kl=0;
    fori(n*k){
        if(!vis[i]){
            kl++;
            dfs(i, vis, adj);
        }
    }
    cout<<kl;
    
    return 0;
}
