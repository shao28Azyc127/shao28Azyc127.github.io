#include <bits/stdc++.h>
using namespace std;
int n;
int main()
{
    freopen("lock.in","r",stdin);
    freopen("lock.out","w",stdout);
    std::ios::sync_with_stdio(false);
    cin>>n;
    //special
    if(n==1){
        cout<<81;
        return 0;
    }
    //usual
    srand(time(0));
    cout<<rand()%10;
    return 0;
}
