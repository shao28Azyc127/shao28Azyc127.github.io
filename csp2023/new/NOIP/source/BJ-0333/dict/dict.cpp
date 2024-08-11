#include<bits/stdc++.h>
using namespace std;
string s[3005];
int t[3005][30];
char mx[3005];
int mi[3005];
int n,m;
int pd(int x,int y)
{
    if(mi[x]<mx[y])return 1;
    return 0;

}
int  main()
{
    freopen("dict.in","r",stdin);
    freopen("dict.out","w",stdout);
    cin>>n>>m;
    for(int i = 1; i <= n; i++){
        cin>>s[i];
        mx[i] = 1;
        mi[i]=26;
        for(int j = 0; j <m ;j++){
            if(((int)(s[i][j])-int('a')+1)>mx[i])mx[i] = (int)(s[i][j])-int('a')+1;
            if(((int)(s[i][j])-int('a')+1)<mi[i])mi[i] = (int)(s[i][j])-int('a')+1;
        }
    }
    for(int i = 1; i <= n; i++){
            int flag = 0;
        for(int j = 1; j <= n; j++){
            if(i==j)continue;
            if(pd(i,j)==0){//
                flag =1;
                break;
            }
        }
        if(flag)printf("0");
        else printf("1");
    }
    cout<<endl;
    return 0;
}