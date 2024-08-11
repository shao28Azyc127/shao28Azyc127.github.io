#include <iostream>
using namespace std;
int main()
{
    freopen("apple.in","r",stdin);
    freopen("apple.out","w",stdout);
    int n,s=0,s2;
    bool w=0;
    cin>>n;
    while(n!=0)
    {
        s++;
        if(n%3==1&&!w)
            s2=s,w=1;
        n=n*2/3;
    }
    cout<<s<<" "<<s2;
    return 0;
}