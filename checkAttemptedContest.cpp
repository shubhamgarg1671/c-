#include <bits/stdc++.h>
using namespace std;
#define ll long long int
#define lld long double
#define pb push_back
#define endl "\n"

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    freopen("ContestUrlList.txt", "r", stdin);
    // freopen("output.txt", "w", stdout);
    vector<string> listOfAllAttemptedContest;
    string contest;
    string checkContest;
    cin >> checkContest;
    cin >> contest;
    cin >> contest;
    while (1)
    {
        if (contest == "END") break;
        listOfAllAttemptedContest.push_back(contest);
        cin >> contest;
    }

    long int i = 0;
    for (i = 0; i < listOfAllAttemptedContest.size(); i++)
    {
        if (checkContest == listOfAllAttemptedContest[i])
        {
            cout << "Contest already present";
            break;
        }
    }
    if (i == listOfAllAttemptedContest.size())
    {
        cout << "Contest not present";
    }
}
