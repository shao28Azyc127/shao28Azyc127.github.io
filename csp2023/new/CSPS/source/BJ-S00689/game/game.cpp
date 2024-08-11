#include<bits/stdc++.h>
#define ull unsigned long long
using namespace std;
const int N=2000005;
int n;
ull hsh[N];
ull M[N];
char s[N],tmp[N];
map<ull,int> mp;
ull Merge(int l,int r){
	if(r-l==2){
		int sum=0;
		if(s[r-1]==s[l]) sum++;
		if(s[l+1]==s[r]) sum++;
		return sum;
	}
	if(r-l==3){
		int sum=0;
		if(s[r-2]==s[l]) sum++;
		if(s[r-1]==s[l+1]) sum++;
		if(s[l+2]==s[r]) sum++;
		if((s[l]==s[l+1] && s[r-1]==s[r]) || (s[l]==s[r] && s[l+1]==s[r-1])) sum++;
		return sum;
	}
	int mid=(l+r)>>1;
	ull ans=Merge(l,mid)+Merge(mid+1,r);
	mp.clear();
	int cnt=0;
	hsh[0]=0ull;
	for(int i=1;i<=r-l+1;i++) tmp[i]='!';
	for(register int i=mid+1;i<=r;i++){
		if(cnt==0 || s[i]!=tmp[cnt]) tmp[++cnt]=s[i],hsh[cnt]=hsh[cnt-1]+M[cnt]*(s[i]-'a'+1);
		else cnt--;
		mp[hsh[cnt]]++;
	}
	cnt=0;
	hsh[0]=0ull;
	for(int i=1;i<=r-l+1;i++) tmp[i]='!';
	for(register int i=mid;i>=l;i--){
		if(cnt==0 || s[i]!=tmp[cnt]) tmp[++cnt]=s[i],hsh[cnt]=hsh[cnt-1]+M[cnt]*(s[i]-'a'+1);
		else cnt--;
		ans+=mp[hsh[cnt]];
	}
	return ans;
}
signed main(){
    freopen("game.in","r",stdin);
    freopen("game.out","w",stdout);
    M[0]=1;
    for(int i=1;i<=2000005;i++) M[i]=M[i-1]*30;
    scanf("%d",&n);cin>>(s+1);
    cout<<Merge(1,n);
    return 0;
}
