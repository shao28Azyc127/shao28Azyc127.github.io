#include <bits/stdc++.h>
using namespace std;
int n,on,d=0,d_n=-1,i=0;
bool flag=0;
int main()
{
    freopen("apple.in","r",stdin);
    freopen("apple.out","w",stdout);
    scanf("%d",&n);
    on=n;
    while(n>0)
    {
        i++;
        if((n-1)%3==0&&!flag)//di yi ci wan qvan zheng chu
        {
            n-=max(n/3,1);
            d_n=i,flag=1;
            //cout<<"1-";
        }
        else if(n%3==0)//wan qvan zheng chu
        {
            //cout<<"2-";
            n-=n/3;
        }
        else
        {
            //cout<<"3-";
            n-=n/3+1;
        }
        //cout<<n<<" "<<i<<endl;
    }
    printf("%d %d",i,d_n);
    return 0;
}
/*
in1:
8
out1£º
5 5
*/
