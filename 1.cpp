#include <bits/stdc++.h>
using namespace std;
#define ll long long int
#define lld long double
#define pb push_back

//this can sort 2d VECTOR based on column where compleete row moves together
bool sortcol( const vector<ll>& v1, const vector<ll>& v2 ) { 
 return v1[1] < v2[1]; 
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
    ll n, i, k;
    cin >> n >> k;
    vector<vector <ll> > vec;
    vector<ll> tpvec;
    tpvec.push_back(0);
    tpvec.push_back(0);
    for (i = 0; i <n; i++)
    {
        tpvec[0] = i + 1;
        cin >> tpvec[1];
        vec.push_back(tpvec);
    }
    
    ll ans = LLONG_MIN;
    for (i = 1; i < n; i++)
    {
        ll tp = (vec[i - 1][0] * vec[i][0]) - (k * (vec[i - 1][1] | vec[i][1]));
        if (i > 1)
        {
            ll tp1 = (vec[i - 2][0] * vec[i][0]) - (k * (vec[i - 2][1] | vec[i][1]));
            tp = max(tp, tp1);
        }
        ans = max(ans, tp);
    }
    sort(vec.begin(), vec.end(), sortcol);
    for (i = 1; i < n; i++)
    {
        ll tp = (vec[i - 1][0] * vec[i][0]) - (k * (vec[i - 1][1] | vec[i][1]));
        if (i > 1)
        {
            ll tp1 = (vec[i - 2][0] * vec[i][0]) - (k * (vec[i - 2][1] | vec[i][1]));
            tp = max(tp, tp1);
        }
        ans = max(ans, tp);
    }
    cout << ans;
    cout << endl;
}
