#include<stdio.h>
#include<math.h>
#define MAX 50
int c=0,x[MAX];
int place(int k, int i){
	int j;
	for(j=1;j<=k-1;j++){
		if((x[j]==i) || (abs(x[j]-i) == abs(j-k))){
			return 0;
		}
	}
	
	return 1;
}

void NQueens(int k, int n){
	int i,j;
	
	for(i=1;i<=n;i++){
		if(place(k,i)){
			x[k] = i;
			if(k == n){
				c++;
				printf("\nSolution vector: ");
				for(j=1;j<=n;j++){
					printf("%d\t",x[j]);
				}
				printf("\nChess Board:\n");
				for(i=1;i<=n;i++){
					for(j=1;j<=n; j++){
						if(x[i] == j){
							printf(" |Q|");
						}
						else{
							printf(" |_|");
						}
					}
					printf("\n");
				}
			}
			else{
				NQueens(k+1,n);
			}
		}
	}
}
int main(){
	int n;
	
	printf("Enter no. of queens: ");
	scanf("%d", &n);
	
	NQueens(1,n);
	printf("\nTotal no. of solutions: %d", c);
	
	return 0;
}
