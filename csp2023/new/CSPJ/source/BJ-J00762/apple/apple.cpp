#include <bits/stdc++.h>

using namespace std;

int main()
{
    freopen("apple.in","r",stdin);
    freopen("apple.out","w",stdout);
    int n;
    cin>>n;
    int b;
    int s=n;
    int q[n]={};
    int c=1;
    int bj=0;
    while(s)
    {
        if(s%3==1&&bj==0)
        {
            b=c;
            bj=1;
        }
        c++;
        s=s-(s/3);
        if(s%3<=2&&s%3>0)
        {
            s--;
        }
    }
    cout<<c<<" "<<b;
    fclose(stdin);
    fclose(stdout);
    return 0;
}
