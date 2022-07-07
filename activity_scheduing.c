#include<stdio.h>
void disp(int a[],int n){
	int i;
	for(i=1;i<=n;i++);
		printf("%d\t",a[i]);	
}
int* gAs(int s[],int f[],int n){
	int j=1,i,size;
	int alist[20];
	alist[1]=1;
	int pre=1;
	for(i=2;i<=n;i++){
		if(s[i]>=f[pre]){
			alist[j]=i;
			j++;
			pre=i;
		
		}
	}
	size=sizeof(alist)/sizeof(alist[0]);
	printf("\n%d\n",j);
	printf("\nAfter Activity Scheduling:\n");
	disp(alist,j);
	return alist;
}
int main(){
	int i,n,size;
	int s[20],f[20],*alist;
	printf("Enter Number Of Element:");
	scanf("%d",&n);
	printf("Enter Starting Time Of Activity List Elements:\n");
	for(i=1;i<=n;i++)
	scanf("%d",&s[i]);
	printf("Enter Finished Time Of Activity List Elements:\n");
	for(i=1;i<=n;i++)
	scanf("%d",&f[i]);
	printf("Activity Scheduling Table:\n");
	printf("a[i]=\t");
	for(i=1;i<=n;i++){
		printf("%d\t",i);
	}
	printf("\ns[i]=\t");
	for(i=1;i<=n;i++){
		printf("%d\t",s[i]);
	}
	printf("\nf[i]=\t");
	for(i=1;i<=n;i++){
		printf("%d\t",f[i]);
	}
	alist=gAs(s,f,n);
	
	return 0;
}
