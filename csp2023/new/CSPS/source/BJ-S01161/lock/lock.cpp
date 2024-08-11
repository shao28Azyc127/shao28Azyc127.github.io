#include<bits/stdc++.h>
using namespace std;
int m[20][100],n[10],o[10],p[10];
struct q{
    int a,b,c,d,e;
}l[10];
int main(){
    freopen("lock.in","r",stdin);
    freopen("lock.out","w",stdout);
    int a,b,c,d,e;
    cin>>a;
    for (b=1;b<=a;b++) cin>>l[b].a>>l[b].b>>l[b].c>>l[b].d>>l[b].e;
    for (b=1;b<=4;b++)
    {
        for (c=b+1;c<=5;c++)
        {
            if (l[b].a!=l[c].a&&l[b].b!=l[c].b||l[b].a==l[c].a&&l[b].b==l[c].b) p[1]=(l[b].b+10-l[b].a)%10;
            if (l[b].a!=l[c].a&&l[b].b!=l[c].b||l[b].a==l[c].a&&l[b].b==l[c].b) p[2]=(l[b].c+10-l[b].b)%10;
            if (l[b].c!=l[c].c&&l[b].d!=l[c].d||l[b].c==l[c].c&&l[b].d==l[c].d) p[3]=(l[b].d+10-l[b].c)%10;
            if (l[b].d!=l[c].d&&l[b].e!=l[c].e||l[b].d==l[c].d&&l[b].e==l[c].e) p[4]=(l[b].e+10-l[b].d)%10;
        }
    }
    for (b=1;b<=a-1;b++)
    {
        for (c=b+1;c<=a;c++)
        {
            if (l[b].a!=l[c].a&&l[b].b!=l[c].b) n[6]=1;
            else if (l[b].b!=l[c].b&&l[b].c!=l[c].c) n[7]=1;
            else if (l[b].c!=l[c].c&&l[b].d!=l[c].d) n[8]=1;
            else if (l[b].d!=l[c].d&&l[b].e!=l[c].e) n[9]=1;
            else if (l[b].a!=l[c].a) n[1]=1;
            else if (l[b].b!=l[c].b) n[2]=1;
            else if (l[b].c!=l[c].c) n[3]=1;
            else if (l[b].d!=l[c].d) n[4]=1;
            else if (l[b].e!=l[c].e) n[5]=1;
        }
    }
    if (n[6]==1)
    {
        for (b=1;b<=a;b++) m[6][l[b].a*10+l[b].b]=1;
    }
    else if (n[7]==1)
    {
        for (b=1;b<=a;b++) m[7][l[b].b*10+l[b].c]=1;
    }
    else if (n[8]==1)
    {
        for (b=1;b<=a;b++) m[8][l[b].c*10+l[b].d]=1;
    }
    else if (n[9]==1)
    {
        for (b=1;b<=a;b++) m[9][l[b].d*10+l[b].e]=1;
    }
    else if (n[1]==1)
    {
        for (b=1;b<=a;b++) m[1][l[b].a]=1;
    }
    else if (n[2]==1)
    {
        for (b=1;b<=a;b++) m[2][l[b].b]=1;
    }
    else if (n[3]==1)
    {
        for (b=1;b<=a;b++) m[3][l[b].c]=1;
    }
    else if (n[4]==1)
    {
        for (b=1;b<=a;b++) m[4][l[b].d]=1;
    }
    else if (n[5]==1)
    {
        for (b=1;b<=a;b++) m[5][l[b].e]=1;
    }
    for (b=1;b<=5;b++)
    {
        for (c=0;c<=9;c++)
        {
            if (m[b][c]==0) o[b]++;
        }
    }
    for (b=6;b<=9;b++)
    {
        for (c=0;c<=9;c++)
        {
            if (m[b][c*10+(c+p[b-5])%10]==0) o[b]++;
        }
    }
    for (b=6;b<=9;b++)
    {
        if (n[b]==1)
        {
            cout<<o[b];
            return 0;
        }
    }
    for (b=1;b<=5;b++)
    {
        if (n[b]==1)
        {
            cout<<o[b];
            return 0;
        }
    }
    cout<<"81";
    return 0;
}
