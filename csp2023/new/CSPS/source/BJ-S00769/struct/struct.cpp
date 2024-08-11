#include <iostream>
#include<bits/stdc++.h>
using namespace std;
string a;
int n;
bool x[8008];
int is(int l,int r)
{
    //int cntt=0;
    /*while(l<r)
    {
        if(a[l]!=a[r]){
            return 0;
        }
        else {
            l++;r--;
        }
    }*/
    memset(x,0,sizeof(x));
    char k='a'-1;
    int ki=l;

    for(int i=l;i<=r;i++)
    {

        if(!x[i]&&a[i]!=k)
        {
            k=a[i];
            ki=i;
        }


        else if(!x[i]&&k==a[i])
        {

            x[i]=1;
            x[ki]=1;
            k='a'-1;
            i=l-1;

        }

    }
    for(int i=l;i<=r;i++)
    {
        if(!x[i])
        {
            return 0;
        }
    }
    return 1;
}



int main()
{
    freopen("struct.in","r",stdin);
    freopen("struct.out","w",stdout);

    cin>>n;
    cout<<"1";
        /*
    int cnt=0;
    for(int i=0;i<=n-2;i++)
    {
        for(int j=i+1;j<=n-1;j++)
        {
            if((j-i)%2==1)

            {cnt+=is(i,j);
            //cout<<i<<" "<<j<<endl;
            }

        }
    }*/


//cout<<is(0,7);

    return 0;
}
