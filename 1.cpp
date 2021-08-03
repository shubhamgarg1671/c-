#include <bits/stdc++.h>
using namespace std;
#define ll long long int
#define lld long double
#define pb push_back

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
    ll n, i;
    cin >> n;
    ll ar[2][n];
    for (i = 0; i < n; i++)
    {
        cin >> ar[0][i];
    }

    for (i = 0; i < n; i++)
    {
        cin >> ar[1][i];
    }
    ar[1][n - 1] = 0;
    ar[0][0] = 0;
    for (i = n - 2; i >= 0; i--)
    {
        ar[1][i] = ar[1][i + 1] + ar[1][i];
    }
    ll ans = LLONG_MAX;
    
    cout << ans;
    cout << endl;
}
