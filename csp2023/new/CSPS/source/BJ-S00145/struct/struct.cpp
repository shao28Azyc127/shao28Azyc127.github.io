#include<iostream>
#include<algorithm>
#include<cstring>
#include<cstdio>
#include<cmath>
#include<map>
using namespace std;
typedef long long LL;
LL n,ltp,tmp;
LL a[110][110][3],cnt1=4;
LL b[110][5],cnt2;
LL t1[5010][5010],t2[5010]; //t1:s->x->cnt1 t2:s->x->cnt2
string sss[5010],c[5010];
map<string,LL> m1;
LL cz(string s){
	if(m1[s]==0) m1[s]=++ltp,sss[ltp]=s;
	return m1[s];
}
bool find(int x,LL y){
	int cntt=t1[0][x],l=1,r=a[cntt][0][0];
	while(l<r){
		int mid=(l+r+1)>>1;
		if(a[cntt][mid][2]<=y) l=mid;
		else r=mid-1;
	}
	int z=a[cntt][l][0];
	if(z<5){
		if(a[t1[0][z]][2][0]<a[cntt][a[cntt][0][0]+1][0]) return 0;
		c[++tmp]=sss[a[cntt][l][1]];return 1;
	}
	//if(a[cntt][l][2]+a[t1[0][z]][a[t1[0][z]][0][0]+1][1]-1<y) return 0;
	c[++tmp]=sss[a[cntt][l][1]];
	return find(z,y-a[cntt][l][2]);
}
int main(){
	ios::sync_with_stdio(0);cin.tie(0);
	freopen("struct.in","r",stdin);
	freopen("struct.out","w",stdout);
	cz("byte"),cz("short"),cz("int"),cz("long");b[0][4]=-1;
	a[1][0][0]=a[2][0][0]=a[3][0][0]=a[4][0][0]=1;
	a[1][0][1]=1,a[2][0][1]=2,a[3][0][1]=3,a[4][0][1]=4;
	a[1][2][0]=a[1][2][1]=a[1][2][2]=1;t1[0][1]=1;
	a[2][2][0]=a[2][2][1]=a[2][2][2]=2;t1[0][2]=2;
	a[3][2][0]=a[3][2][1]=a[3][2][2]=4;t1[0][3]=3;
	a[4][2][0]=a[4][2][1]=a[4][2][2]=8;t1[0][4]=4;
	cin>>n;
	for(int i=1;i<=n;i++){
		int opt;cin>>opt;
		if(opt==1){
			int k;string s1,s2,s3;cin>>s1>>k;
			a[++cnt1][0][0]=k;a[cnt1][0][1]=cz(s1);
			t1[0][a[cnt1][0][1]]=cnt1;
			//cout<<a[cnt1][0][0]<<" "<<a[cnt1][0][1]<<"\n";
			for(int j=1;j<=k;j++){
				int x,y;cin>>s2>>s3;x=cz(s2),y=cz(s3);
				a[cnt1][j][0]=x;a[cnt1][j][1]=y;
				LL dx=a[t1[0][x]][a[t1[0][x]][0][0]+1][2];
				a[cnt1][k+1][0]=max(a[cnt1][k+1][0],dx);
				t1[cnt1][y]=j;
				//cout<<a[cnt1][j][0]<<" "<<a[cnt1][j][1]<<" ";
				//cout<<a[cnt1][j][2]<<"\n";
			}
			a[cnt1][0][2]=-a[cnt1][k+1][0];
			for(int j=1;j<=k;j++)
				a[cnt1][j][2]=a[cnt1][j-1][2]+a[cnt1][k+1][0];
			a[cnt1][k+1][2]=a[cnt1][k+1][0]*k;
			cout<<a[cnt1][k+1][2]<<" "<<a[cnt1][k+1][0]<<"\n";
		}
		if(opt==2){
			string s1,s2;cin>>s1>>s2;
			int x=cz(s1),y=cz(s2);t2[y]=++cnt2;
			b[cnt2][0]=x,b[cnt2][1]=y;
			b[cnt2][2]=++b[cnt2-1][4];
			//b[cnt2][3]=b[cnt2][2]+a[t1[0][x]][a[t1[0][x]][0][0]+1][1]-1;
			b[cnt2][4]=b[cnt2][2]+a[t1[0][x]][a[t1[0][x]][0][0]+1][2]-1;
			cout<<b[cnt2][2]<<"\n";
		}
		if(opt==3){
			string s,s1;cin>>s;
			int nn=s.size();s+='.';
			int k,kk,now=0;
			for(int j=0;j<=nn;j++){
				if(s[j]!='.'){s1+=s[j];continue;}
				int x=cz(s1);//cout<<x<<" ";
				if(now==0) k=b[t2[x]][2],now=1,kk=b[t2[x]][0];
				else{
					int cntt=t1[0][kk];
					k+=a[cntt][t1[cntt][x]][2];
					kk=a[cntt][t1[cntt][x]][0];
				}s1="";
				//cout<<k<<" "<<now<<" "<<kk<<"\n";
			}
			cout<<k<<"\n";
		}
		if(opt==4){
			LL x;cin>>x;tmp=0;
			int l=1,r=cnt2;
			while(l<r){
				int mid=(l+r+1)>>1;
				if(b[mid][2]<=x) l=mid;
				else r=mid-1;
			}
			if(b[l][0]<5){cout<<sss[b[l][1]]<<"\n";continue;}
			//if(b[l][4]<x){cout<<"ERR\n";continue;}
			c[++tmp]=sss[b[l][1]];
			int ttt=find(b[l][0],x-b[l][2]);
			if(!ttt){cout<<"ERR\n";continue;}
			for(int j=1;j<tmp;j++) cout<<c[j]<<".";
			cout<<c[tmp]<<"\n";
		}
	}
	return 0;
}
