#include <bits/stdc++.h>
using namespace std;
int n,day=0,op=0,i=0,temp;
bool apple[1000000000]={false},flag=false;
int main()
{
    freopen("apple.in","r",stdin);
    freopen("apple.out","w",stdout);
    scanf("%d",&n);
    while(1){
        i=0;
        op=0;
        while(i<n){
            if(apple[i]==false){
                if(op==0){
                    if(i==n-1) temp=day+1;
                    apple[i]=true;
                }
                op=(op+1)%3;
                flag=true;
            }
            i++;
        }
        day++;
        if(flag==false) break;
        flag=false;
    }
    printf("%d %d",day-1,temp);
    return 0;
}
