#include <iostream>
#include <cstdio>
using namespace std;
int n,tday,alld;
bool ap[1000000003];
bool check()
{
    for(int i=1;i<=n;i++)
    {
        if(ap[i]==0)
        {
            return true;
        }
    }
    return false;
}
int main()
{
    freopen("apple.in","r",stdin);
    freopen("apple.out","w",stdout);
    ios::sync_with_stdio(false);
    cin >> n;
    while(check())
    {
        for(int i=1;i<=n;)
        {
            while(ap[i]==1&&i<=n)
            {
                i++;
            }
            if(!ap[i])
            {
                ap[i]=1;
                //cout << i <<endl;
            }
            if(i==n)
            {
                tday=alld+1;
            }
            int j=0;
            while(j<2)
            {
                if(ap[i]==0)
                {
                    j++;
                    i++;
                }
                else
                {
                    i++;
                }
            }
        }
        alld++;
    }
    cout << alld << " " << tday;
    fclose(stdin);
    fclose(stdout);
    return 0;
}
