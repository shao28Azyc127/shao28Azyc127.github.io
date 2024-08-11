#include<bits/stdc++.h>
using namespace std;
int arr[10][10];
int ans;int c=0;
int main()
{
    freopen("lock.in","r",stdin);
    freopen("lock.out","w",stdout);
    int n;
    cin>>n;
    for(int i=0;i<n;i++)
        for(int j=0;j<5;j++)
        {
             cin>>arr[i][j];
        }

    for(int i=0;i<=99999;i++)
    {
        bool flag=1;
        int num[10]=
        {i/10000,(i%10000)/1000,(i%1000)/100,(i%100)/10,i%10};
        int pos[10][10];

        for(int j=0;j<n;j++)
        {
            int temp=0;
            for(int z=0;z<5;z++)
                if(arr[j][z]!=num[z])
                {
                    pos[j][temp]=z;
                    temp++;
                }

            int a= arr[j][pos[j][0]]-num[pos[j][0]];
            int b= arr[j][pos[j][1]]-num[pos[j][1]];
            if(a<0)
                a+=10;
            if(b<0)
                b+=10;
            if(!(temp==1&&(j==0||pos[j][0]==pos[j-1][0])||
                 (temp==2&&pos[j][1]-pos[j][0]==1&&a==b)))
                flag=0;
        }
        if(flag)
            ans++;
    }
    cout<<ans;

}
