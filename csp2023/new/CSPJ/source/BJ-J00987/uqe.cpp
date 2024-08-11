#include<bits/stdc++.h>
using namespace std;
int aaaaa(int a,int b,bool top)
{
    if(a%b==0){
        if(top)
        {
            cout << a/b;
        }
        else
        {
            return b;
        }
    }
    //if()
    return 0;
}
int ys(int a)//sqrt de shi hou yong
{
    int aaaa=1;
    for(int i=2;i<(int)sqrt(a);i++)
    {
        if(a%(i*i)==0)
        {
            aaaa*=i;
            a/=i*i;
        }
    }
    return aaaa;
}

void jfc(int a,int b,int c)
{
    float delta=b*b-a*c*4;
    if(delta<0)
    {
        cout << "NO" << endl;
        return;
    }
    if(sqrt(delta)-(int)sqrt(delta)==0)
    {
        delta=sqrt(delta);
        b=abs(b);
        if(1.0*b/a/2-b/a/2==0){
            if(1.0*(delta+b)/a/2-1.0*(delta+b)/a/2==0){
                cout << (delta+b)/2/a << endl;
            }
        }

    }
    else
    {
        //cout <<

    }
}
int main()
{
    freopen("uqe.in","r",stdin);
    freopen("uqe.out","w",stdout);
    int n,m;
    cin >> n >>m;
    int a,b,c;

    for(int i=0;i<n;i++)
    {
        cin >> a >> b >> c;
        jfc(a,b,c);
    }

    return 0;
}
