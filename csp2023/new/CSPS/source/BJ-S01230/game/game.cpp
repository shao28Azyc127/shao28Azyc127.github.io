#include<bits/stdc++.h>
using namespace std;
char a0[8001];
bool a[8001][8001];
int a1;
int sum;
void s(int b1,int e1){
	a[b1][e1]=1;
	if(b1-1>=0&&e1+1<a1&&a0[b1-1]==a0[e1+1]){
		s(b1-1,e1+1);
	}if(e1+2<a1&&a0[e1+2]==a0[e1+1]){
		s(b1,e1+2);
	}if(e1+4<a1&&a0[e1+4]==a0[e1+1]&&a0[e1+3]==a0[e1+2]){
		s(b1,e1+4);
	}if(e1+6<a1&&a0[e1+6]==a0[e1+1]&&a0[e1+5]==a0[e1+2]&&a0[e1+4]==a0[e1+3]){
		s(b1,e1+6);
	}
}
int main(){
    freopen("game.in","r",stdin);
    freopen("game.out","w",stdout);
	cin>>a1;
	for(int i=0;i<a1;i++){
		cin>>a0[i];
	}for(int i=0;i<a1;i++){
		if(a0[i]==a0[i+1]){
			s(i,i+1);
		}
	}for(int i=0;i<a1;i++){
		for(int j=0;j<a1;j++){
			if(a[i][j]){
				sum++;
			}
		}
	}cout<<sum;
    fclose(stdin);
    fclose(stdout);
    return 0;
}
