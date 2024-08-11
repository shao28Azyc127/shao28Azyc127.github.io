#include <bits/stdc++.h>
using namespace std;
int n,a[100000000];
void hebing(int x)
{
    for(int i=x;i<n-1;i++)
        a[i]=a[i+1];
}
int main()
{
    freopen("apple.in","r",stdin);
    freopen("apple.out","w",stdout);
    int i,l;
    cin>>n;
    l=n;
    for(int i=0;i<n;i++)
        a[i]=i+1;
    for(i=1;n!=0;i++)
    {
        for(int j=0;j<n;j+=2)
        {
            if(a[j]==l)
                l=i;
            hebing(j);
            n--;
        }
    }
    cout<<i-1<<' '<<l;
    fclose(stdin);
    fclose(stdout);
    return 0;
}
