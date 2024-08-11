//#include <iostream>
#include <fstream>
#include <string>
#include <algorithm>
using namespace std;

ifstream cin("dict.in");
ofstream cout("dict.out");

pair<string, int> dict[6005];
int cnt[26];

int main()
{
    int n, m;
    cin >> n >> m;
    for(int i = 1; i <= n; i++)
    {
        string tmp;
        cin >> tmp;
        dict[i].second = i;
        dict[n + i].second = n + i;
        for(int j = 0; j < 26; j++)
        {
            cnt[j] = 0;
        }
        for(int j = 0; j < m; j++)
        {
            ++cnt[tmp[j] - 'a'];
        }
        for(int j = 25; j >= 0; j--)
        {
            dict[i].first.insert(dict[i].first.end(), cnt[j], 'a' + j);
        }
        for(int j = 0; j < 26; j++)
        {
            dict[n + i].first.insert(dict[n + i].first.end(), cnt[j], 'a' + j);
        }
    }
    sort(dict + 1, dict + 2 * n + 1);
    string ans(n, '0');
    for(int i = 1; i <= n; i++)
    {
        if(dict[i].second > n)
        {
            ans[dict[i].second - n - 1] = '1';
        } else {
            if(dict[i + 1].second == dict[i].second + n)
            {
                ans[dict[i].second - 1] = '1';
            }
            break;
        }
    }
    cout << ans << endl;
}
