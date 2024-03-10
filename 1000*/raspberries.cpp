#include <iostream>
#include <bits/stdc++.h>

using namespace std;
using namespace chrono;

// code
void solve()
{
    int n, k;
    cin >> n >> k;
    vector<int> v;
    for (int i = 0; i < n; ++i)
    {
        int x;
        cin >> x;
        v.push_back(x);
    }
    int ans = 0;
    if (k == 4)
    {
        int even_ct = 0;
        int m = INT_MAX;
        for (int i = 0; i < n; ++i)
        {
            if (!(v[i] & 1))
                even_ct++;
            int val = v[i] + 1;
            if (val % 4 == 0)
                m = 1;
            if (v[i] % 4 == 0)
            {
                cout << 0 << '\n';
                return;
            }
        }
        if (even_ct == 0)
            ans = 2;
        else if (even_ct == 1)
            ans = 1;
        else if (even_ct > 1)
            ans = 0;
        ans = min(ans, m);
    }
    else
    {
        ans = INT_MAX;
        for (int i = 0; i < n; ++i)
        {
            if (v[i] % k == 0)
            {
                cout << 0 << '\n';
                return;
            }
            ans = min(ans, (k - (v[i] % k)));
        }
    }
    cout << ans << '\n';
}

// main function
int main()
{

    auto start = high_resolution_clock::now();

    int tt = 1;
    cin >> tt;
    while (tt--)
    {
        solve();
    }

    auto stop = high_resolution_clock::now();
    auto duration = duration_cast<microseconds>(stop - start);

#ifdef siddharth
    cerr << "time: " << duration.count() / 1000 << endl;
#endif
}
// end