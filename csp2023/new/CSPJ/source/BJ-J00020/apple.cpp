#include<bits/stdc++.h>
#include<iostream>
using namespace std;
int main()
{
    freopen("apple.in","r",stdin);
    freopen("apple.out","w",stdout);
    int n,a[1000009]={0};
    cin>>n;
    int judg=2,day1=0,day2=1;
    while(1)
    {
        int j=1;
        for(int i=1;i<=n;i++)
        {
            if(a[i]==0&&judg==2)
            {
                //cout<<" "<<i<<" ";
                if(i==n) day1=day2;
                a[i]=1;
                judg=0;
                j=0;
            }
            else if(a[i]==0)
            {
                judg++;
                j=0;
            }
        }
        //cout<<endl;
        /*for(int i=1;i<=n;i++)
        {
            cout<<a[i]<<" ";
        }
        cout<<endl;*/
        if(j==1) break;
        else
        {
            judg=2;
            //cout<<day2<<endl;
            day2++;
        }
    }
    day2--;
    cout<<day2<<" "<<day1;
    fclose(stdin);
    fclose(stdout);
    return 0;
}