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
    cin.tie(NULL);
    
    ll n;
    cin>>n;
    ll k;
    cin>>k;
    string s[n];
    fori(n) cin>>s[i];
    vector<ll> adj[k*n];
    ll s1,e;
    fori(n){
        forj(k){
            if(s[i][j]=='.'||s[i][j]=='A'||s[i][j]=='B'){
                if(s[i][j]=='A') s1=i*k+j;
                if(s[i][j]=='B') e=i*k+j;
                if(i>0&&(s[i-1][j]=='.'||s[i-1][j]=='B'||s[i-1][j]=='A')){adj[(i-1)*k+j].push_back(i*k+j);}
                if(j>0&&(s[i][j-1]=='.'||s[i][j-1]=='A'||s[i][j-1]=='B')){adj[(i)*k+j-1].push_back(i*k+j);}
                if(i<n-1&&(s[i+1][j]=='.'||s[i+1][j]=='A'||s[i+1][j]=='B')){adj[(i+1)*k+j].push_back(i*k+j);}
                  if(j<k-1&&(s[i][j+1]=='.'||s[i][j+1]=='A'||s[i][j+1]=='B')){adj[(i)*k+j+1].push_back(i*k+j);}
            }
        }
    }
    //cout<<s1<<" "<<e<<endl;
    vector<ll> dis(n*k,-1);
    vector<ll> parent(n*k, -1);
    dis[s1]=0;
    bfs(dis,adj,s1,parent);
    if(parent[e]!=-1){
        vector<ll> vb;
        ll op=e;
        while(parent[op]!=-1){
            vb.push_back(op);
            op=parent[op];
        }
        //for(auto u: vb) cout<<u<<" ";
        cout<<"YES\n";
        reverse(vb.begin(), vb.end());
        cout<<vb.size()<<endl;
        fori(vb.size()){
            if(s1+k==vb[i]){cout<<"D";}
            if(s1-k==vb[i]){cout<<"U";}
            if(s1+1==vb[i]){cout<<"R";}
            if(s1-1==vb[i]){cout<<"L";}
            s1=vb[i];
        }
    }else{
        
        cout<<"NO";
    }
    
    return 0;
}
