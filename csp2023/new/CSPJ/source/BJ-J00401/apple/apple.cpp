#include<bits/stdc++.h>
using namespace std;
long long n,a,c=0,b=-1;
bool f=1;
int main(){
    freopen("apple.in","r",stdin);
    freopen("apple.out","w",stdout);
    cin>>n;
    while(n>0){
        c+=1;
        a=n%3;
        if(a==1&&f){
        	b=c;
        	f=0;
		}
        if(!a)
        	n=n-(n/3);
        else
        	n=n-(n/3+1);
    }
    if(b>-1)
        cout<<c<<" "<<b;
    else
        cout<<c<<" "<<c;
    return 0;
}