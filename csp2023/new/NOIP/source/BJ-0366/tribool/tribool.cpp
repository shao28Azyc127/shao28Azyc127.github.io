#include<bits/stdc++.h>
#define pi(x) freopen(x,"r",stdin);
#define po(x) freopen(x,"w",stdout);
#define ci() fclose(stdin);
#define co() fclose(stdout);
using namespace std;
int c,t,n,m;
struct d{
	int target=0;
	int fromt=0;
	char fromv=0;
	bool rev=0;
}op[100005];
struct final_change{
	int from=0;
	char value=0;
	bool rev=0;
}x[100005];
vector<int>waited_res[100005];
void func(int rev,int i){
	for(int j=0;j<waited_res[i].size();j++){
		if(rev%2==1&&x[i].value=='T') x[waited_res[i][j]].value='F';
		else if(rev%2==1&&x[i].value=='F') x[waited_res[i][j]].value='T';
		else{
			x[waited_res[i][j]].value=x[i].value;
			//~ cout<<"value turn"<<waited_res[i][j]<<endl;
		}
		x[waited_res[i][j]].rev=x[i].rev;
		func(x[waited_res[i][j]].rev,waited_res[i][j]);
	}
}
void solve(){
	memset(waited_res,0,sizeof(waited_res));
	memset(x,0,sizeof(x));
	cin>>n>>m;
	for(int i=1;i<=m;i++){
		char u;
		cin>>u;
		if(u=='-'){
			int a,b;
			cin>>a>>b;
			op[i].target=a;
			op[i].fromt=b;
			op[i].fromv=0;
			op[i].rev=1;
		}
		else if(u=='+'){
			int a,b;
			cin>>a>>b;
			op[i].target=a;
			op[i].fromt=b;
			op[i].fromv=0;
			op[i].rev=0;
		}
		else{
			int a;
			cin>>a;
			op[i].target=a;
			op[i].fromv=u;
			op[i].rev=0;
			op[i].fromt=0;
		}
	}
	
	
	//~ cout<<"input done"<<endl;
	
	
	int cnt=0;
	for(int i=1;i<=n;i++){
		//~ cout<<i<<endl;
		char value=0;
		int rev=0;
		int targ=i;
		bool ran=0;
		for(int j=m;j>=1;j--){
			if(op[j].target==targ){
				ran=1;
				//~ cout<<targ<<" ";
				if(op[j].fromv&&!value){
					//~ cout<<12312<<" ";
					value=op[j].fromv;
					break;
				}
				else{
					//~ cout<<j<<endl<<op[j].fromt<<endl;;
					targ=op[j].fromt;
					if(op[j].rev) rev++;
				}
			}
		}
		//~ cout<<i<<" <- "<<targ<<" rev:"<<rev<<endl;
		//11111111111111111111111111111111111111111111111111111111111111111111111111
		if(!ran){
			//~ cout<<"random give num"<<endl;
			x[i].value='T';
			x[i].rev=0;
		}
		
		if(value){
			//~ cout<<"fu zhi give num"<<endl;
			x[i].value=value;
			x[i].rev=rev%2;
			func(x[i].rev,i);
		}
		else{
			if(i==targ){
				//~ cout<<"you give yourself num"<<endl;
				if(rev%2){
					x[i].value='U';
				}
				else x[i].value='T';
				x[i].rev=rev%2;
				func(x[i].rev,i);
				continue;
			}
			x[i].from=targ;
			if(targ<i){
				//~ cout<<"found the root num"<<endl;
				int j=targ,cnt=0;
				bool found=1;
				while(!x[j].value){
					//~ cnt++;
					//~ if(cnt>n){
						//~ x[i].value='U';
						//~ x[i].rev=rev%2;
						//~ break;
					//~ }
					if(j==x[j].from){
						if(rev%2){
							x[i].value='U';
						}
						else x[i].value='T';
						x[i].rev=rev%2;
						break;
					}
					j=x[j].from;
					rev+=x[j].rev;
					if(j>i){
						//~ cout<<"have wait for the root num"<<endl;
						waited_res[j].push_back(i);
						found=0;
						break;
					}
				}
				if(found){
					//~ cout<<rev<<" "<<x[j].value<<endl;
					if(rev%2==1&&x[j].value=='T'){
						 x[i].value='F';
						 //~ cout<<"FFF ";
					}
					else if(rev%2==1&&x[j].value=='F') x[i].value='T';
					else{
						x[i].value=x[j].value;
					}
					x[i].rev=rev%2;
					func(x[i].rev,i);
				}   //如果找到了
			}
			else{
				//~ cout<<"wait for the aim num"<<endl;
				waited_res[targ].push_back(i);
			}
		}
	}
	for(int i=1;i<=n;i++){
		//~ cout<<x[i].value<<" ";
		if(x[i].value=='U') cnt++;
	}
	cout<<cnt<<endl;
}

int main(){
	pi("tribool.in");
	po("tribool.out");
	ios::sync_with_stdio(false);
	cin>>c>>t;
	while(t--){
		solve();
	}
	ci();
	co();
}
/*
10 10
T 3
+ 1 2
- 7 1
+ 2 10
T 6
- 1 4
U 3
+ 7 10
F 5
+ 6 9
*/
