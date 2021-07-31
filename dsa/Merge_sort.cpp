#include <bits/stdc++.h>
using namespace std;
#define ll long long int

ll ar[1000000];

void merge (ll l, ll m, ll r)
{
    ll arr[r - l];
    ll j = l, k = m;
    for (ll i = 0; i < r - l; i++)
    {
        if ((k == r) || (j < m && k < r && ar[j] <= ar[k]))
        {
            arr[i] = ar[j];
            j++;
        }
        else
        {
            arr[i] = ar[k];
            k++;
        }
    }
    for (ll i = 0; i < r - l; i++)
    {
        ar[i + l] = arr[i];
    }
}

void merg_sort(ll l, ll r)
{
    if (r - l == 2)
    {
        if (ar[l] > ar[l + 1])
            swap(ar[l], ar[l + 1]);
    }
    else if (r - l > 2)
    {
        ll m = (l + r) / 2;
        merg_sort(l, m);
        merg_sort(m, r);
        merge(l, m, r);
    }
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
//        cout << t << " ";
        solve();
    }
    cout << "Complete";
}

void solve()
{
    ll n, i;
    n = rand() % 999999 + 1;
    ll mm[n];
    ll ar1[n];
    for (i = 0; i < n ; i++)
    {
        ar[i] = rand() % 10000000000;
        ar1[i] = ar[i];
        mm[i] = ar[i];
    }

    sort(ar1, ar1 + n);
    merg_sort(0, n);
    for (i = 0; i < n; i++)
    {
        if (ar[i] != ar1[i])
        {
            cout << endl << n << endl;
            for (ll j = 0; j < n; j++)
            {
                cout << mm[j] << " " << ar[j] << " " << ar1[j] << endl;
            }
           break;
        }
    }
    //cout << endl;
}

// TIME COMPLEXITY
// nlogn in all cases cases

// space complexity 
// n for all cases.
