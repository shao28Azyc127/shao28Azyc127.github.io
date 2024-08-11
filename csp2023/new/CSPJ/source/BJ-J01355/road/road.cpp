#include<bits/stdc++.h>
using namespace std;
const int N=1e5+5;
int v[N],a[N],n,d;
long long sum;
struct node
{
    int id;
    int num;
}b[N];
bool cmp(node x,node y)
{
    if(x.num==y.num) return x.id<y.id;
    else return x.num<y.num;
}
int main()
{
    freopen("road.in","r",stdin);
    freopen("road.out","w",stdout);
    cin>>n>>d;
    for(int i=0;i<n-1;i++)
    {
        cin>>v[i];
        sum+=v[i];
    }
    for(int i=0;i<n;i++)
    {
        cin>>a[i];
        //b[i].num=a[i];
        //b[i].id=i;
    }
    //sort(b,b+n,cmp);
    int t=ceil((double)sum/(double)d);
    cout<<a[0]*t;
    return 0;
}
