#include<iostream>
using namespace std;
bool a[1000010]={};
int main()
{
    freopen("apple.in","r",stdin);
    freopen("apple.out","w",stdout);
    int n;
    cin>>n;
    if(n==1)
    {
        cout<<1<<" "<<1<<endl;
    }
    else if((n-1)%3==0)
    {
        cout<<n<<" "<<1<<endl;
    }
    else cout<<n<<" "<<n<<endl;
    return 0;
}
