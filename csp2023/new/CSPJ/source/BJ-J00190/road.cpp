#include<iostream>
using namespace std;
int main()
{
    freopen("road.in","r",stdin);
    freopen("road.out","w",stdout);
    int n,d;
    cin>>n>>d;
    int v[100005],a[100005];
    for(int i=1;i<n;i++)
    {
        cin>>v[i];
    }
    for(int i=1;i<=n;i++)
    {
        cin>>a[i];
    }
    int min=a[1];
    int ans=0;
    int a1[100005];
    int v1[100005];
    int j=1;
    a1[1]=a[1];
    for(int i=1;i<n;i++)
    {

        if(a[i]<min){
            j++;
            min=a[i];
            a1[j]=a[i];

        }
        v1[j]+=v[i];
    }
    for(int i=1;i<=j;i++)
    {
        if(v1[i]%d==0)ans+=v1[i]/d*a1[i];
        else{
            ans+=(v1[i]/d+1)*a1[i];
            v1[i+1]-=(d*(v1[i]/d+1)-v1[i]);
        }
    }
    cout<<ans;
    return 0;
}