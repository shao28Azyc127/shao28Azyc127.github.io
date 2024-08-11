# include <bits/stdc++.h>

using namespace std;

const int N=15;

typedef long long ll;

# define Rep(i,a,b) for(int i=a;i<=b;i++)
# define _Rep(i,a,b) for(int i=a;i>=b;i--)
# define RepG(i,u) for(int i=head[u];~i;i=e[i].next)
# define PII pair<int,int>
# define mkp make_pair

template<typename T> void read(T &x){
    x=0;int f=1;
    char c=getchar();
    for(;!isdigit(c);c=getchar())if(c=='-') f=-1;
    for(;isdigit(c);c=getchar())x=x*10+c-'0';
    x*=f;
}

int n;
int a[N][N];
int b[N];
int ans;

int main()
{
    freopen("lock.in","r",stdin);
    freopen("lock.out","w",stdout);
    read(n);
    Rep(i,1,n)Rep(j,1,5)read(a[i][j]);
    Rep(b1,0,9){
        b[1]=b1;
        Rep(b2,0,9){
            b[2]=b2;
            Rep(b3,0,9){
                b[3]=b3;
                Rep(b4,0,9){
                    b[4]=b4;
                    Rep(b5,0,9){
                        b[5]=b5;
                        bool flag=true;
                        Rep(i,1,n){
                            int cnt=0,x=-1,y=-1;
                            Rep(j,1,5)
                                if(a[i][j]!=b[j]){
                                    cnt++;
                                    if(x==-1)x=j;
                                    else if(y==-1)y=j;
                                }
                            if(cnt>=3){
                                flag=false;
                                break;
                            }
                            if(cnt==0){
                                flag=false;
                                break;
                            }
                            if(cnt==1)continue;
                            if(y!=x+1){
                                flag=false;
                                break;
                            }
                            bool flagg=false;
                            Rep(j,0,9)if((a[i][x]+j)%10==b[x]&&(a[i][y]+j)%10==b[y])flagg=true;
                            if(!flagg){
                                flag=false;
                                break;
                            }
                        }
                        if(flag){
                            ans++;
                        }
                    }
                }
            }
        }
    }
    printf("%d\n",ans);
    return 0;
}