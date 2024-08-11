#include<bits/stdc++.h>
using namespace std;
int n,day1=0,day2=0,num=0;
int main() {
    freopen("apple.in","r",stdin);
    freopen("apple.out","w",stdout);
    cin>>n;
    int x=n;
    while (x>0) {
        day1++;
        if (num==0&&x%3==1) {
            num++;
            day2=day1;
        }
        int num=x/3;
        if (x%3!=0) num++;
        x-=num;
    }
    cout<<day1<<" "<<day2<<"\n";
    return 0;
}
