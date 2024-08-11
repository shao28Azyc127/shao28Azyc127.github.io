#include<iostream>

using namespace std;

int a[10][100][5];
int k=0;
int cnt=0;

void second(int where, int a1, int b, int c, int d, int e, int a_true, int b_true)
{
    int x, y;
    if(a1==-1&&b==-1)
    {
        x=(a_true+1)%10, y=(b_true+1)%10;
        for(int i=0;i<=9;i++)
        {
            if(x==a_true&&y==b_true) continue;
            a[where][k][0] = x;
            a[where][k][1] = y;
            a[where][k][2] = c;
            a[where][k][3] = d;
            a[where][k][4] = e;
            x = (x+1)%10;
            y = (y+1)%10;
            k++;
            cnt++;
        }
    }
    else if(b==-1&&c==-1)
    {
        x=(a_true+1)%10, y=(b_true+1)%10;
        for(int i=0;i<=9;i++)
        {
            if(x==a_true&&y==b_true) continue;
            a[where][k][0] = a1;
            a[where][k][1] = x;
            a[where][k][2] = y;
            a[where][k][3] = d;
            a[where][k][4] = e;
            x = (x+1)%10;
            y = (y+1)%10;
            k++;
            cnt++;
        }
    }
    else if(c==-1&&d==-1)
    {
        x=(a_true+1)%10, y=(b_true+1)%10;
        for(int i=0;i<=9;i++)
        {
            if(x==a_true&&y==b_true) continue;
            a[where][k][0] = a1;
            a[where][k][1] = b;
            a[where][k][2] = x;
            a[where][k][3] = y;
            a[where][k][4] = e;
            x = (x+1)%10;
            y = (y+1)%10;
            k++;
            cnt++;
        }
    }
    else
    {
        x=(a_true+1)%10, y=(b_true+1)%10;
        for(int i=0;i<=9;i++)
        {
            if(x==a_true&&y==b_true) continue;
            a[where][k][0] = a1;
            a[where][k][1] = b;
            a[where][k][2] = c;
            a[where][k][3] = x;
            a[where][k][4] = y;
            x = (x+1)%10;
            y = (y+1)%10;
            k++;
            cnt++;
        }
    }
}

void first(int where, int a1, int b, int c, int d, int e, int a_true)
{
    if(a1==-1)
    {
        for(int i=0;i<=9;i++)
        {
            if(i==a_true) continue;
            a[where][k][0] = i;
            a[where][k][1] = b;
            a[where][k][2] = c;
            a[where][k][3] = d;
            a[where][k][4] = e;
            cnt++;
            k++;
        }
    }
    else if(b==-1)
    {
        for(int i=0;i<=9;i++)
        {
            if(i==a_true) continue;
            a[where][k][0] = a1;
            a[where][k][1] = i;
            a[where][k][2] = c;
            a[where][k][3] = d;
            a[where][k][4] = e;
            cnt++;
            k++;
        }
    }
    else if(c==-1)
    {
        for(int i=0;i<=9;i++)
        {
            if(i==a_true) continue;
            a[where][k][0] = a1;
            a[where][k][1] = b;
            a[where][k][2] = i;
            a[where][k][3] = d;
            a[where][k][4] = e;
            cnt++;
            k++;
        }
    }
    else if(d==-1)
    {
        for(int i=0;i<=9;i++)
        {
            if(i==a_true) continue;
            a[where][k][0] = a1;
            a[where][k][1] = b;
            a[where][k][2] = c;
            a[where][k][3] = i;
            a[where][k][4] = e;
            cnt++;
            k++;
        }
    }
    else
    {
        for(int i=0;i<=9;i++)
        {
            if(i==a_true) continue;
            a[where][k][0] = a1;
            a[where][k][1] = b;
            a[where][k][2] = c;
            a[where][k][3] = d;
            a[where][k][4] = i;
            cnt++;
            k++;
        }
    }
}

int main()
{
    freopen("lock.in", "r", stdin);
    freopen("lock.out", "w", stdout);
    int n;
    cin>>n;
    int lock[20][5];
    for(int j=0;j<n;j++)
    {
        for(int i=0;i<5;i++)
        {
            cin>>lock[j][i];
        }
    }
    for(int i=0;i<n;i++)
    {
        cnt=0;
        first(i, -1, lock[i][1], lock[i][2], lock[i][3], lock[i][4], lock[i][0]);
        first(i, lock[i][0], -1, lock[i][2], lock[i][3], lock[i][4], lock[i][0]);
        first(i, lock[i][0], lock[i][1], -1, lock[i][3], lock[i][4], lock[i][0]);
        first(i, lock[i][0], lock[i][1], lock[i][2], -1, lock[i][4], lock[i][0]);
        first(i, lock[i][0], lock[i][1], lock[i][2], lock[i][3], -1, lock[i][0]);
        second(i, -1, -1, lock[i][2], lock[i][3], lock[i][4], lock[i][0], lock[i][1]);
        second(i, lock[i][0], -1, -1, lock[i][3], lock[i][4], lock[i][1], lock[i][2]);
        second(i, lock[i][0], lock[i][1], -1, -1, lock[i][4], lock[i][2], lock[i][3]);
        second(i, lock[i][0], lock[i][1], lock[i][2], -1, -1, lock[i][3], lock[i][4]);
    }
    int ans=0;
    int tmp=0;
    if(n==1)
    {
        cout<<cnt;
    }
    else
    {
        for(int i=0;i<n-1;i++)
        {
            for(int j=0;j<81;j++)
            {
                for(int k=0;k<5;k++)
                {
                    if(a[i][j][k] == a[i+1][j][k])
                    {
                        ans++;
                    }
                }
                if(ans==5)
                {
                    tmp++;
                }
            }
        }
        cout<<tmp;
    }
    return 0;
}
