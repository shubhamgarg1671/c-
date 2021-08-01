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
    ll a[n];
    ll b[n];
    ll c[n];
    for (i = 0; i < n; i++)
    {
        cin >> a[i];
//        a[i] = a[i]  % n;
        c[i] = n;
    }
    for (i = 0; i < n; i++)
    {
        cin >> b[i];
  //      b[i] = b[i]  % n;
    }
    vector<ll> vec;
    for (i = 0; i < n; i++)
    {
        if ((a[0] + b[i]) % n < c[0]) {
            vec.clear();
            vec.push_back(i);
            c[0] = (a[0] + b[i]) % n;
        }
        else if ((a[0] + b[i]) % n == c[0]) {
            vec.push_back(i);
        }
    }
    for (i = 0; i < n; i++) {
        c[i] = (a[i] + b[(vec[0] + i) % n]) % n;
    }
    ll fl = 0;
    for (i = 0; i < n; i++) {
        if (vec.size() == 1)
        {
            break;
        }
        if (fl != 1 && c[i] != (a[i] + b[(vec[1] + i) % n]) % n)
        {
            if (c[i] < (a[i] + b[(vec[1] + i) % n]) % n) {
                break;
            } else {
                fl = 1;
            }
        }
        if (fl == 1) {
            c[i] = (a[i] + b[(vec[1] + i) % n]) % n;
        }
    }
    fl = 1;
    for (i = 0; i < n; i++)
    {
        cout << c[i] << " ";
    }
    cout << endl;
}
