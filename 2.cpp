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
    ll n, i = 3;
    ll ans = 0;
    while (i--)
    {
        cin >> n;
        ans = ans + n;
    }
    i = 3;
    while (i--)
    {
        cin >> n;
        ans = ans - n;
    }
    if (ans> 0)
    {
        cout << "1";
    }
    else 
    {
        cout << "2";
    }
    cout << endl;
}
