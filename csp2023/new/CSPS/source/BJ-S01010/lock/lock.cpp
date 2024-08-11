#include<bits/stdc++.h>
using namespace std;
int n=1;
int arr[100][100];
bool check(int tmp[])
{
    int b=0;
    for(int i=1;i<=n;i++)
    {
        int ans=0;
        for(int j=1;j<=5;j++)
        {
            if(arr[i][j]!=tmp[j])ans++;
        }
        //cout<<ans<<endl;
        if(ans==1)b++;
        if(ans==2)
        {
            for(int j=1;j<=5;j++)
            {
                   if((arr[i][j]-tmp[j]==arr[i][j+1]-tmp[j+1])&&(arr[i][j]-tmp[j]!=0))ans++;
            }
            if(ans==3)
            {
                b++;
            }
            else return false;

        }
    }
    if(b==n)
    {
        for(int i=0;i<=2;i++)
        {
            for(int j=0;j<=6;j++)cout<<arr[i][j]<<' ';
            cout<<endl;
        }
        cout<<endl;
        for(int i=0;i<6;i++)cout<<tmp[i]<<' ';
        cout<<endl;
        return true;
    }
    return false;
}
int main()
{
    cin>>n;
    for(int i=1;i<=n;i++)
    {
        for(int j=1;j<=5;j++)
        {
            cin>>arr[i][j];
        }
    }
    int sum=0;
    for(int a1=0;a1<=9;a1++)
    {
        for(int a2=0;a2<=9;a2++)
        {
            for(int a3=0;a3<=9;a3++)
            {
                for(int a4=0;a4<=9;a4++)
               {
                    for(int a5=0;a5<=9;a5++)
                    {
                        int tmp[10];
                        tmp[1]=a1;
                        tmp[2]=a2;
                        tmp[3]=a3;
                        tmp[4]=a4;
                        tmp[5]=a5;
                        if(check(tmp))
                        {
                            cout<<a1<<' '<<a2<<' '<<a3<<' '<<a4<<' '<<a5<<endl;
                            sum++;
                       }
                    }
                }
            }
        }
    }
    cout<<sum;
    return 0;
}
