#include <bits/stdc++.h>

using namespace std;
typedef long long ll;
typedef unsigned long long ull;
#define rep(i,a,b) for (auto i=(a);i<=(b);++i)
#define per(i,a,b) for (auto i=(a);i>=(b);--i)

#define N int(3010)

multiset<string> st;
vector<string> v,b;
map<char,int> mp;

int main()
{
    freopen("dict.in","r",stdin);
    freopen("dict.out","w",stdout);

    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    int n,m;
    cin>>n>>m;
    
    rep (i,1,n)
    {
        string s;
        cin>>s;
        v.push_back(s);
    }
    for (auto s:v)
    {
        for (char ch:s) mp[ch]++;
        char tmp0=-1,tmp1;
        for (char&ch:s)
        {
            if (mp.rbegin()->first>ch)
            {
                auto it=--mp.end();
                tmp0=it->first;
                tmp1=ch;
                ch=it->first;
                break;
            }
            auto it=mp.find(ch);
            if (it==mp.end()) continue;
            it->second--;
            if (!it->second) mp.erase(it);
        }
        if (tmp0!=-1) per (i,s.size()-1,0) if (s[i]==tmp0) 
        {
            s[i]=tmp1;
            break;
        }
        mp.clear();
        st.insert(s);
        b.push_back(s);
        // cerr<<s<<'\n';
    }
    m=0;
    for (auto&s:v)
    {
        for (char ch:s) mp[ch]++;
        char tmp0=-1,tmp1;
        for (char&ch:s)
        {
            if (mp.begin()->first<ch)
            {
                auto it=mp.begin();
                tmp0=it->first;
                tmp1=ch;
                ch=it->first;
                break;
            }
            auto it=mp.find(ch);
            if (it==mp.end()) continue;
            it->second--;
            if (!it->second) mp.erase(it);
        }
        if (tmp0!=-1) per (i,s.size()-1,0) if (s[i]==tmp0) 
        {
            s[i]=tmp1;
            break;
        }
        mp.clear();
        auto r=st.upper_bound(s);
        // cerr<<s<<": "<<(r==st.begin())<<'\n';
        bool ans;
        if (s==b[m]) ans=--r==st.begin();
        else ans=r==st.begin();
        if (ans) cout<<"1";
        else cout<<"0";
        ++m;
    }
    return 0;
}
