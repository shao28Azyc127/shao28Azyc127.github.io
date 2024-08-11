#include<iostream>
#include<fstream>
using namespace std;
long long ans,n,cnt;
int main()
{
    ifstream fin("apple.in");
    ofstream fout("apple.out");
    fin>>n;
    long long i=n;
    while(n!=0)
    {
        n-=n/3+1;
        cnt++;
    }
    long long p=i-(i/3+1);
    fout<<cnt+1<<" ";
    if(i%3==1)fout<<1;
    else if(i%3==2){
        if(p%3==1)
        {
            fout<<2;
        }
        else fout<<cnt+1;
    }
    else fout<<2;
    return 0;
}
