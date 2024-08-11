#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
int N,op,x=1,y=1;
struct ele{
	string tp,na;
	int a;
	ll ads,ade;
}e[101];
struct stu{
	string sn,stk,stt[101],stn[101];
	ll sta,stl,stads[101],stade[101];
}st[101];
ll ad;
int main(){
	freopen("struct.in","r",stdin);
	freopen("struct.out","w",stdout);
	scanf("%d",&N);
	while(N--){
		scanf("%d",&op);
		if(op==1){
			string s,t[101],n[101];
			int k,maxa,add=0;
			cin>>s;
			printf("%d",&k);
			for(int i=1;i<=k;i++){
				cin>>t[i]>>n[i];
				st[x].stt[i]=t[i];
				st[x].stn[i]=n[i];
				if(t[i]=="byte"){
					maxa=max(maxa,1);
					st[x].stads[i]=add;
					st[x].stade[i]=add;
					add=st[x].stade[i]+1;
				}
				else if(t[i]=="short"){
					maxa=max(maxa,2);
					st[x].stads[i]=(add+1)/2*2;
					st[x].stade[i]=st[x].stads[i]+1;
					add=st[x].stade[i]+1;
				}
				else if(t[i]=="int"){
					maxa=max(maxa,4);
					st[x].stads[i]=(add+3)/4*4;
					st[x].stade[i]=st[x].stads[i]+3;
					add=st[x].stade[i]+1;
				}
				else if(t[i]=="long"){
					maxa=max(maxa,8);
					st[x].stads[i]=(add+7)/8*8;
					st[x].stade[i]=st[x].stads[i]+7;
					add=st[x].stade[i]+1;
				}
				else{
					for(int j=1;j<x;j++){
						if(t[i]==st.sn[j]){
							maxa=max(maxa,st[j].sta);
							st[x].stads[i]=(add+st[j].sta-1)/st[j].sta*st[j].sta;
							st[x].stade[i]=st[x].stads[i]+st[j].sta-1;
							add=st[x].stade[i]+1;
						}
					}
				}
			}
			st[x].stl=(add+st[x].sta-1)/st[x].sta*st[x].sta;
			st[x].stk=k;
			st[x].sta=maxa;
			st[x++].sn=s;
		}else if(op==2){
			string t,n;
			cin>>t>>n;
			if(t=="byte"){
				e[y].tp="byte";
				e[y].na=n;
				e[y].a=1;
				e[y].ads=ad;
				e[y].ade=ad;
				ad=e[y].ade+1;
				y++;
			}else if(t=="short"){
				e[y].tp="short";
				e[y].na=n;
				e[y].a=2;
				e[y].ads=(ad+1)/2*2;
				e[y].ade=ads+1;
				ad=e[y].ade+1;
				y++;
			}else if(t=="int"){
				e[y].tp="int";
				e[y].na=n;
				e[y].a=4;
				e[y].ads=(ad+3)/4*4;
				e[y].ade=ads+3;
				ad=e[y].ade+1;
				y++;
			}else if(t=="long"){
				e[y].tp="long";
				e[y].na=n;
				e[y].a=8;
				e[y].ads=(ad+7)/8*8;
				e[y].ade=ads+7;
				ad=e[y].ade+1;
				y++;
			}else{
				for(int i=1;i<x;i++){
					if(t=st[i].sn){
						e[y].tp=st[i].sn;
						e[y].na=n;
						e[y].a=st[i].sta;
						e[y].ads=(ad+e[y].a-1)/e[y].a*e[y].a;
						e[y].ade=ads+e[y].a-1;
						ad=e[y].ade+1;
						y++;
					}
				}
			}
		}else if(op==3){
			string s;
			cin>>s;
			for(int i=1;i<y;i++){
				if(s==e[i].na){
					printf("%lld\n",e[i].ads);
				}else{
					string ss[101];
					ll adds;
					int kk=1;
					for(int j=0;j<s.size();j++){
						if(s[j]=='.'){
							kk++;
						}
						ss[kk]=ss[kk]+s[j];
					}
					for(int j=1;j<=kk;j++){
						int kst;
						if(j==1){
							for(int k=1;k<y;k++){
								if(ss[j]==e[k].na){
									adds=e[k].ads;
								}
							}
							for(int k=1;k<x;k++){
								if(ss[j]==st[k].sn){
									kst=k;
								}
							}
						}else{
							for(int k=1;k<=st[kst].stk;k++){
								if(ss[j]=st[kst].stn[k]){
									adds+=st[kst].stads[k];
									kst=k;
								}
							}
						}
					}
					printf("%lld\n",adds);
				}
			}
		}else{
			ll addr;
			bool f=0;
			scanf("%lld",&addr);
			for(int i=1;i<y;i++){
				if(addr>=e[i].ads&&addr<=e[i].ade){
					f=1;
					if(e[i].tp=="byte"||e[i].tp=="short"||e[i].tp=="int"||e[i].tp=="long"){
						printf("%lld",e[i].ads);
					}else{
						string ss[101];
						ll adds;
						int kk=1;
						for(int j=0;j<s.size();j++){
							if(s[j]=='.'){
								kk++;
							}
							ss[kk]=ss[kk]+s[j];
						}
						for(int j=1;j<=kk;j++){
							int kst;
							if(j==1){
								for(int k=1;k<y;k++){
									if(ss[j]==e[k].na){
										adds=e[k].ads;
									}
								}
								for(int k=1;k<x;k++){
									if(ss[j]==st[k].sn){
										kst=k;
									}
								}
							}else{
								for(int k=1;k<=st[kst].stk;k++){
									if(ss[j]=st[kst].stn[k]){
										adds+=st[kst].stads[k];
										kst=k;
									}
								}
							}
						}
						printf("%lld\n",adds);
					}
				}
			}
			if(!f)printf("ERR\n");
		}
	}
	fclose(stdin);
	fclose(stdout);
	return 0;
}
