#include<stdio.h>
#include<stdlib.h>

int isSort(int a[],int n){
	if(n==0 || n==1)
		return 0;
	if(a[n-1]<a[n-2])
		return 1;
	return isSort(a,n-1);
}
void sort(int a[],int n){
	int i,j,temp;
	for(i=0;i<n-1;i++){
		for(j=0;j<n-i-1;j++){
			if(a[j]>a[j+1]){
				a[j]=a[j]^a[j+1];
				a[j+1]=a[j]^a[j+1];
				a[j]=a[j]^a[j+1];
			}

		}
	}
	printf("After Sorting Array Is:\n");
	for(i=0;i<n;i++)
		printf("%d\t",a[i]);
}
int bsur(int a[],int lo,int hi,int x){
	int mid;
	if(isSort(a,hi+1)!=0){
		printf("Array Is Not Sorted.\n");
		sort(a,hi+1);
	}
	if(lo<=hi){
		mid=(lo+hi)/2;
		if(a[mid]==x)
			return mid;
		else if(a[mid]<x)
			bsur(a,mid+1,hi,x);
		else 
			bsur(a,lo,mid-1,x);
	}
	return -1;
}
int bsui(int a[],int lo,int hi,int x){
	int mid;
	if(isSort(a,hi+1)!=0){
		printf("Array Is Not Sorted.\n");
		sort(a,hi+1);
	}
	while(lo<=hi){
		mid=(lo+hi)/2;
		if(a[mid]==x)
			return mid;
		else if(a[mid]<x)
			lo=mid+1;
		else
			hi=mid-1;	
	}
	return -1;
}
int main(){
	int n,i,x,ch,r;
	int a[10];
	printf("Enter Size of Array: ");
	scanf("%d",&n);
	printf("Enter Array Element:\n");
	for(i=0;i<n;i++)
		scanf("%d",&a[i]);
	printf("Which Element You Want To Find?\n");
	scanf("%d",&x);
	printf("Press 1 for Binary Search Using Recurssion.\n");
	printf("Press 2 for Binary Search Using Itteration.\n");
	printf("Press 3 for Exit.\n");
	printf("Enter Your Choise:");
	scanf("%d",&ch);
	switch(ch){
		case 1:
			r=bsur(a,0,n-1,x);
			if(r!=-1)
				printf("\n%d Found At Position %d Of Current Array.",x,r+1);
			else
				printf("\n%d Not Present In Current Array.",x);
			break;
		case 2:
			r=bsui(a,0,n-1,x);
			if(r!=-1)
				printf("\n%d Found At Position %d.",x,r+1);
			else
				printf("\n63%d Not Present In Current Array.",x);
			break;
		case 3:
			exit(0);
		default:
			printf("Wrong Entry!!");
	}
	return 0;
}
