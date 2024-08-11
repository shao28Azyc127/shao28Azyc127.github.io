#include <bits/stdc++.h> //rp++

using namespace std;
const int MAXN = 3002;

int n,m;
int c[30];
string s[MAXN];

inline string Sort1(string str)
{
    string sr = str;
    memset(c,0,sizeof(c));
    for(register int i = 0;i < sr.length();++i)
        c[sr[i] - 'a' + 1]++;
    int tot = 0;
    for(register int i = 1;i <= 26;++i)
        for(register int j = 1;j <= c[i];++j)
            sr[tot++] = (char)('a' + i - 1);
    return sr;
}

inline string Sort2(string str)
{
    string sr = str;
    memset(c,0,sizeof(c));
    for(register int i = 0;i < sr.length();++i)
        c[sr[i] - 'a' + 1]++;
    int tot = 0;
    for(register int i = 26;i >= 1;i--)
        for(register int j = 1;j <= c[i];++j)
            sr[tot++] = (char)('a' + i - 1);
    return sr;
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0),cout.tie(0);
    freopen("dict.in","r",stdin);
    freopen("dict.out","w",stdout);

    cin >> n >> m;
    for(register int i = 1;i <= n;++i)
        cin >> s[i];
    
    if(n == 1)
    {
        cout << 1 << '\n';
        return 0;
    }

    if(m == 1)
    {
        int id = 0;
        char minc = (char)(127);
        for(register int i = 1;i <= n;++i)
        {
            if(s[i][0] < minc)
            {
                minc = s[i][0];
                id = i;
            }
        }

        for(register int i = 1;i <= n;++i)
        {
            if(id == i)
                cout << 1;
            else
                cout << 0;
        }

        cout << '\n';
        return 0;
    }
    
    if(m == 2)
    {
        for(register int i = 1;i <= n;++i)
        {
            bool b = true;
            string str = s[i];
            if(str[0] > str[1])
                swap(str[0],str[1]);
            for(register int j = 1;j <= n;++j)
            {
                if(i == j)
                    continue;
                string str2 = s[j];
                if(str2[0] < str2[1])
                    swap(str2[0],str2[1]);
                if(str > str2)
                {
                    b = false;
                    break;
                }
            }

            if(b)
                cout << 1;
            else
                cout << 0;
        }
        
        cout << '\n';
        return 0;
    }
    
    for(register int i = 1;i <= n;++i)
    {
        bool b = true;
        string str = s[i];
        str = Sort1(str);
        for(register int j = 1;j <= n;++j)
        {
            if(i == j)
                continue;
            string str2 = s[j];
            str2 = Sort2(str2);
            if(str > str2)
            {
                b = false;
                break;
            }
        }

        if(b)
            cout << 1;
        else
            cout << 0;
    }
    
    cout << '\n';
    return 0;
}