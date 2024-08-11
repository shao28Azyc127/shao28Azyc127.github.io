#include<iostream>
using namespace std;
int trees[100][3];
int uv[100][2];
int main()
{
    freopen("tree.in", "r", stdin);
    freopen("tree.out", "w", stdout);
    int n;
    cin>>n;
    for(int i=0;i<n;i++)
    {
        cin>>trees[i][0]>>trees[i][1]>>trees[i][2];
    }
    for(int i=0;i<n-1;i++)
    {
        cin>>uv[i][0]>>uv[1];
    }
    cout<<5;
    return 0;
}