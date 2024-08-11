#include<iostream>
#include<cstring>
using namespace std;

int main ()
{
    freopen("apple.in","r",stdin);
    freopen("apple.out","w",stdout);
    int n;
    cin >> n;
    int ans=0;
    int len=n;
    int cnt=0;
    while(len!=0)
    {
        cnt+=1;
        if(len%3==0)
        {
            len=len/3*2;
        }
        else if(len%3==1)
        {
            len=len/3*2;
            if(ans==0)ans=cnt;
        }
        else if(len%3==2)
        {
            len=len/3*2+1;
        }
    }
    cout << cnt <<" "<< ans << endl;
    return 0;
}
