#include<bits/stdc++.h>
using namespace std;
ifstream fin("apple.in");
ofstream fout("apple.ans");
int main()
{
    int n;
    fin>>n;
    int a[n];
    int sh=n;
    int jip=0,jit=0;
    for(int i=0;i<n;i++)
    {
        a[i]=i+1;
    }
    for(int i=1;;i*=3)
    {
        if(sh<=0) break;
        for(int j=0;j<n;j++)
        {
            if(j+1==n)
            {
                jip=jit+1;
            }
            if(a[j]%3==1)
            {
                a[i]=0;
                if(sh<=0) break;
            }
        }
        jit++;
    }
    fout<<jit<<" "<<jip;
    return 0;
}