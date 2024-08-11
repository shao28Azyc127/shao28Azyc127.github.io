#include <bits/stdc++.h>
#define ll long long
using namespace std;

int n,k,op,f,gzj;
string s[105],sl[105][105],sm[105][105];
int slm[105];
ll szj[105],zj[105];

int main(){
	ios::sync_with_stdio(false);
	freopen("struct.in","r",stdin);
	freopen("struct.out","w",stdout);
	cin>>n;
	for(ll i=1;i<=n;i++){
		cin>>op;
		if(op==1){
			cin>>s[i]>>k;
			for(ll j=1;j<=k;j++){
				cin>>sl[i][j]>>sm[i][j];
				if(sl[i][j][0]=='b'&&sl[i][j][1]=='y'&&sl[i][j][2]=='t'&&sl[i][j][3]=='e'){
					slm[i]=max(slm[i],1);
					if((slm[i]+1)%1==0){
						szj[i]+=1;
					}else{
						szj[i]+=1-szj[i]%1+0;
					}
				}else if(sl[i][j][0]=='s'&&sl[i][j][1]=='h'&&sl[i][j][2]=='o'&&sl[i][j][3]=='r'&&sl[i][j][4]=='t'){
					slm[i]=max(slm[i],2);
					if((slm[i]+1)%2==0){
						szj[i]+=2;
					}else{
						szj[i]+=2-szj[i]%2+1;
					}
				}else if(sl[i][j][0]=='i'&&sl[i][j][1]=='n'&&sl[i][j][2]=='t'){
					slm[i]=max(slm[i],4);
					if((slm[i]+1)%4==0){
						szj[i]+=4;
					}else{
						szj[i]+=4-szj[i]%4+3;
					}
				}else if(sl[i][j][0]=='l'&&sl[i][j][1]=='o'&&sl[i][j][2]=='n'&&sl[i][j][3]=='g'){
					slm[i]=max(slm[i],8);
					if((slm[i]+1)%8==0){
						szj[i]+=8;
					}else{
						szj[i]+=8-szj[i]%8+7;
					}
				}else{
					for(ll z=1;z<i;z++){
						if(sl[i][j]==s[z]){
							slm[i]=max(slm[i],slm[z]);
							szj[i]+=szj[z]-1;
							break;
						}
					}
				}
			}
			if(szj[i]%slm[i]==0){		
				cout<<szj[i]<<" "<<slm[i]<<endl;
			}else{
				szj[i]+=slm[i]-szj[i]%slm[i];
				cout<<szj[i]<<" "<<slm[i]<<endl;
			}
		}else if(op==2){
			cin>>s[i]>>sm[i][1];
			cout<<zj[gzj]<<endl;
			if(s[i][0]=='b'&&s[i][1]=='y'&&s[i][2]=='t'&&s[i][3]=='e'){
				zj[gzj+1]+=1+zj[gzj];
			}else if(s[i][0]=='s'&&s[i][1]=='h'&&s[i][2]=='o'&&s[i][3]=='r'&&s[i][4]=='t'){
				zj[gzj+1]+=2+zj[gzj];
			}else if(s[i][0]=='i'&&s[i][1]=='n'&&s[i][2]=='t'){
				zj[gzj+1]+=4+zj[gzj];
			}else if(s[i][0]=='l'&&s[i][1]=='o'&&s[i][2]=='n'&&s[i][3]=='g'){
				zj[gzj+1]+=8+zj[gzj];
			}else{
				for(ll z=1;z<i;z++){
					if(sl[i][1]==s[z]){
						zj[gzj+1]+=zj[gzj]+szj[k];
						break;
					}
				}
			}
			gzj++;
		}else if(op==3){
			cout<<endl;
		}else{
			cout<<endl;
		}
	}
	return 0;
}
