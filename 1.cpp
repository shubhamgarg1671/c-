#include <bits/stdc++.h>
using namespace std;
#define ll long long int
#define lld long double
#define pb push_back

//this can sort 2d VECTOR based on column where compleete row moves together
bool sortcol( const vector<ll>& v1, const vector<ll>& v2 ) { 
 return v1[0] > v2[0]; 
} 

ll lcm (ll a, ll b)
{
    ll tp = a * b;
    return tp / __gcd(a, b);
}

void solve();
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    //freopen("input.txt", "r", stdin);
    //freopen("text.txt", "w", stdout);
    ll t = 1;
    cin >> t;
    while (t--) 
    {
        solve();
    }
}

void solve()
{
    ll n, i, m;
    cin >> n >> m;
    vector <vector< ll> > vec(m);
    for (i = 0; i < m; i++)
    {
        ll tp, tp1;
        cin >> tp >> tp1;
        vec[i].push_back(tp);
        vec[i].push_back(tp1);        
    }
    sort(vec.begin(), vec.end(), sortcol);
    ll lf = n;
    ll cm = 1;
    ll ans = 0;
    for (i = 0; i < m; i++)
    {
        cm = lcm(cm, vec[i][1]);
        ll td = lf - (n / cm);
        //cout << td << " ";
        ans = ans + (vec[i][0] * td);
        lf = lf - td;
        //cout << ans << "  ";
    }
    cout << ans;
    cout << endl;
}
