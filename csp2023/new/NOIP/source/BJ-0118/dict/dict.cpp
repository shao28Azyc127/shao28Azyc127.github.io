#include<bits/stdc++.h>
typedef long long ll;
using namespace std;
const int N=3010;
string s;
int n,m,cnt[N][30],best[3][30],bd1=0,bd2=0;
bool ck(int cd,int bd){
    for(int i=26;i>=1;i--){
        if(cnt[cd][i]<best[bd][i])return 1;
        if(cnt[cd][i]>best[bd][i])return 0;
    }
    return 0;
}
void update(int x){
    if(ck(x,1)){
        for(int i=1;i<=26;i++)best[2][i]=best[1][i];
        bd2=bd1;
        for(int i=1;i<=26;i++)best[1][i]=cnt[x][i];
        bd1=x;
        return ;
    }
    if(ck(x,2)){
        for(int i=1;i<=26;i++)best[2][i]=cnt[x][i];
        bd2=x;
        return ;
    }
}
struct node{
    int cha,num;
};
node E[N],chea[3];
bool ckans(int x,int bd){
    if(E[x].cha<chea[bd].cha)return 1;
    return 0;
}
int main(){
    freopen("dict.in","r",stdin);
    freopen("dict.out","w",stdout);
    cin>>n>>m;
    if(n==1){
		cin>>s;
        cout<<"1";return 0;
    }
    for(int i=1;i<=n;i++){
        cin>>s;
        for(int j=0;j<m;j++){
            cnt[i][(s[j]-'a')+1]++;
        }
    }
    best[1][26]=s.length()+1,best[2][26]=s.length()+1;
    for(int i=1;i<=n;i++){
        update(i);
        for(int j=1;j<=26;j++){
            if(cnt[i][j]){E[i].cha=j;E[i].num=cnt[i][j];break;}
        }
    }
    for(int i=1;i<=2;i++){
        for(int j=26;j>=1;j--){
            if(best[i][j]){chea[i].cha=j;chea[i].num=best[i][j];break;}
        }
    }
    //for(int i=1;i<=n;i++){
	//	cout<<E[i].cha<<' '<<E[i].num<<'\n';
	//}
    //out<<bd1<<' '<<bd2<<'\n';
    //cout<<chea[1].cha<<' '<<chea[1].num<<'\n';
    //cout<<chea[2].cha<<' '<<chea[2].num<<'\n';
    for(int i=1;i<=n;i++){
        if(i==bd1){
            if(ckans(i,2)){
                cout<<"1";
            }else cout<<"0";
        }else{
            if(ckans(i,1)){
                cout<<"1";
            }else cout<<"0";
        }
    }
    return 0;
}
