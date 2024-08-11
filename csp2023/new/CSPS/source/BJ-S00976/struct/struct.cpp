#include <iostream>
#include <string>
#include <unordered_map>

#define rep(i, a, b) for (int i = a; i <= b; i = -~i) 

using namespace std;

const int maxn = 1e6 + 10;

int n;
long long last;
unordered_map<long long, string> mp;
unordered_map<string, pair<long long, long long> > mp2;

int main()
{
    std::ios::sync_with_stdio(false); std::cin.tie(0); std::cout.tie(0);
    freopen("struct.in", "r", stdin);
    freopen("struct.out", "w", stdout);

    cin >> n;
    while (n--)
    {
        int op; string str, s;
        cin >> op;
        if (op == 2)
        {
            cin >> str >> s;
            if (str == "byte") mp2[s].first = last, mp2[s].second = last, mp[last] = s, last++;
            else if (str == "short") 
            {
                if (last % 2 != 0) last++;
                mp2[s].first = last, mp2[s].second = last + 1, mp[last] = s, mp[last + 1] = s, last += 2;
            }
            else if (str == "int")
            {
                if (last % 4 != 0) last += (4 - last % 4);
                rep(i, 0, 3) mp[last + i] = s;
                mp2[s].first = last, mp2[s].second = last + 3;
                last += 4;
            }
            else if (str == "long")
            {
                if (last % 8 != 0) last += (8 - last % 8);
                rep(i, 0, 7) mp[last + i] = s;
                mp2[s].first = last, mp2[s].second = last + 7;
                last += 8;
            }
        } 
        else if (op == 3)
        {
            cin >> s;
            cout << mp2[s].first << " " << mp2[s].second << "\n";
        }
        else if (op == 4)
        {
            long long num;
            cin >> num;
            if (mp[num] == "") cout << "ERR\n";
            else cout << mp[num] << "\n";
        }

    }
    return 0;
}