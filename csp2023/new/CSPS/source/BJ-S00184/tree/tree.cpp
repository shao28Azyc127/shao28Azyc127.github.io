#include<bits/stdc++.h>
using namespace std;
int n,op;string typ,nam,jj;
struct ND{int dx,yq;};
map<string,ND>mp;
struct Node{int l,r;string s;}cd[10000],cl[10000];
int main(){
	freopen("tree.in","r",stdin);
	freopen("tree.out","w",stdout);
	mp["byte"].dx=mp["byte"].yq=1;
	mp["short"].dx=mp["short"].yq=2;
	mp["int"].dx=mp["int"].yq=4;
	mp["long"].dx=mp["long"].yq=8;
	int t=0,len=0;
	cin>>n;while(n--){
		cin>>op;if(op==2){
			cin>>typ>>nam;int dd;
			for(int i=t;;i++){
				if(i%mp[typ].yq==0){dd=i;break;}
			}t=dd;cout<<t<<endl;
			cd[++len].s=nam;cd[len].l=t;
			t+=mp[typ].dx;cd[len].r=t-1;
		}if(op==3){
			cin>>nam;int pd=0;
			for(int i=0;i<nam.size();i++){
				if(nam[i]=='.')pd++;
			}if(pd==0){
				for(int i=1;i<=len;i++){
					if(nam==cd[i].s){cout<<cd[i].l<<endl;break;}
				}
			}if(pd==1){
				string kl,kz;int sz=0,sz1=0,lk=0;
				for(int i=0;i<nam.size();i++){
					cout<<nam[i]<<endl;
					if(nam[i]=='.'){lk=1;continue;}
					if(lk==0)kl[sz++]=nam[i];
					if(lk==1)kz[sz1++]=nam[i];
				}
			}
		}if(op==4){
			int x;cin>>x;int kj=0;
			for(int i=1;i<=len;i++){
				if(x>=cd[i].l&&x<=cd[i].r){cout<<cd[i].s<<endl;kj=1;break;}
			}if(kj==0)cout<<"ERR"<<endl;
		}if(op==1){
			int u;cin>>jj>>u;int le=0,maxx=-9999999,tt=0;
			for(int yy=1;yy<=u;yy++){
				cin>>typ>>nam;int dd;
				maxx=max(maxx,mp[typ].yq);
				for(int i=tt;;i++){
					if(i%mp[typ].yq==0){dd=i;break;}
				}tt=dd;
				cl[++le].s=nam;cl[le].l=tt;
				tt+=mp[typ].dx;cl[le].r=tt-1;
			}cout<<cl[le].r+1<<" "<<maxx<<endl;
			mp[jj].dx=cl[le].r+1;mp[jj].yq=maxx;
		}
	}return 0;
}