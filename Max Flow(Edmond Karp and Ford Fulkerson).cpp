#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define N '\n'
#define Fast ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);

const ll INF = 1e15+10;

const ll maxn=110;

ll n;
//vector<vector<ll> > capacity,adj;

vector<ll>adj[maxn];
ll capacity[maxn][maxn];


ll BFS(ll s,ll t, vector<ll>&parent)
{
    fill(parent.begin(),parent.end(),-1);

    parent[s]=-2;
    queue<pair<ll,ll> >q;
    q.push({s,INF});

    while(!q.empty())
    {
        ll curr=q.front().first;
        ll flow=q.front().second;

        q.pop();

        for(ll next:adj[curr])
        {
            if(parent[next]==-1&&capacity[curr][next]>0)
            {
                parent[next]=curr;
                ll new_flow=min(flow,capacity[curr][next]);

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
    vector<ll>parent(n+10);
    ll new_flow;

    while(new_flow=BFS(s,t,parent))
    {
        flow+=new_flow;

        ll curr=t;

        while(curr!=s)
        {
            ll prev=parent[curr];

            capacity[prev][curr]-=new_flow;
            capacity[curr][prev]+=new_flow;

            curr=prev;
        }
    }
    return flow;
}

void clr()
{
    for(ll i=0;i<=n;i++)
    {
        adj[i].clear();

    }
    for(ll i=1;i<=n;i++)
    {
        for(ll j=1;j<=n;j++)
        {
            capacity[i][j]=0;
        }
    }
}

void solve(ll tst)
{
    cin>>n;
    ll s,t,x;
    cin>>s>>t>>x;
    clr();
    for(ll i=1;i<=x;i++)
    {
        ll u,v,c;
        cin>>u>>v>>c;

        adj[u].push_back(v);
        adj[v].push_back(u);

        capacity[u][v]+=c;
        capacity[v][u]+=c;
    }
    
    // for(ll i=1;i<=n;i++)
    // {
    //     for(ll j=1;j<=n;j++)
    //     {
    //         cout<<capacity[i][j]<<" ";
    //     }
    //     cout<<N;
    // }

    ll ans=maxflow(s,t);
    cout<<"Case "<<tst<<": "<<ans<<N;
}

int main()
{
    Fast;
    ll t=1;
    cin>>t;
    ll tst=0;
    while(t--)
    {
        solve(++tst);
    }
}
