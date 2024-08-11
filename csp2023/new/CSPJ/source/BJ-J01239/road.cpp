#include<bits/stdc++.h>
using namespace std;
ifstream fin("road.in");
ofstream fout("road.ans");
bool cmp(int a,int b)
{
    return a>b;
}
int main()
{
    int n,d;
    fin>>n>>d;
    int ju[n],yo[n];
    int i,j,k;
    int a[1000001];
    for(i=0;i<n;i++)
    {
        for(j=0;j<n;j++)
        {
            for(k=0;k<n;k++)
            {
                
            }
        }
    }
    i--;
    j--;
    k--;
    sort(a,a+i*j*k+1);
    cout<<a[i*j*k];
    return 0;
}
