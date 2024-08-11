#include<bits/stdc++.h>
#define ll long long
using namespace std;
const int N=3005;
int n,m;
long long minchar[N],maxchar[N],minnum[N],maxnum[N];
string s[N];
void pre(int i){
minchar[i]='z'+1;
maxchar[i]='a'-1;
for(int j=0;j<m;j++){
    if(s[i][j]<minchar[i])minchar[i]=s[i][j];
    if(s[i][j]>maxchar[i])maxchar[i]=s[i][j];
}
for(int j=0;j<m;j++){
    if(s[i][j]==minchar[i])minnum[i]++;
    if(s[i][j]==maxchar[i])maxnum[i]++;
}
}
int main(){
freopen("dict.in","r",stdin);
freopen("dict.out","w",stdout);
cin>>n>>m;
for(int i=1;i<=n;i++){
    cin>>s[i];
    pre(i);
}
if(n==1){
    cout<<1;
    return 0;
}
for(int i=1;i<=n;i++){
    int flag=1;
    for(int j=1;j<=n;j++){
        if(j==i)continue;
        if(minchar[i]<maxchar[j])continue;
        else if(minchar[i]==maxchar[j]){
            if(minnum[i]>=maxnum[j]){
                flag=0;
                break;
            }
        }
        else{
            flag=0;
            break;
        }
    }
    cout<<flag;
}

return 0;
}
