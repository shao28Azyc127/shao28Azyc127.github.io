#include<bits/stdc++.h>
using namespace std;
long long l=0,c,l1=0;
string name1[105];
long long n,op,m,mm={0},num[105]={0};
string name[105],nl,sm;
int main(){
    freopen("struct.in","r",stdin);
    freopen("struct.out","w",stdout);
	cin>>n;
	for(int i=0;i<n;i++){
		cin>>op;
		if(op==1){
			mm=0;
			cin>>nl>>m;
			name[l]=nl;
			for(int j=0;j<m;j++){
				cin>>nl>>sm;
				if(nl=="byte" && mm<1) mm=1;
				else if(nl=="short" && mm<2) mm=2;
				else if(nl=="int" && mm<4) mm=4;
				else if(nl=="long" && mm<8) mm=8;
				else{
					for(int k=0;k<=l;k++)
						if(name[k]==nl) if(mm<num[k])mm=num[k];
				}
			}
			num[l]=mm*m;
			l+=1;
			cout<<mm*m<<" "<<mm<<endl;
		}
		if(op==2){
			cin>>nl>>sm;
			name1[l1]=sm;
			l1+=1;
		}
		if(op==3){
			cin>>sm;
			for(int j=0;j<l1;j++){
				if(name1[j]==sm){ cout<<8*j; break;}
			}
		}
		if(op==4){
			cin>>c;
			cout<<name1[c/8];
		}

	}
	return 0;
}