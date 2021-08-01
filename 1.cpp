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
    ll n, i, d, h;
    cin >> n;
    ll ar[n];
    ll ans = 0;
    for (i = 0; i < n; i++)
    {
        cin >> ar[i];
    }
    sort(ar, ar + n);
    ll cf = 0;
    for (i = 0; i < n ; i++)
    {
        cf++;
        while (i < n - 1 && ar[i] == ar[i + 1]) {
            i++;
            cf++;
        }
        ans = ans + (cf * (n - cf));
        cf = 0;
    }
    cout << ans;
    cout << endl;
}
