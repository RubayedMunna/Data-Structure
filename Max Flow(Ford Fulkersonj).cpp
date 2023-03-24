#include<bits/stdc++.h>
#include<ext/pb_ds/assoc_container.hpp>
using namespace std;
using namespace __gnu_pbds;
//using u64 = uint64_t;
//using u128 = __uint128_t;
#define ll long long
#define N '\n'
#define Fast ios_base::sync_with_stdio(false); cin.tie(NULL)
#define File freopen("in.txt","r",stdin)


ll n;
vector<vector<ll>>capacity;
vector<vector<ll>>adj;

ll bfs(ll s,ll t,vector<ll>& parent)
{
    fill(parent.begin(),parent.end(),-1);

    parent[s]=-2;
    queue<pair<ll,ll>>q;
    q.push({s,INF});

    while(!q.empty())
    {
        ll cur=q.front().first;
        ll flow=q.front().second;
        q.pop();

        for(ll next:adj[cur])
        {
            if(parent[next]==-1&&capacity[cur][next])
            {
                parent[next]=cur;
                ll new_flow=min(flow,capacity[cur][next]);
                if(next==t)
                {
                    return new_flow;
                }
                q.push({next,new_flow});
            }
        }
    }
    return 0;
}

ll maxflow(ll s,ll t)
{
    ll flow=0;
    vector<ll>parent(n);
    ll new_flow;

    while(new_flow=bfs(s,t,parent))
    {
        flow+=new_flow;

        ll cur=t;
        while(cur!=s)
        {
            ll prev=parent[cur];
            capacity[prev][cur]-=new_flow;
            capacity[cur][prev]+=new_flow;
            cur=prev;
        }
    }
    return flow;
}

void solve(ll tst)
{

}

int main()
{
    Fast;
    //File;
    ll t=1;
    cin>>t;
    ll tst=0;
    while(t--)
    {
        solve(++tst);
    }
    return 0;
}
