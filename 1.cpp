#include <bits/stdc++.h>
using namespace std;
#define ll long long int
#define lld long double
#define pb push_back

ll N = 100001;
ll ar[100001];
vector <vector<ll> >vec(100001); 
void allFactor()
{
    ll i, j;
    for (i = 2; i < N; i++)
    {
        vec[i].push_back(1);
        for (j = 2; j <= sqrt(i); j++)
        {
            if (i % j == 0)
            {
                vec[i].push_back(j);
                if (j * j != i)
                vec[i].push_back(i / j);
            }
        }
        sort(vec[i].begin(), vec[i].end());
    }
}

void solve1(ll n);
ll solve(ll n);
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    //freopen("input.txt", "r", stdin);
    freopen("text.txt", "w", stdout);
    ll t = 1;
    cin >> t;
    allFactor();
    while (t--)
    {
        solve1(t);
    }
}

void solve1(ll n)
{
    ll  i;
    ll ans = 0;
    for (i = 2; i <= n; i++)
    {
        ll tp = n / i;
        ans = ans + (tp * vec[i].size());
//        cout << ans << " ";
        tp = n % i;
        tp = (upper_bound(vec[i].begin(), vec[i].end(), tp) - vec[i].begin());
        ans = ans + tp;
  //      cout << ans << "  ";
    }
    if (ans != solve(n))
    cout << n << endl;
}

ll solve(ll n)
{
    ll i;
    ll ans = 0;
    for (i = 1; i <= n; i++)
    {
        for (ll j = 1; j <= n; j++)
        {
            if (i % j != 0 && j % (i % j) == 0)
            {
                ans++;
            }
        }
    }
    return ans;
}
