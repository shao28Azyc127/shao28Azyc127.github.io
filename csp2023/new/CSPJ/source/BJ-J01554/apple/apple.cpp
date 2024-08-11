#include<bits/stdc++.h>
using namespace std;
long long n;
long long adsf;
long long cnnnnnnt=0;
long long lkjh;
int main(){
    freopen("apple.in","r",stdin);
    freopen("apple.out","w",stdout);
    cin>>n;
    lkjh=n;
    if(n%3==1){
        adsf=1;
    }
    else{
        while(lkjh>=0){
            if(lkjh%3==1){
                adsf=cnnnnnnt;
                adsf++;
                break;
            }
            if(lkjh==0){
                break;
            }
            lkjh=lkjh-((lkjh-1)/3+1);
            cnnnnnnt+=1;
        }
    }
    cnnnnnnt=0;
    while(n>=0){
		if(n==0){
            break;
        }
        n=n-((n-1)/3+1);
        cnnnnnnt+=1;
    }
    cout<<cnnnnnnt<<" "<<adsf;
    return 0;
}
