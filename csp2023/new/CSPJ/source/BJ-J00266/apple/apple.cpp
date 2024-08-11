#include <bits/stdc++.h>
using namespace std;
int n,ans1,ans2;
string s;
vector <int> v;

int main()
{
    freopen("apple.in","r",stdin);
    freopen("apple.out","w",stdout);
    cin>>n;
    while (n>0){
        ans1++;
        int cn=n/3;
        if (n%3!=0) cn++;//shao de
        if (n%3==1&&ans2==0) ans2=ans1;
        n-=cn;
    }
    cout<<ans1<<" "<<ans2;
    return 0;
}
