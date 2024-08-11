#include <iostream>
#include <algorithm>
using namespace std;
const int N=131;
int n,m;
bool flag=false;
char c[3010];
struct node{
    string s1,s2;
}s[3010];
bool cmp(char a,char b){
    return a<b;
}
int main(){
    freopen("dict.in","r",stdin);
    freopen("dict.out","w",stdout);
    scanf("%d %d",&n,&m);
    if(n==1){
        cout<<1;
        return 0;
    }
    for(int i=1;i<=n;i++){
        scanf("%s",c);
        sort(c,c+m,cmp);
        s[i].s1=c;
        reverse(c,c+m);
        s[i].s2=c;
    }
    for(int i=1;i<=n;i++){
        flag=false;
        for(int j=1;j<=n;j++){
            if(j==i){
                continue;
            }
            if(s[i].s1>s[j].s2){
                printf("0");
                flag=true;
                break;
            }
        }
        if(!flag){
            printf("1");
        }
    }
    fclose(stdin);
    fclose(stdout);
    return 0;
}
