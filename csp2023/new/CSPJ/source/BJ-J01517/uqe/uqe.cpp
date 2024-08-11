#include<bits/stdc++.h>

using namespace std;

int T,M;

int gcd(int a,int b){
    if(b==0) return a;
    return gcd(b,a%b);
}

void get(int kid,int mum){
    int g=gcd(kid,mum);
    kid/=g;mum/=g;
    if(kid==0){
        printf("0");
        return;
    }
    if(kid<0 && mum<0){
        kid=abs(kid),mum=abs(mum);
    }
    if(kid>0 && mum<0){
        kid=-kid,mum=-mum;
    }
    if(mum==1){
        printf("%d",kid);
        return;
    }
    printf("%d/%d",kid,mum);
}

string g_string(int a){
    string s="";
    int d=0;
    if(a==0){
        s="0";
        return s;
    }
    if(a<0){
        d=1;
        a=-a;
    }
    while(a){
        s=char(a%10+'0')+s;
        a/=10;
    }
    if(d) s=string("-")+s;
    return s;
}

void go(int kid1,int kid2,int mum,int f){
    int t=sqrt(kid2);
    if(t*t==kid2){
        if(f==1) get(kid1+t,mum);
        else get(kid1-t,mum);
        return;
    }
    else{
        int y=mum;
        string s="";
        int g=gcd(kid1,mum);
        kid1/=g;mum/=g;
        if(kid1<0 && mum<0){
            kid1=abs(kid1),mum=abs(mum);
        }
        if(kid1>0 && mum<0){
            kid1=-kid1,mum=-mum;
        }
        if(kid1==0){
            s="";
        }
        else if(mum==1){
            s=g_string(kid1);
        }
        else{
            s=g_string(kid1)+string("/")+g_string(mum);
        }
        if(s!="") s+=string("+");

        int w;
        for(w=sqrt(kid2);w>1;--w) if(kid2%(w*w)==0) break;
        kid2/=w*w;
        if(f==2) w=-w;

        mum=y;
        g=gcd(w,mum);
        w/=g;mum/=g;
        if(kid1<0 && mum<0){
            w=abs(w),mum=abs(mum);
        }
        if(w>0 && mum<0){
            w=-w,mum=-mum;
        }
        if(w==1){
            s+=string("sqrt(")+g_string(kid2)+string(")");
            if(mum>1) s+=string("/")+g_string(mum);
        }
        else if(mum==1){
            s+=g_string(w)+string("*sqrt(")+g_string(kid2)+string(")");
        }
        else{
            s+=g_string(w)+string("*sqrt(")+g_string(kid2)+string(")/")+g_string(mum);
        }
        cout<<s;
    }
}

void work(int a,int b,int c){
    int arfa=b*b-4*a*c;
    if(arfa<0){
        printf("NO");
        return;
    }
    if(arfa==0){
        get(-b,2*a);
        return;
    }
    if(arfa>0){
        double x1,x2;
        x1=(-b+sqrt(arfa*1.0))/(2*a);
        x2=(-b-sqrt(arfa*1.0))/(2*a);
        if(x1>x2) go(-b,arfa,2*a,1);
        else go(-b,arfa,2*a,2);
    }
}

int main(){
    freopen("uqe.in","r",stdin);
    freopen("uqe.out","w",stdout);
    scanf("%d%d",&T,&M);
    //cout<<g_string(T)+"+"<<endl;
    while(T--){
        int a,b,c;
        scanf("%d%d%d",&a,&b,&c);
        work(a,b,c);
        if(T) printf("\n");
    }
    fclose(stdin);
    fclose(stdout);
    return 0;
}