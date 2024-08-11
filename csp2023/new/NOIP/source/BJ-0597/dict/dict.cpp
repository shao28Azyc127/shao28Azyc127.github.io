# include <bits/stdc++.h>
using namespace std;
const int maxn = 30005;
int n, m;
char s[maxn][maxn];

int main()
{
    freopen("dict.in", "r", stdin);
    freopen("dict.out", "w", stdout);
    cin>>n>>m;
    if (n==1)
    {
        cin>>s[1][1];
        cout<<1;
        return 0;
    }
    if (m==1)
    {

        for (int i=1; i<=n; ++i)
        {
            scanf("%s", &s[i][1]);
        }
        for (int i=1; i<=n; ++i)
        {
            int cnt=0;
            for (int j=1; j<=n; ++j)
            {
                if (i==j) continue;

                if (s[i][1] <=s[j][1]) cnt++;
            }
            //cout<<s[i][1]<<"---"<<cnt<<endl;
            if (cnt==n-1) cout<<1;
            else cout<<0;
        }
    }
    if (m==2)
    {
        string ss;
        for (int i=1; i<=n; ++i)
        {
            cin>>ss;
            s[i][1] = ss[0];
            s[i][2] = ss[1];
        }
        for (int i=1; i<=n; ++i)
        {
            int cnt=0;
            for (int j=1; j<=n; ++j)
            {
                if (i==j) continue;

                if (s[i][1] <= s[j][1] || (s[i][1]==s[j][1]&&s[i][2]<=s[j][2]))
                {
                    cnt++;
                }
                else if((s[i][2]<=s[j][1]) || (s[i][2]==s[j][1]&&s[i][1]<=s[j][2])) cnt++;
            }
            //cout<<"OK"<<endl;
            if (cnt==n-1) cout<<1;
            else cout<<0;
        }
    }

    return 0;
}
