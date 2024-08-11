#include<bits/stdc++.h>
using namespace std;
struct node
{
    int l,r;
    string nam;
}a[105];
int fnd(int from,int len)
{
    while(from%len!=0)
        from++;
    return from;
}
int main()
{
    freopen("struct.in","r",stdin);
    freopen("struct.out","w",stdout);
    int T,m=0;
    cin>>T;
    a[0].r=-1;
    while(T--)
    {
        int op;
        cin>>op;
        if(op==2)
        {
            string typ,nam;
            cin>>typ>>nam;
            int len,lst=a[m].r+1;
            if(typ=="byte")
                len=1;
            if(typ=="short")
                len=2;
            if(typ=="int")
                len=4;
            if(typ=="long")
                len=8;
            int cp=fnd(lst,len);
            m++;
            a[m].nam=nam;
            a[m].l=cp;
            a[m].r=cp+len-1;
        }
        if(op==3)
        {
            string nam;
            cin>>nam;
            for(int i=1;i<=m;i++)
                if(a[i].nam==nam)
                {
                    cout<<a[i].l<<endl;
                    break;
                }
        }
        if(op==4)
        {
            int pos;
            cin>>pos;
            for(int i=1;i<=m;i++)
                if(a[i].l<=pos && pos<=a[i].r)
                {
                    cout<<a[i].l<<endl;
                    break;
                }
            cout<<"ERR"<<endl;
        }
    }
    return 0;
}
