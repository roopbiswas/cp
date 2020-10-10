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

// 				**LCA BINARY LIFTING**
// 		https://www.spoj.com/problems/LCASQ/


vector<ll> g[100110];
ll p[100110][17],ln,lvl[100011];


void dfs(ll x,ll par)
{
	lvl[x]=lvl[par]+1;
	p[x][0]=par;
	for(ll i=1;i<=ln;i++)
		p[x][i]=p[p[x][i-1]][i-1];
	for(auto q:g[x])
		if(q!=par)
			dfs(q,x);
}

ll lca(ll x,ll y)
{
	if(lvl[x]<lvl[y])
		swap(x,y);

	ll i,lg;
	for(lg=0;(1<<lg) <= lvl[x] ;lg++);
	lg--;
	
	for(i=lg;i>=0;i--)
		if((1<<i) <= lvl[x]-lvl[y])
			x=p[x][i];

	if(x==y) return x;

	for(;lg>=0;lg--)
		if(p[x][lg] != p[y][lg])
			x=p[x][lg],y=p[y][lg];

	return p[x][0];
}

int main()
{
	IOS;
	ll n,k,m,i,j,c=0,cs=0,t;
	t=1;

	cin>>n;
	// n=s.length();
	// ll a[n];
	ln=log2(n);
	rep(i,n)
	{
		cin>>m;
		rep(j,m)
		{
			cin>>k;
			g[i].pb(k);
			g[k].pb(i);
		}
	}
	lvl[0]=0;
	dfs(0,0);
	string s;
	cin>>t;
	while(t--)
	{
		cin>>j>>k;
		c=lca(j,k);
		cout<<c;

		
		cout<<"\n";
	}
	return 0;
}