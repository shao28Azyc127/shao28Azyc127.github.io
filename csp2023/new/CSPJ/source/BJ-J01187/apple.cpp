#include<iostream>
#include<cstdio>
#include<algorithm>
using namespace std;
int main(){
    freopen("apple.in","r",stdin);
    freopen("apple.out","w",stdout);
    int n;
    cin>>n;
    int tmp=n;
    int aday,nday,cnt=1;
    bool flag=0;
    while(tmp){
        if(tmp%3==1&&flag==0){
            nday=cnt;
            flag=1;
        }
        tmp=tmp*2/3;
        cnt++;
    }
    aday=cnt-1;
    printf("%d %d",aday,nday);
    fclose(stdin);
    fclose(stdout);
    return 0;
}
