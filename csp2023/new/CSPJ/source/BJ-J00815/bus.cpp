#include <iostream>
#include <bits/stdc++.h>
using namespace std;
int km;
int number;
int juli[10005];
int jiage[10005];

int main()
{
    freopen("road.in","r",stdin);
    freopen("road.out","w",stdout);
    cin>>number>>km;

    for (int i=1;i<number;i++)
    {
        cin>>juli[i];
    }
    for(int i=1;i<=number;i++)
    {
        cin>>jiage[i];
    }
    int jiaqian;
    int juli1=0;
    for (int a=1;a<number;a++)
    {
        juli1+=juli[a];
    }
    if (juli1&km!=0)
    {
        jiaqian=(juli1/km+1)*jiage[1];
    }
    else{
        jiaqian=juli1/km*jiage[1];
    }
    cout<<jiaqian
    return 0;
}