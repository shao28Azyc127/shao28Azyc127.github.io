#include <iostream>

using namespace std;

int main()
{
    freopen("game.in","r",stdin);
    freopen("game.out","w",stdout);
    int n;
    cin>>n;
    char a[n];
    for(int i=0; i<n; i++)
    {
        cin>>a[i];
    }
    int g=0;
    char t[n];
    for(int j=0; j<n-1; j++)
    {
        t[0]=a[j];
        for(int l=j+1; l<n-1; l++)
        {
            t[l]=a[l];
            int o=2;
            if(() && (o%2 == 0))
            {
                g++;
                o++;
                t[l+1]=a[l+1];
            }
            else
            {
                o++;
                t[l+1]=a[l+1];
            }
        }
    }
    cout<<g-1;
    return 0;
}
