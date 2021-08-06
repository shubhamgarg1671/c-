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
    ll n, i, p, k;
    cin >> n >> p >> k;
    ll ans = 0;
    if (n % k == 0)
    {
        ans = p % k;
//        ans--;
        ans = ans * (n / k);
    }
    else
    {
        ans = p % k;
//        ans--;
        ans = ans * ((n / k) + 1);  
    }
    ans = ans + (p / k);
    if (((n - 1) % k) < p % k)
    {
//        cout << "ef";
        ll tp = (n - 1) % k;
        ll tp1 = p % k;
        tp1--;
        ans = ans - (tp1 - tp);
    }
    cout << ans + 1;
    cout << endl;
}
