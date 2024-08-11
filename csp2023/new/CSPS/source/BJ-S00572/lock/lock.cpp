#include <iostream>
#include <vector>
using namespace std;
void lockin(int n,vector <vector<int>> &a)
{
    a.resize(n);
    int x;
    for(int i=0;i<n;i++)
    {
        for(int j=0;j<5;j++)
        {
            cin>>x;
            a[i].push_back(x);
        }
    }
}

void lock201(vector<vector<int>> &a,int n,vector<vector<int>> &b,int &k)
{
    int e=0;
    a.resize(n);
    //a[i].resize(5);
    lockin(n,a);
    for(int i=0;i<n;i++)
    {
        for(int y:a[i])
        {
            cout<<y;
        }
    }
    for(int i=0;i<n;i++)
    {
        long x=a[i][0]*10000+a[i][1]*1000+a[i][2]*100+a[i][3]*10+a[i][4];
        for(int y:a[i])
        {
            int it;
            it++;
            for(int z=0;z<10;z++)
            {
                cout<<z;
            }
        }
        for(int j=1;j<5;j++)
        {
            for(int z=0;z<=9;z++)
            {
                    int e=(z+a[i][j])%10;
                    x=x+10^j;
                    b[i].push_back(x);
                    k++;

            }
        }

        }
   for(int i=1;i<n;i++)
    {
        for(int j=0;j<n;j++)
        {
            for(int y:b[i-1])
            {
                if(y!=b[i][j]) k--;
            }
        }
    }
    }
void lock(vector<vector<int>> &b,int n)
{
    for(int i=1i<n;i++)
    {
        for(int y:b[i])
        {
            for(int x:b[i-1])
            {
                if(y!=x) k--;
            }
        }
    }
}
void cout01(vector<vector<int>> &a,int &n)
{
    for(int i=0;i<n;i++)
    {
        for(int y:a[i])
        {
            cout<<y;
        }
    }
}
int main()
{
    freopen("lock.in","r",stdin);
    freopen("lock.out","w",stdout);
    vector<vector<int>> a;
    vector<vector<int>> b;
    int n;
    int k=0;
    cin>>n;
    lockin(n,a);
    //cout01(a,n);
    if(n==1)   cout<<81;
    else
    {
        lock201(a,n,b,k);
        lock(b,n);
        cout<<k<<endl;
    }
    return 0;
}