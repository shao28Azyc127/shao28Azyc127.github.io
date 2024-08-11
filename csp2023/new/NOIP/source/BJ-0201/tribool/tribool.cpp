#include<bits/stdc++.h>
using namespace std;

#define MAXN 100005

int n,m,testcase;
char s[3];

struct acti{ int opt,x,y; }T[MAXN];
struct Value{ int conf,val,idt,coef,init; }V[MAXN];
vector<int> nE[MAXN];

//���ʲ�ͬ��״̬��һ��ȷ����ֵ����ĳ��������ͬ����ĳ�������෴���Լ��ĳ�ֵ��

int to[MAXN],coe[MAXN];

vector<int> circ;
int vis[MAXN],vis2[MAXN],Siz = 0;

void markTree( int u ){ Siz ++,vis2[u] = 1; for( int v : nE[u] ) if( !vis2[v] ) markTree( v ); }

inline pair<int,int> markcircle( int x ){
	circ.emplace_back( x ),vis2[x] = 1; int now = to[x],isp = 1;
	while( !vis2[now] ){
		circ.emplace_back( now ),vis2[now] = 1;
		now = to[now];
	}
	Siz = 0; for( int rts : circ ) markTree( rts ),isp *= coe[rts];
	// printf("info circle\n");
	// for( int rts : circ ) printf("%d %d\n",rts,coe[rts]);
	// printf("%d %d\n",isp,Siz);
	// printf("shenme %d\n",(int)circ.size());
	circ.clear();
	return make_pair( isp , Siz );
}

vector<int> nowhere;
int findcircle( int x ){
	if( !to[x] ) return x;
	if( vis[to[x]] ) return -x;
	vis[x] = 1,nowhere.emplace_back( x );
	return findcircle( to[x] );
}

void dfstree( int x ){
	vis2[x] = 1,Siz ++;
	for( int v : nE[x] ) if( !vis2[v] ) dfstree( v );
}

inline void solve(){
	int Ans = 0;
	scanf("%d%d",&n,&m);
	for( int i = 1 ; i <= m ; i ++ ){
		scanf("%s",s + 1);
		if( s[1] == 'T' ){
			int x; scanf("%d",&x); T[i] = acti{ 1 , x , 1 };
			//if( testcase == 4 ) printf("%s %d\n",s + 1,x);
		}
		else if( s[1] == 'F' ){
			int x; scanf("%d",&x); T[i] = acti{ 1 , x , -1 };
			//if( testcase == 4 ) printf("%s %d\n",s + 1,x);
		}
		else if( s[1] == 'U' ){
			int x; scanf("%d",&x); T[i] = acti{ 1 , x , 0 };
			//if( testcase == 4 ) printf("%s %d\n",s + 1,x);
		}
		else if( s[1] == '+' ){
			int x,y; scanf("%d%d",&x,&y); T[i] = acti{ 2 , x , y };
			//if( testcase == 4 ) printf("%s %d %d\n",s + 1,x,y);
		}
		else if( s[1] == '-' ){
			int x,y; scanf("%d%d",&x,&y); T[i] = acti{ 3 , x , y };
			//if( testcase == 4 ) printf("%s %d %d\n",s + 1,x,y);
		}
	}
	for( int i = 1 ; i <= n ; i ++ ) V[i] = Value{ 0 , 0 , 0 , 0 , 1 };
	for( int i = 1 ; i <= m ; i ++ ){
		int opt = T[i].opt;
		if( opt == 1 ) V[T[i].x] = Value{ 1 , T[i].y , 0 , 0 , 0 };
		else if( opt == 2 ){
			int conf = V[T[i].y].conf;
			if( conf ) V[T[i].x] = Value{ 1 , V[T[i].y].val , 0 , 0 , 0 };
			else{
				//if( V[T[i].y].init ) continue;
				if( V[T[i].y].idt ) V[T[i].x] = Value{ 0 , 0 , V[T[i].y].idt , V[T[i].y].coef , 0 };
				else V[T[i].x] = Value{ 0 , 0 , T[i].y , 1 , 0 };
			}
		}
		else if( opt == 3 ){
			int conf = V[T[i].y].conf;
			if( conf ) V[T[i].x] = Value{ 1 , -V[T[i].y].val , 0 , 0 , 0 };
			else{
				//if( V[T[i].y].init ) continue;
				if( V[T[i].y].idt ) V[T[i].x] = Value{ 0 , 0 , V[T[i].y].idt , -V[T[i].y].coef , 0 };
				else V[T[i].x] = Value{ 0 , 0 , T[i].y , -1 , 0 };
			}
		}
		// printf("end action %d\n",i);
		// for( int i = 1 ; i <= n ; i ++ ){
		// 	printf("%d %d %d %d %d\n",V[i].conf,V[i].val,V[i].idt,V[i].coef,V[i].init);
		// }
	}
	//һ��������Ȳ����Լ��ĳ�ֵҲ����ȷ����ֵ������һ�����ߣ�
	//�õ����ɿ��������ɿ����������
	for( int i = 1 ; i <= n ; i ++ ) to[i] = coe[i] = 0,nE[i].clear();
	for( int i = 1 ; i <= n ; i ++ ) vis[i] = vis2[i] = 0;
	for( int i = 1 ; i <= n ; i ++ ){
		if( V[i].init || V[i].conf ) continue;
		int u = i,v = V[i].idt; to[u] = v,coe[u] = V[i].coef;
		nE[u].emplace_back( v ),nE[v].emplace_back( u );
	}
	// for( int i = 1 ; i <= n ; i ++ ){
	// 	printf("%d %d %d\n",i,to[i],coe[i]);
	// 	for( int ele : nE[i] ) printf("edge %d %d\n",i,ele);
	// }
	int siz2 = 0,flag = 0,cnt = 0;
	for( int i = 1 ; i <= n ; i ++ ){
		if( !vis2[i] ){
			// cnt ++;
			nowhere.clear();
			int tmp = findcircle( i );
			if( tmp < 0 ){
				//����ҵ���һ�û��������õ��˻���һ��
				tmp = -tmp;
				pair<int,int> Val = markcircle( tmp );
				int fir = Val.first,sec = Val.second;
				//���ì����ôͳ�ƴ�
				// flag += sec;
				if( fir == -1 ) Ans += sec;
			}
			else{
				cnt ++;
				//����ҵ���һ�������õ��˸�
				Siz = 0;
				dfstree( tmp );
				siz2 += Siz;
				//��������� U ��ͳ�ƴ�
				if( V[tmp].conf && !V[tmp].val ){
					Ans += Siz;
					// printf("%d %d\n",cnt,siz2);
				}
			}
			for( int ele : nowhere ) vis[ele] = 0;
			// printf("%d %d %d %d\n",Ans1,Ans2,flag,cnt);
		}
	}
	printf("%d\n",Ans);
}

signed main(){
	freopen("tribool.in","r",stdin);
	freopen("tribool.out","w",stdout);
	int tid; scanf("%d%d",&tid,&testcase);
	while( testcase -- ) solve();
	return 0;
}