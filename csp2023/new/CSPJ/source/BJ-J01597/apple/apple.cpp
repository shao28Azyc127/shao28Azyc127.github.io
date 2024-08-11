#include<iostream>
using namespace std;
int main()
{
    freopen("apple.in","r",stdin);
    freopen("apple.out","w",stdout);
    int n = 0,numji = 0,numl = 0,numn = 0,ji = 0;
    cin >> n;
    bool vio[n+1],x = true;
    for (int i = 1;i <= n;i++)
    {
        vio[i] = true;
    }
    while(x)
    {
        numl++;
        numji = 0;
        x = false;
        for (int i = 1;i <= n;i++)
        {
            if (vio[i])
            {
                numji++;
            }
            if (numji == 1)
            {
                vio[i] = false;
            }
            if ((numji - 1) % 3 == 0)
            {
                vio[i] = false;
            }
        }
        for (int i = 1;i <= n;i++)
        {
            if (vio[i])
            {
                x = true;
                break;
            }
        }
        if ((!vio[n]) && ji == 0)
        {
            numn = numl;
            ji = 1;
        }
    }
    cout << numl << " " << numn;
}