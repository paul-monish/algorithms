#include<stdio.h>
/*
void disp(float a[],int n){
	int i;
	for(i=0;i<n;i++)
		printf("%0.1f\t",a[i]);
}*/
float gk(float p[],float w[],float m, int n){
	int i;
	float x[20],u,tp=0.0;
	u=m;
	for(i=0;i<n;i++)
		x[i]=0.0;
	for(i=0;i<n;i++){
		if(w[i]>u)
			break;
		else{
			x[i]=1.0;
			u=u-w[i];
		}
	}
	if(i<n)
		x[i]=u/w[i];
	for(i=0;i<n;i++)
		tp+=x[i]*p[i];
	printf("\nSolution Vector's:\n");
	for(i=0;i<n;i++)
		printf("%0.1f\t",x[i]);
	printf("\nTotal Profit= %0.1f",tp);
	return tp;
}

void swap(float *x,float *y){
	float t;
	t=*x;
	*x=*y;
	*y=t;
}
float maxP(float p[],float w[],float m,int n){
	int i,j;
	for(i=0;i<n-1;i++){
		for(j=0;j<n-i-1;j++){
			if(p[j]<p[j+1]){
				swap(&p[j],&p[j+1]);
				swap(&w[j],&w[j+1]);
			}
		}
	}
	return gk(p,w,m,n);
}
float minW(float p[],float w[],float m,int n){
	int i,j;
	for(i=0;i<n-1;i++){
		for(j=0;j<n-i-1;j++){
			if(w[j]>w[j+1]){
				swap(&p[j],&p[j+1]);
				swap(&w[j],&w[j+1]);
			}
		}
	}
	return gk(p,w,m,n);
}
float maxR(float p[],float w[],float m,int n){
	float r[20];
	int i,j;
	for(i=0;i<n;i++)
		r[i]=p[i]/w[i];
	for(i=0;i<n-1;i++){
		for(j=0;j<n-i-1;j++){
			if(r[j]<r[j+1]){
				swap(&r[j],&r[j+1]);
				swap(&p[j],&p[j+1]);
				swap(&w[j],&w[j+1]);
			}
		}
	}
	//disp(r,n);
	return gk(p,w,m,n);
}


int main(){
	float p[20],w[20],m,tp1,tp2,tp3;
	int n,i;
	printf("==========Knapsack Fractional Solution Using Greedy Algorithm===========\n");
	printf("Enter Number Of Item:");
	scanf("%d",&n);
	printf("Enter Capacity:");
	scanf("%f",&m);
	printf("\n");
	for(i=0;i<n;i++){
		printf("Enter Value For W[%d]= ",i);
		scanf("%f",&w[i]);
		printf("Enter Value For P[%d]= ",i);
		scanf("%f",&p[i]);
		printf("\n");
	}
	printf("\nSolution Using Maximum Profit-Weight Ratio:\n");
	tp1=maxR(p,w,m,n);
	printf("\n\nSolution Using Maximum Profit:\n");
	tp2=maxP(p,w,m,n);
	printf("\n\nSolution Using Minimum Weight:\n");
	tp3=minW(p,w,m,n);
	printf("\n");
	(tp1>tp2)?(tp1>tp3?printf("\nMaximum Profit-Weight Ratio Gives Optimal Solution."):printf("\nMinimum Weight Gives Optimal Solution.")):(tp2>tp3?printf("\nMaximum Profit Gives Optimal Solution."):printf("\nMaximum Profit-Weight Ratio Gives Optimal Solution."));
	return 0;	
}
