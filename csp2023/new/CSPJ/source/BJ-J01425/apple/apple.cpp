#include<bits/stdc++.h>
int main()
{
    freopen("apple.in","r",stdin);
    freopen("apple.out","w",stdout);
    int n;
    cin>>n;
    n1=n;

    int n1=n;
    int cot=0,ans=0;
    while(n!=0)
    {
        int n2=n1;
        n=cell(1.8*n/3);
        cot++;
    }
    if(n/3==2)
    {
        ans=n;
    }
    else if(n/3==1)
        ans=1;
    else
        ans=3;
    
    cout<<cot<<" "<<ans<<endl;
    return 0;
}
