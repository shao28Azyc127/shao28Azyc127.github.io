#include<bits/stdc++.h>
using namespace std;
struct node{
    int price,num;
}a[100009];
int n,d,v[1000009],loo=0,ans=0;
bool cmp(node a,node b)
{
    if(a.price!=b.price)
        return a.price<b.price;
    else
        return a.num<b.num;
}
int ddis(int a,int b)
{
    int aaaaa=0;
    for(int i=a;i<=b-1;i++)
    {
        aaaaa+=v[i];
    }
    return  aaaaa;
}
int main()
{
    freopen("road.in","r",stdin);
    freopen("road.out","w",stdout);
    cin>>n>>d;
    int vaa=0;
    for(int i=1;i<=n-1;i++)
    {
        cin>>v[i];
        vaa+=v[i];
    }
    for(int i=1;i<=n;i++)
    {
        int as;
        cin>>as;
        a[i].price=as;
        a[i].num=i;
//cout<<a[i].price<<" "<<a[i].num<<endl;
    }
//cout<<"YES"<<endl;
    sort(a+1,a+n+1,cmp);
    int now=n;
    for(int i=1;i<=n;i++)
    {
        if(now>a[i].num)
        {
            double sssssddd=ddis(a[i].num,now);
            loo=0;
            int sss=sssssddd;
            if(sssssddd-sss!=0) sss++;
            double ssss=sss/d;
            int hsy=ssss;
            if(ssss-hsy!=0) hsy++;
            ans+=hsy*a[i].price;
            //loo=(hsy-ddis(a[i].num,now))/d;
//cout<<ans<<"   "<<a[i].num<<"->>"<<now<<" "<<hsy<<" "<<sss<<endl;
            now=a[i].num;
        }
    }
    cout<<ans;
    return 0;
}
