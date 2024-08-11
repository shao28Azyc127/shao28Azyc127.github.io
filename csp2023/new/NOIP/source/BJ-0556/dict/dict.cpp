#include<bits/stdc++.h>

using namespace std;

struct node{
	char ch[3005];
	char mxc='a',mic='z';
}s[3005];

int t[3005][27];

int n,m;

void init(int a,int b,int c,int d,int i,int j){
	swap(s[i].ch[a],s[i].ch[b]);
	swap(s[j].ch[c],s[j].ch[d]);
	for(int k=1;k<=26;k++){
		t[i][k]=t[j][k]=0;
	}
	for(int k=1;k<=m;k++){
		t[i][s[i].ch[k]-'a'+1]++;
		t[j][s[j].ch[k]-'a'+1]++;
		s[i].mic=min(s[i].mic,s[i].ch[k]);
		s[j].mxc=max(s[j].mxc,s[j].ch[k]);
	}
}

int main(){
	freopen("dict.in","r",stdin);
	freopen("dict.out","w",stdout);
	
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		for(int j=1;j<=m;j++){
			cin>>s[i].ch[j];
			s[i].mxc=max(s[i].mxc,s[i].ch[j]);
			s[i].mic=min(s[i].mic,s[i].ch[j]);
			t[i][s[i].ch[j]-'a'+1]++;
		}
	}
	
	if(n==1){
		cout<<"1";
		return 0;
	}
	if(m==1){
		for(int i=1;i<=n;i++){
			bool flag=true;
			for(int j=1;j<=n;j++){
				if(i!=j)
				if(s[i].ch[1]>=s[j].ch[1]){
					cout<<0;
					flag=false;
					break;
				}
			}
			if(flag) cout<<1;
		}
		return 0;
	}
	
	for(int i=1;i<=n;i++){
		bool flag=true;
		for(int j=1;j<=n;j++){
			if(i!=j){
				if(s[i].mic>s[j].mxc){
					cout<<"0";
					flag=false;
					break;
				}else if(s[i].mic<s[j].mxc){
					continue;
				}else{
					int idxmn,cgmn;
					int idxmx,cgmx;
					for(int k=1;k<=m;k++){
						if(s[i].ch[k]==s[i].mic){
							t[i][s[i].mic-'a'+1]--;
							if(t[i][s[i].mic-'a'+1]==0){
								s[i].mic='z';
								for(int h=1;h<=m;h++){
									if(t[i][s[i].ch[h]-'a'+1]!=0 && s[i].ch[h]<s[i].mic){
										s[i].mic=s[i].ch[h];
									}
								}
							}
							continue;
						}else{
							
							for(int h=m;h>=1;h--){
								if(s[i].ch[h]==s[i].mic){
									idxmn=h;
									break;
								}
							}
							swap(s[i].ch[idxmn],s[i].ch[k]);
							cgmn=k;
							break;
						}
					}
					
					for(int k=1;k<=m;k++){
						if(s[j].ch[k]==s[j].mxc){
							t[j][s[j].mxc-'a'+1]--;
							if(t[j][s[j].mxc-'a'+1]==0){
								s[j].mxc='a';
								for(int h=1;h<=m;h++){
									if(t[i][s[j].ch[h]-'a'+1]!=0 && s[j].ch[h]<s[j].mxc){
										s[j].mic=s[j].ch[h];
									}
								}
							}
							continue;
						}else{
							for(int h=m;h>=1;h--){
								if(s[j].ch[h]==s[j].mxc){
									idxmx=h;
									break;
								}
							}
							swap(s[j].ch[idxmx],s[j].ch[k]);
							cgmx=k;
							break;
						}
					}
					
					if(s[i].ch<s[j].ch){
						init(idxmn,cgmn,idxmx,cgmx,i,j);
						continue;
					}else{
						init(idxmn,cgmn,idxmx,cgmx,i,j);
						cout<<"0";
						flag=false;
						break;
					}
					
				}
			}
		}
		if(flag){
			cout<<"1";
		}
	}
/*	
	for(int i=1;i<=n;i++){
		for(int j=1;j<=m;j++){
			cout<<s[i].ch[j];
		}
		cout<<" ";
		cout<<s[i].mic<<" "<<s[i].mxc;
		cout<<endl;
	}
*/	

	fclose(stdin);
	fclose(stdout);
	return 0;
}
