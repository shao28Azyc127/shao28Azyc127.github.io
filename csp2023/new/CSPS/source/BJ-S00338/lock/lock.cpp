#include <iostream>
#include <cstdio>
#include <algorithm>
#include <string>
using namespace std;
struct lock
{
    int s[15];
    lock() {for(int i=1;i<=5;i++)s[i]=0;}
    void read() {for(int i=1;i<=5;i++)cin >> s[i];}
    void print() {for(int i=1;i<=5;i++)cout << s[i] << ' ';cout << "\n";}
};
int n,ans;
lock a[15];
int d[15],p;
int dis(int x,int y)
{
    x%=10,y%=10;
    return (x>=y?x-y:x+10-y);
}
bool check1(lock l1,lock l2)
{
    p=0;
    for(int i=1;i<=5;i++)
        if(l1.s[i]!=l2.s[i])
            d[++p]=i;
    if(p>=3 || p==0)
        return 0;
    if(p==1)
        return 1;
    return (d[2]==d[1]+1 &&
            dis(l1.s[d[1]],l2.s[d[1]])==dis(l1.s[d[2]],l2.s[d[2]]));
}
bool check2(lock l)
{
    for(int i=1;i<=n;i++)
        if(!check1(l,a[i]))
            return 0;
    return 1;
}
int main()
{
    freopen("lock.in","r",stdin);
    freopen("lock.out","w",stdout);
    cin >> n;
    for(int i=1;i<=n;i++)
        a[i].read();
    lock l;
    for(l.s[1]=0;l.s[1]<=9;l.s[1]++)
        for(l.s[2]=0;l.s[2]<=9;l.s[2]++)
        for(l.s[3]=0;l.s[3]<=9;l.s[3]++)
            for(l.s[4]=0;l.s[4]<=9;l.s[4]++)
            for(l.s[5]=0;l.s[5]<=9;l.s[5]++)
            {
                if(check2(l))
                {
                    ans++;
                    //l.print();
                }
            }
    cout << ans << endl;
    return 0;
}
