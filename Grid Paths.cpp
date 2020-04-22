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

bool isPrime(long long k){
    if(k<=1){return false;}
    if(k==2){return true;}
    if(k%2==0){return false;}
    long long i = 3;
   while (i*i <= k) {if (k % i == 0) {return false;}i += 2;}
return true;
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

//ll st[200010][30];
//ll loge2[200001];
//void logify(){
//loge2[1] = 0;
//for (ll i = 2; i <= 200001; i++)
//    loge2[i] = loge2[i/2] + 1;
//}


int main(){
    
    ll n;
    cin>>n;
    string s;
    map<pair<ll,ll>,bool> mp;
    fori(n){
        cin>>s;
        forj(n){if(s[j]=='*') mp[{i,j}]=1;
        }
        s.clear();
    }
    if(mp[{0,0}] || mp[{n-1,n-1}]){cout<<0;}
    else{
        vector<vector<ll> > dp(n,vector<ll>(n,0));
        forj(n){
            if(!mp[{0,j}]){dp[0][j]=1;}
            else{break;}
        }
        forj(n){
            if(!mp[{j,0}]){dp[j][0]=1;}
            else{break;}
        }
        for(ll i=1;i<n;i++){
            for(ll j=1;j<n;j++){
                if(!mp[{i,j}]){
                    (dp[i][j]+=dp[i-1][j]+dp[i][j-1])%=d7;
                }
                //cout<<dp[i][j]<<" ";
            }//en;
        }
        cout<<dp[n-1][n-1];
    }
    
    
    return 0;
}
