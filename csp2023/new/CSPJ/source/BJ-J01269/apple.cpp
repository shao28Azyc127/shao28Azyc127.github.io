#include<iostream>
#include<cstdio>
#include<queue>
//#include<untiliy>
using namespace std;
struct shu
{
    int shu,ming,lun;
};
//  2 3  5 6  8 9  11 12  14 15  17  18  20 21  23 24  26 27  29 30
queue<shu> arr;
int main()
{
    int l=0;
    int m=1;
    int k=1;
    int up;
    freopen("apple.in","r",stdin);
    freopen("apple.out","w",stdout);
    int n;
    shu a;
    cin>>n;
    for(int i=1;i<=n;i++)
    {
        a.lun=0;
        a.shu=i;
        a.ming=i;
        arr.push(a);
    }
    while(!arr.empty())
    {
        //.cout<<1;
        if(up<arr.front().lun)
        {
            m=1;
            k++;
        }
        up=arr.front().lun;
        if(arr.front().ming%3!=1)
        {
            a.lun=arr.front().lun+1;
            a.shu=arr.front().shu;
            a.ming=m;
            m++;
            arr.push(a);
            //cout<<1;
        }
        else if(arr.front().shu==n)
        {
            l=k;
        }
        //cout<<arr.front().shu<<k<<' ';
        arr.pop();

    }
    cout<<k<<' '<<l;
    return 0;
}
