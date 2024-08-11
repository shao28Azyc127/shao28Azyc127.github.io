#include <bits/stdc++.h>
using namespace std;
int main()
{
    freopen("apple.in","r",stdin);
    freopen("apple.out","w",stdout);
    int a,l=0,k=1;
    cin>>a;
    while(a>0){
        l++;
        if((a-1)%3==0&&k==1) k=l;
        a-=(a-1)/3+1;
    }
    cout<<l<<" "<<k;
    fclose(stdin);
    fclose(stdout);
    return 0;
}
