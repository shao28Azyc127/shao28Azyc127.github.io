#include<iostream>
using namespace std;
int n,s,d,g;
bool f=true;
int main()
{
    freopen("apple.in","r",stdin);
    freopen("apple.out","w",stdout);
    cin>>n;
    s=n;
    while(1)
    {
        s=n;
        d++;
        if(s%3==1&&f)
        {
            g=d;
            f=false;
        }
        if(s<=1)
        {
            break;
        }
        for(int i=1;i<=s;i++)
        {
            if(i%3==1)
            {
                n--;
            }
        }

    }
    cout<<d<<" "<<g;
    return 0;
}