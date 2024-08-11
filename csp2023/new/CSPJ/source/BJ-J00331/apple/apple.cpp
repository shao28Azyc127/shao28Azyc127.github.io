#include<bits/stdc++.h>
using namespace std;
long long n,a[100000000],cnt=1,pos=1,date[100000000],f=0;
int main()
{
    freopen("apple.in","r",stdin);
    freopen("apple.out","w",stdout);
    cin>>n;
    long long l=n;
    while(0){
        if(l>=3&&(l-1)%3!=0){
            l=l-l%3-1;
        }
        else if(l>=3&&(l-1)%3==0){
            l=l-l%3-1;
            date[f]=cnt;
            f++;
        }
        else if(l<3){
            l--;
        }
        cnt++;
    }
    cout<<cnt<<" "<<date[1];
    fclose(stdin);
    fclose(stdout);
    return 0;
}
