#include <iostream>

using namespace std;

int n;
string a;

bool check(int l,int r)
{
    bool used[1000005]={};
    int cnnnt=r-l+1;
    for (int i=l;i<=r;i++)
    {
        if (!used[i])
        {
            // left
            for (int j=i-1;j>=l;j--)
            {
                if (!used[j])
                {
                    if (a[j]!=a[i])
                    {
                        break;
                    }
                    else
                    {
                        cnnnt--;
                        cnnnt--;
                        used[i]=1;
                        used[j]=1;
                        break;
                    }
                }
            }
            for (int j=i+1;j<=r;j++)
            {
                if (!used[j])
                {
                    if (a[j]!=a[i])
                    {
                        break;
                    }
                    else
                    {
                        cnnnt--;
                        cnnnt--;
                        used[i]=1;
                        used[j]=1;
                        break;
                    }
                }
            }
            

            // right
        }
    }
    if (cnnnt > 0)
    {
        return 0;
    }
    return 1;
}

int main()
{
    freopen("game.in","r",stdin);
    freopen("game.out","w",stdout);
    cin >> n;
    cin >> a;
    int ans=0;
    for (int i=0;i<n;i++)
    {
        for (int j=i+1;j<n;j++)
        {
            ans+=check(i,j);
        }
    }
    cout << ans << endl;
    
    return 0;
}