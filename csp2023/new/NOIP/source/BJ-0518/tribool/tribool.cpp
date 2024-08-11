#include<iostream>
#include<cstring>
#include<cstdio>
using namespace std;
int c,t;
int n,m;
int step[100005][5];
int check[100005];
bool tri[100005];
/*
 * 1: 1+ -1-    0<-
 * 2: y   y     1T -1F 10U
 * 3: x   x      x
 * */

void pre(){
	bool flag=false;
	int tmp,start,cnt=0;
	for(int i=1;i<=m;i++){
		if(step[i][1]==-1){
			if(flag&&step[i][3]==tmp){
				cnt++;
				tmp=step[i][2];
				check[cnt]=step[i][2];
			}
			else{
				cnt=1;
				flag=true;
				start=step[i][3];
				tmp=step[i][2];
				check[1]=step[i][2];
			}
		}
	}
	if(start==tmp&&(cnt%2==1)){
		tmp=0;
		for(int i=1;i<=cnt;i++){
			if(tri[check[i]])tmp--;
			tri[check[i]]=true;
		}
		cnt+=tmp;
	}
	else cnt=0;
}

int solve(){
	int cnt=0;
	for(int i=1;i<=m;i++){
		if(tri[step[i][3]]){
			tri[step[i][2]]=true;
		}
		else if(tri[step[i][2]]){
			tri[step[i][2]]=false;
		}
	}
	for(int i=1;i<=n;i++){
		if(tri[i]){
			cnt++;
		}
	}
	return cnt;
}
 
int main(){
	freopen("tribool.in","r",stdin);
	freopen("tribool.out","w",stdout);
	cin>>c>>t;
	char sg;
	int x;
	while(t--){
		memset(step,0,sizeof(step));
		memset(tri,0,sizeof(tri));
		memset(check,0,sizeof(check));
		cin>>n>>m;
		for(int i=1;i<=m;i++){
			cin>>sg;
			switch(sg){
				case '-':
					step[i][1]=-1;
					cin>>step[i][2]>>step[i][3];
					break;
				case '+':
					step[i][1]=1;
					cin>>step[i][2]>>step[i][3];
					break;
				case 'F':
					i--;
					m--;
					cin>>x;
					tri[x]=false;
					break;
				case 'T':
					i--;
					m--;
					cin>>x;
					tri[x]=false;
					break;
				default:
					cin>>x;
					i--;
					m--;
					tri[x]=true;
					break;
			}
		}	
		if(c==1||c==2||c==7||c==8||c==9||c==10){
			pre();
		}
		cout<<solve()<<endl;
	}
	fclose(stdin);
	fclose(stdout);
	return 0;
}
