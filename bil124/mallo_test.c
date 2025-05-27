#include<stdio.h>
#include<stdlib.h>

int main(){
	
	int *ptr;
	int n, i;
	
	
	printf("Enter number of elements: ");
	scanf("%d",&n);
	printf("Entered element number= %d\n",n);
	
	ptr= (int*)malloc( n * sizeof(int));
	
	if(ptr==NULL)
		printf("Yer acýlamadý !!!!\n");
	else
		printf("BASARILI\n");	

	for(i=0;i<n;i++){
		
		ptr[i]=i+1;
	}
	
	printf("Lets see arrays %d elements: \n",n);
	for(i=0;i<n;i++){
		
		printf("%d\t",ptr[i]);
	}
		
	return 0;
}
