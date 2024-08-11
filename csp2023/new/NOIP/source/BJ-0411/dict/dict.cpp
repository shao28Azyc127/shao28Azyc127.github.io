#include<iostream>
#include<cstring>
using namespace std;
const int N = 3005;

int n,m,bucket[30];
string s[N],mins[N],maxs[N],anss;

int main()
{
    freopen("dict.in","r",stdin);
    freopen("dict.out","w",stdout);
    cin >> n >> m;
    for(int i=1;i<=n;i++)
        cin >> s[i];

    for(int i=1;i<=n;i++)
    {
        memset(bucket,0,sizeof(bucket));
        for(int j=0;j<m;j++)
            bucket[s[i][j] - 'a' + 1]++;

        for(int j=1;j<=26;j++)
            while(bucket[j] > 0)
            {
                mins[i] = mins[i] + (char)(j + 'a' - 1);
                bucket[j]--;
            }
    }

    //for(int i=1;i<=n;i++) cout << mins[i] << endl;


    for(int i=1;i<=n;i++)
        for(int j=0;j<m;j++)
            maxs[i] = maxs[i] + mins[i][m-j-1];

    //for(int i=1;i<=n;i++) cout << maxs[i] << endl;

    anss = maxs[1];
    for(int i=2;i<=n;i++)
        if(anss > maxs[i]) anss = maxs[i];

    //cout << anss << endl;

    for(int i=1;i<=n;i++)
    {
        if(anss < mins[i]) cout << 0;
        else cout << 1;
    }

    return 0;
}
