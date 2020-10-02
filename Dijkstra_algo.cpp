//




#include <bits/stdc++.h>
using namespace std;


#define spdio ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
#define pb push_back
#define pp pop_back()
#define pf push_front
#define ppf pop_front()
#define ff first
#define ss second
#define mp make_pair
#define fr(i,j,n) for(ll i=j; i<n; i++)
#define rfr(i,j,n) for(ll i=n-1; i>=j; i--)
#define pll pair<ll,ll>
#define plb pair<ll,bool>
#define psl pair<string,ll>
#define psb pair<string,bool>
#define srt(v) sort((v).begin(),(v).end())
#define ub(v,val) upper_bound((v).begin(),(v).end(),(val))-(v).begin()
#define lb(v,val) lower_bound((v).begin(),(v).end(),(val))-(v).begin()


typedef long double ld;
typedef long long int ll;


//getline(cin,string);
const ll inf = (ll) 1e18 + 19;
const ll mod = (ll) 1e9  +  7;




ll ncr(ll n,ll r) {
    ll val=1,i,j,p=2;
    rfr(i,n-r+1,n+1) {
        val*=i;
        while(val%p==0 && p<=r) {
            val/=p;
            p+=1;
        }
    }
    if(p<r) {
        fr(i,p,r+1) val/=i;
    }
    return val;
}




void cazz() {
    ll t=1,i=0,j,n;
    cin>>t;
    while(t--) {
        ll m,a,b,c;
        cin>>n>>m;
        ll dist[n+1],vis[n+1]={},k;
        fr(i,2,n+1) dist[i]=inf;
        dist[1]=0;
        vector <pll> v[n+1];
        fr(i,0,m) {
            cin>>a>>b>>c;
            v[a].pb({b,c});
        }
        priority_queue <pll> q;
        q.push({0,1});
        while(!q.empty()) {
            ll val=q.top().ss;
            q.pop();
            vis[val]=true;
            for(auto it: v[val]) {
                dist[it.ff]=min(dist[it.ff],dist[val]+it.ss);
                if(!vis[it.ff]) q.push({-dist[it.ff],it.ff});
            }
        }
        bool f=0;
        fr(i,1,n+1) {
            f=0;
            for(auto it: v[i]) {
                if(dist[it.ff]>dist[i]+it.ss) {
                    cout<<"The graph has negetive cycle.\n";
                    f=1;
                    break;
                }
            }
            if(f) break;
        }
        if(f) continue;
        fr(i,1,n+1) cout<<dist[i]<<' ';
    }
}




int main() {
    spdio;
	cazz();
	return 0;
}

