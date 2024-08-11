#include <bits/stdc++.h>
using namespace std;

int main()
{
    ifstream ifs;
    ofstream ofs;
    ifs.open("apple.in");
    ofs.open("apple.out");
    int n;
    ifs>>n;
    int ans1=0,ans2=-17543;
    while(n!=0)
    {
        int le=ceil(n/3.0);
        ans1++;
        if(n%3==1&&ans2==-17543)
            ans2=ans1;
        n-=le;
    }
    ofs<<ans1<<" "<<ans2;
    ifs.close();
    ofs.close();
    return 0;
}
