#include<iostream>
#include<cstdio>
#include<cstring>
#include<ctime>
#include<cstdlib>
#include<algorithm>
#include<cmath>
#include<string>
#include<queue>
#include<vector>
#include<map>
#include<set>
#include<utility>
#include<iomanip>
using namespace std;
int read(){
    int xx=0,ff=1;char ch=getchar();
    while(ch>'9'||ch<'0'){if(ch=='-')ff=-1;ch=getchar();}
    while(ch>='0'&&ch<='9'){xx=xx*10+ch-'0';ch=getchar();}
    return xx*ff;
}
long long READ(){
    long long xx=0,ff=1;char ch=getchar();
    while(ch>'9'||ch<'0'){if(ch=='-')ff=-1;ch=getchar();}
    while(ch>='0'&&ch<='9'){xx=xx*10+ch-'0';ch=getchar();}
    return xx*ff;
}
char one(){
	char ch=getchar();
	while(ch==' '||ch=='\n')
		ch=getchar();
	return ch;
}
const int maxn=5010,maxm=10000010;
int N,M;
int lin[maxn],len;
struct edge{
	int y,next,v;
}e[maxm];
inline void insert(int xx,int yy,int vv){
	e[++len].next=lin[xx];
	lin[xx]=len;
	e[len].y=yy;
	e[len].v=vv;
}
void SPFA(){
	static int INF=1<<30;
	static int dis[maxn],q[maxn],head,tail;
	static bool vis[maxn];
	N=read(),M=read();
	memset(lin,0,sizeof(lin));len=0;
	for(int i=1;i<=M;i++){
		int t1=read(),t2=read(),t=read();
		insert(t1,t2,t);
	}
	for(int i=1;i<=N;i++)
		dis[i]=INF;
	head=1,tail=1,dis[1]=0,vis[1]=1;
	q[1]=1;
	int tim1=clock(),tim2;
	for(;head<=tail;head++){
		vis[q[head]]=0;
		for(int i=lin[q[head]];i;i=e[i].next)
			if(dis[e[i].y]>dis[q[head]]+e[i].v){
				dis[e[i].y]=dis[q[head]]+e[i].v;
				if(!vis[e[i].y]){
					q[++tail]=e[i].y;
					vis[e[i].y]=1;
				}
			}
	}
	tim2=clock();
	printf("%d\n",tim2-tim1);
}
int main(){
	freopen("in","r",stdin);
	SPFA();
	return 0;
}

