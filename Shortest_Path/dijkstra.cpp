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
int e[maxn][maxn];
void dijkstra(){
	static int INF=1<<30;
	static int dis[maxn];
	static bool vis[maxn];
	N=read(),M=read();
	memset(e,10,sizeof(e));
	for(int i=1;i<=M;i++){
		int t1=read(),t2=read(),t=read();
		if(t<e[t1][t2])
			e[t1][t2]=t;
	}
	memset(vis,0,sizeof(vis));
	memset(dis,10,sizeof(dis));
	dis[1]=0;
	int tim1=clock(),tim2;
	for(int i=1;i<N;i++){
		int minn=INF,c;
		for(int j=1;j<=N;j++)
			if(dis[j]<minn&&(!vis[j]))
				minn=dis[j],c=j;
		vis[c]=1;
		for(int j=1;j<=N;j++)
			if(dis[j]>dis[c]+e[c][j])
				dis[j]=dis[c]+e[c][j];
	}
	tim2=clock();
	printf("%d\n",tim2-tim1);
}
int main(){
	freopen("in","r",stdin);
	dijkstra();
	return 0;
}

