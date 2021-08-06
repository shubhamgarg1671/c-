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
    ll n = 4, i;
    set <ll> st;
    ll xr = 0;
    //vector <ll> vec;
    while(n--)
    {
        ll tp;
        cin >> tp;
        xr = xr ^ tp;
  //      vec.push_back(tp);
        st.insert(tp);
    }
//    sort(vec.begin(), vec.end());
    if (st.size() > 2)
    {
        cout << "2";
    }
    else if (st.size() == 2)
    {
        if (xr == 0)
        {
            cout << "2";
        }
        else 
        {
            cout << "1";
        }
    }
    else
    {
        cout << "0";
    }
    cout << endl;
}
