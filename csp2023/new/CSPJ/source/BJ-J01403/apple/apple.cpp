#include<bits/stdc++.h>
using namespace std;
int n,days,day;
bool flag=true;
int main()
{
    freopen("apple.in","r",stdin);
    freopen("apple.out","w",stdout);
    cin>>n;
    while(n>0)
    {
        days++;
        if(n%3==1 and flag==true)
        {
            day=days;
            flag=false;
        }
        n -= ((n/3)+(n%3 != 0));
    }
    cout<<days<<" "<<day;
    fclose(stdin);
    fclose(stdout);/**/

    //printf("test");
    return 0;
}
