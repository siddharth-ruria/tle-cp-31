
#include <iostream>
#include <bits/stdc++.h>
using namespace std;
using namespace chrono;

// code
void solve()
{
    string s;
    cin >> s;
    vector<int> cnt(2, 0);
    for (int i = 0; i < s.size(); ++i)
    {
        cnt[s[i] - '0']++;
    }
    for (int i = 0; i < s.size(); ++i)
    {
        int req = (s[i] - '0') ^ 1;
        if (cnt[req] == 0)
        {
            cout << s.size() - i << '\n';
            return;
        }
        cnt[req]--;
    }
    cout << 0 << '\n';
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