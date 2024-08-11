#include <iostream>
#include <vector>

using namespace std;
int n,a[8][5],ans=0;
struct Ans{
    int x=0;
    vector<int>y;
};
bool check(int z,int b,int c,int d,int e)
{
    int s[5];
    s[0]=z;
    s[1]=b;
    s[2]=c;
    s[3]=d;
    s[4]=e;
    Ans count;
    for (int i=0;i<n;i++)
    {
        count.x=0;
        while(!count.y.empty())
        {
            count.y.pop_back();
        }
        for (int j=0;j<5;j++)
        {
            if (a[i][j]!=s[j])
            {
                count.x++;
                count.y.push_back(j);
            }
        }
        if(count.x>=3)
        {
            return 0;
        }
        if (count.x==2)
        {
            if(a[i][count.y[0]]-a[i][count.y[1]]!=s[count.y[0]]-s[count.y[1]]||abs(count.y[0]-count.y[1])!=1)
            {
                return 0;
            }
        }
    }
    return 1;
}
int main()
{
    freopen("lock.in","r",stdin);
    freopen("lock.out","w",stdout);
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    cin >> n;

    for (int i=0;i<n;i++)
    {
        for (int j=0;j<5;j++)
        {
            cin >> a[i][j];
        }
    }
    if (n==1)
    {
        cout << 81;
    }
    for  (int i=0;i<9;i++)
    {
        for(int j=0;j<9;j++)
        {
            for(int k=0;k<9;k++)
            {
                for(int l=0;l<9;l++)
                {
                    for(int m=0;m<9;m++)
                    {
                        if (check(i,j,k,l,m))
                        {
                            ans++;
                        }
                    }
                }
            }
        }
    }
    cout << ans;

    return 0;
}
