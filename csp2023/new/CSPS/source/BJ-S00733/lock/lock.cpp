#include<bits/stdc++.h>
using namespace std;

int ar[10];
int arr[15][90][10];

bool f(int i,int ii,int j,int jj)
{
    for(int a=0;a<5;a++)
    {
        if(arr[i][ii][a]!=arr[j][jj][a])
            return 0;
    }
    return true;
}

int g(int a,int b)
{
    if(a>=b)
        return (a-b)%10;
    else
        return 10+a-b;
}

int main()
{
    freopen("lock.in","r",stdin);
    freopen("lock.out","w",stdout);
    int n;
    cin >> n;
    int cnt = 0;
    for(int i=0;i<n;i++)
    {
        cnt = 0;
        for(int j=0;j<5;j++)
        {
            cin >> ar[j];
        }
        for(int j=0;j<5;j++)
        {
            for(int jj=0;jj<10;jj++)
            {
                if(jj!=ar[j])
                {
                    for(int jjj=0;jjj<5;jjj++)
                    {
                        if(jjj==j)
                            arr[i][cnt][jjj] =  jj;
                        else
                            arr[i][cnt][jjj] = ar[jjj];
                    }
                    cnt++;
                }
            }
        }
        for(int j=0;j<4;j++)
        {
            for(int jj=0;jj<10;jj++)
            {
                if(jj!=ar[j])
                {
                    for(int jjj=0;jjj<5;jjj++)
                    {
                        if(jjj==j)
                        {
                            arr[i][cnt][jjj++] = jj;
                            arr[i][cnt][jjj] = g(ar[j+1],ar[j]-jj);
                        }
                        else
                            arr[i][cnt][jjj] = ar[jjj];
                    }
                    cnt++;
                }
            }
        }
    }
    int ans = 0;
    bool bl = true;
    for(int i=0;i<n;i++)
    {
        for(int ii=0;ii<81;ii++)
        {
            for(int j=i+1;j<n;j++)
            {
                for(int jj=0;jj<81;jj++)
                {
                    bl = f(i,ii,j,jj);
                }
            }
            if(bl)
                ans++;
        }
    }
    cout << ans;
    return 0;
}
