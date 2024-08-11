#include<bits/stdc++.h>
using namespace std;
int t[10],a[10][10],n,ans;
inline bool judge1(int i){
	bool flag=1;

        bool flg=0;
        for(int j=1;j<=5;j++){
            if(flg && t[j]!=a[i][j]){
               flag=0;
           	}
            if(!flg && t[j]!=a[i][j]){
               flg=1;
            }
        }
    return flag;

}
inline bool check(int a,int b,int c,int d){
	if(a<b && c>d) d+=10;
	if(a>b && c<d) c+=10;
	if(a-c==b-d) return 1;
	return 0;
}
inline bool judge2(int i){
	bool flag=1;
        bool flg=0;
        for(int j=1;j<=5;j++){
            if(t[j]!=a[i][j]){
            	if(!flg && check(t[j],t[j+1],a[i][j],a[i][j+1])) flg=1,j++;
            	else flag=0;
            }
        }

    return flag;

}
inline void dfs(int p){
    if(p==6){

        t[6]=8980;
        bool mark=0;
        for(int i=1;i<=n;i++){
            mark=0;
            for(int j=1;j<=5;j++){
                if(t[j]!=a[i][j]) mark=1;
            }
            if(!mark) return ;
        }

        for(int i=1;i<=n;i++){
            if(!judge1(i) && !judge2(i)) return ;
        }
        ans++;
    	return ;
    }
    for(int i=0;i<=9;i++){
        t[p]=i;
        dfs(p+1);
    }
}
int main(){
    freopen("lock.in","r",stdin);
    freopen("lock.out","w",stdout);
    ios::sync_with_stdio(0);
    cin>>n;
    for(int i=1;i<=n;i++){
        for(int j=1;j<=5;j++){
            cin>>a[i][j];
        }
    }
    dfs(1);
    cout<<ans;

    return 0;
}
