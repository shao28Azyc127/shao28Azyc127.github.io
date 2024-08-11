#include<bits/stdc++.h>
using namespace std;
int main()
{
    freopen("apple.in","r",stdin);
    freopen("apple.out","w",stdout);
    int n,sn,lout=0,k=0,bk=0;
    cin>>n;
    sn=n;
    while(sn)
    {
        if(sn%3==1&&bk==0)
        {
            lout=k+1;
            bk=1;
        }
        sn-=(sn-1)/3+1;
        k++;
    }
    cout<<k<<" "<<lout;
    return 0;
}
