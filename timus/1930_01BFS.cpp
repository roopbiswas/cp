// In the name of GOD
#include<bits/stdc++.h>
using namespace std;

#define debug(x) cout<<#x<<" :: "<<x<<"\n";
#define debug2(x,y) cout<<#x<<" :: "<<x<<"\t"<<#y<<" :: "<<y<<"\n";
#define debug3(x,y,z) cout<<#x<<" :: "<<x<<"\t"<<#y<<" :: "<<y<<"\t"<<#z<<" :: "<<z<<"\n";

#define     IOS         ios::sync_with_stdio(false);cin.tie(0);cout.tie(0)
#define 	setprecn(x) cout<<fixed<<setprecision(x);
#define 	ll          long long int
#define 	pb          push_back
#define 	pll         pair<ll,ll>
#define 	vll         vector<ll>
#define 	ff          first
#define 	ss          second
#define 	all(a)      (a).begin(),(a).end()
#define 	sz(x)       (ll)x.size()
#define 	mod         1000000007
#define 	inf         10000000000000007
#define 	rep(i,n)    for(ll i=0;i<n;i++)
#define 	repe(i,a,b) for(ll i=a;i<b;i++)
#define 	lbnd        lower_bound
#define 	ubnd        upper_bound
#define 	bs          binary_search

ll power(ll a,ll b,ll m=mod)
{
	if(b==0)
		return 1;
	if(b==1)
		return a;
	ll c=power(a,b/2,m);
	if(b%2==0)
		return((c%m)*(c%m))%m;
	return ((((c%m)*(c%m))%m)*(a%m))%m;
}
/********************************************************/

// **0/1 BFS**
// timus 1930. Ivan's Car
// https://acm.timus.ru/problem.aspx?space=1&num=1930

int main()
{
	// IOS;
	ll n,k,m,i,j,c=0,cs=0,t;
	t=1;

	// cin>>t;
	while(t--)
	{
		cin>>n>>m;
		// n=s.length();
		// ll a[n];
		vector<vector<ll>> gu(n+1),gd(n+1);
		rep(i,m)
		{
			cin>>j>>k;
			gu[j].pb(k);
			gd[k].pb(j);
		}
		ll x,y;
		cin>>x>>y;
		vector<ll> du(n+1,inf),dd(n+1,inf);
		deque<ll> q;
		du[x]=0;
		dd[x]=0;
		q.push_back(x);
		while(!q.empty())
		{
			auto v=q.front();
			q.pop_front();
			// debug3(v,cost,du[v]);
			for(auto u:gu[v])
			{
				if(du[v]<du[u])
				{
					du[u]=du[v];
					q.push_front(u);
				}
				if(dd[v]+1<du[u])
				{
					du[u]=dd[v]+1;
					q.push_back(u);
				}
			}
			for(auto u:gd[v])
			{
				if(dd[v]<dd[u])
				{
					dd[u]=dd[v];
					q.push_front(u);
				}
				if(du[v]+1<dd[u])
				{
					dd[u]=du[v]+1;
					q.push_back(u);
				}
			}
		}
		c=min(dd[y],du[y]);
		cout<<c;

		
		cout<<"\n";
	}
	return 0;
}