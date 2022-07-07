#include<stdio.h>
#define MAX 50
#define INF 999999

int cost[MAX][MAX],dist[10],status[10], visited[MAX],prev[10];
void  dijks(int n,int v){
	int i,j,c,w,min,u;
	for(i=1;i<=n;i++){
		status[i]=0;
		dist[i]=cost[v][i];
		prev[i]=v;
		
	}
	dist[v]=0;
	status[v]=1;
	prev[v]=0;
	for(c=2;c<=n;c++){
		min=INF;
		for(w=1;w<=n;w++){
			if(dist[w]<min && status[w]!=1){
				min=dist[w];
				u=w;
			}
		}
		status[u]=1;
		for(w=1;w<=n;w++){
			if((dist[u]+cost[u][w])<dist[w] && status[w]==0){
				dist[w]=dist[u]+cost[u][w];
				prev[w]=u;
			}
		}
		
		
   }
}

int main(){
	int i, j, v, n;
	
	printf("Enter size of the matrix: ");
	scanf("%d", &n);
	printf("\nEnter value of matrix:\n");
	for(i=1;i<=n;i++){
		for(j=1;j<=n;j++){
			scanf("%d", &cost[i][j]);
			if(cost[i][j] == 0){
				cost[i][j]= INF;
			}
		}
	}	
	printf("\nEnter source vertex: ");
	scanf("%d", &v);
	dijks(n,v);
	printf("\nEnter Predecessor Array: ");
	for(i=1;i<=n;i++)
		printf("%d\t",prev[i]);
	
	printf("\nDistance Array: ");
	for(i=1;i<=n;i++){
		if(i!=v){
			printf("\n%d ---> %d = %d\n",v,i,dist[i]);
			j=i;
			printf("path: %d",i);
			while(j!=v){
				j=prev[j];
				printf("<--- %d",j);
			}
			printf("\n");
		}
			
	}
		
	return 0;
	
}
/*
0 10 0 0 5
0 0  1 0 2
0 0  0 4 0
7 0  6 0 0
0 3  9 2 0

*/
