//#define India

#ifndef India
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

ll x=-1,kk=-1;
bool jpo=false;
void dfs(ll s, vector<bool> &v, vector<ll> &pr, vector<ll> adj[]){
    if(v[s]) return;
    v[s]=true;
    //cout<<s+1<<" ";
    for(auto u: adj[s]){
        if(!v[u]){
            pr[u]=s;
            //cout<<u<<" ";
            dfs(u,v,pr,adj);}
        else{
            if(!jpo&&pr[s]!=u){jpo=true;x=u;kk=s;}
        }
    }
}
ll binomialCoeff(ll n, ll k){
   ll C[n + 1][k + 1];ll i, j;
   for (i = 0; i <= n; i++){
       for (j = 0; j <= min(i, k); j++){
           if (j == 0 || j == i){C[i][j] = 1;}
           else{C[i][j] = (C[i - 1][j - 1] + C[i - 1][j]);}}}
   return C[n][k];
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

ll modinv(ll x, ll mod) { return modexp(x, mod - 2, mod); }
const int Nx=1e6+5;
ll fact[Nx];
void factorial(){fact[0]=1;
    for(int i=1;i<Nx;i++)
    {
        fact[i]=(fact[i-1]*i)%d7;
    }
    return ;}
ll binomial(ll a,ll b,ll mod){
    return ((fact[a]*modinv(fact[b],mod))%mod*modinv(fact[a-b],mod))%mod;}

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

ll st[200010][30];
ll loge2[200001];
void logify(){
loge2[1] = 0;
for (ll i = 2; i <= 200001; i++)
    loge2[i] = loge2[i/2] + 1;
}

int main(){
    
    ll n,q;
    cin>>n>>q;
    ll a[n];
    fori(n) cin>>a[i];
    fori(n){
        st[i][0]=a[i];
    }
    ll k=log2(n);
    for(ll i=1;i<=k+1;i++){
        for(ll p=0;p+ (1<<i) <=n;p++ ){
            st[p][i]= min(st[p][i-1], st[p+(1<<(i-1))][i-1]);
        }
    }
    logify();
    fori(q){
        ll x,y;
        cin>>x>>y;x--;y--;
        ll op=loge2[y-x+1];
        ll kl=min(st[x][op],st[y-(1<<op)+1][op]);
        cout<<kl<<endl;
    }
    
    return 0;
}
