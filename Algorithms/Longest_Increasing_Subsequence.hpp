// Starting at any i, ending at fix end j - Longest Increasing SubSequence

vector<vector<long long int>> &lis(vector<long long int> &a, long long int l, long long int r)
{
    vector<vector<long long int>> lis_ans(r - l + 1, vector<long long int>);

    for (long long int i = l; i <= r; i++)
    {
        vector<long long int> v;
        vector<long long int>::iterator it;
        ll ans = 0;
        for (long long int j = i; j <= r; j++)
        {
            it = lower_bound(v.begin(), v.end(), a[j]);
            if (it == v.end())
                v.push_back(a[j]);
            else
                *it = a[j];
            ans = max(ans, int(v.size()));
            lis_ans[i].push_back(ans);
        }
    }

    return &lis_ans;
}

// Starting at any i, ending at fix end j - Longest Decreasing SubSequence

vector<vector<long long int>> &lds(vector<long long int> &v, long long int l, long long int r)
{
    long long n = (long long int)v.size();
    reverse(v.begin(), v.end());

    for (long long int i = 0; i < n; i++)
        v[i] = -v[i];

    vector<vector<long long int>> lds_ans = *lis(v, n - r - 1, n - l - 1);

    reverse(v.begin(), v.end());

    for (long long int i = 0; i < n; i++)
        v[i] = -v[i];

    return &lds_ans;
}

// Reference - https://www.hackerearth.com/submission/6436930/