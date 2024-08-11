#include<bits/stdc++.h>
using namespace std;
int a[8][5],n,diff[10][5]={0,},aa[8], cz;
int aaaa;
bool pd(int aaa,int b,int c,int d,int e){

    for(int i=0;i<n;i++)
    {
        if(a[i][0]==aaa&&a[i][1]==b&&a[i][2]==c&&a[i][3]==d&&a[i][4]==e){
            return 0;
        }
        if(a[i][0]==aaa&&a[i][1]==b&&a[i][2]==c&&a[i][3]==d&&a[i][4]!=e){
            continue;
        }
        else if(a[i][0]==aaa&&a[i][1]==b&&a[i][2]==c&&a[i][3]!=d&&a[i][4]==e){
            continue;
        }
        else if(a[i][0]==aaa&&a[i][1]==b&&a[i][2]!=c&&a[i][3]==d&&a[i][4]==e){
            continue;
        }
        else if(a[i][0]==aaa&&a[i][1]!=b&&a[i][2]==c&&a[i][3]==d&&a[i][4]==e){
            continue;
        }
        else if(a[i][0]!=aaa&&a[i][1]==b&&a[i][2]==c&&a[i][3]==d&&a[i][4]==e){
            continue;
        }
        else if(a[i][0]==aaa&&a[i][1]==b&&a[i][2]==c&&(10+a[i][3]-d)%10==(10+a[i][4]-e)%10){
            continue;
        }
        else if(a[i][0]==aaa&&a[i][1]==b&&a[i][4]==e&&(10+a[i][3]-d)%10==(10+a[i][2]-c)%10){
            continue;
        }
        else if(a[i][0]==aaa&&a[i][3]==d&&a[i][4]==e&&(10+a[i][1]-b)%10==(10+a[i][2]-c)%10){
            continue;
        }
        else if(a[i][3]==d&&a[i][4]==e&&a[i][2]==c&&(10+a[i][0]-aaa)%10==(10+a[i][1]-b)%10){
            continue;
        }
        else{
            return 0;
        }
    }
    return 1;
}
int main()
{
    freopen("lock.in","r",stdin);
    freopen("lock.out","w",stdout);
    int cntt=0;
    cin >> n;
    for(int i=0;i<n;i++)
    {
        for(int j=0;j<5;j++)
        {
            cin >> a[i][j];
        }
    }
    for(int i=0;i<10;i++)
    {
        for(int j=0;j<10;j++)
        {
            for(int k=0;k<10;k++)
            {
                for(int m=0;m<10;m++)
                {
                    for(int n=0;n<10;n++)
                    {
                        if(pd(i,j,k,m,n)){
                            cout << i << " " << j << " " << k << " " << m << " " << n << endl;
                            cntt++;
                        }
                    }
                }
            }
        }
    }
    cout << cntt << endl;
    return 0;
}
