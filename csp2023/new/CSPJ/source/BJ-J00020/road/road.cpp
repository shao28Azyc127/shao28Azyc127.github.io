#include<bits/stdc++.h>
using namespace std;
int main()
{

    freopen("road.in","r",stdin);
    freopen("road.out","w",stdout);
    int n,d;
    cin>>n>>d;
    int distance[100005],a[100005],price[100005],pricenum[100005],p=1,target=0,oil=0;
    distance[1]=0;
    for(int i=2;i<=n;i++)
    {
        int a;
        cin>>a;
        distance[i]=distance[i-1]+a;
    }
    //cout<<1<<endl;
    for(int i=1;i<=n;i++)
        cin>>a[i];
    int num=a[1];
    price[1]=a[1];
    pricenum[1]=1;
    //cout<<a[1]<<endl;
    for(int i=2;i<=n-1;i++)
    {
        if(a[i]<num)
        {
            num=a[i];
            p++;
            price[p]=a[i];
            pricenum[p]=i;
        }
    }
    /*for(int i=1;i<=n;i++)
    {
        cout<<distance[i]<<" ";
    }*/
    pricenum[p+1]=n;
    /*cout<<p<<endl;
    for(int i=1;i<=p;i++)
    {
        cout<<price[i]<<" "<<pricenum[i]<<endl;
    }*/
    for(int i=1;i<=p;i++)
    {
        int j=oil;
        int sum=0;
        for(;j<distance[pricenum[i+1]]-distance[pricenum[i]];j=j+d)
        {
            target+=price[i];
            sum++;
        }
        oil=j-distance[pricenum[i+1]]+distance[pricenum[i]];
        //cout<<i<<" "<<oil<<endl;
    }
    cout<<target;
    fclose(stdin);
    fclose(stdout);
    return 0;
}