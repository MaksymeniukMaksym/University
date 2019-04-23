#include <iostream>
#include <stdio.h>

main() {
	int A[100][100],B[100]= {0},C[100],K[100]= {0},a,b,i,j,k,n,l,e,cina,cina1=20000,kil=0,kp=0,Q[100]= {9},w=10,R[100]= {9},k2,k1;
	char ch[12]="ABCDEFG ";
	printf("number of sets: \n");
	scanf("%d",&a);
	printf("the number of columns:\n");
	scanf("%d",&b);
	printf(" ");
	for(i=0; i<b; i++) {
		printf(" ");
		printf("%d",i+1);
	}
	printf(" price");
	printf("\n");
	for (i=0; i<a; i++) {
		printf("\n");
		printf("%c",ch[i]);
		for(j=0; j<=b; j++) {
			printf(" ");
			scanf("%d",&A[i][j]);
		}
	}
	printf("\n");
	for(e=0; e<a; e++) {
		cina=0;
		k=1;
		l=0;
		for(i=0; i<b; i++) {
			C[i]=0;
			B[i]=0;
			K[i]=0;
		}
		for(j=e; j<a; j++) {
			C[l]=j;
			kil++;
			n=0;
			for(i=0; i<b; i++) {
				B[i]+=A[j][i]+K[i];
				if(B[i]>0) n++;
			}
			cina+=A[j][b];
			if(n!=b) {
				n=0;
				for(i=0; i<k; i++)printf("%c",ch[C[i]]);
				printf(" - \n");
				for(i=0; i<b; i++) {
					K[i]=B[i];
					B[i]=0;
				}
				k++;
				l++;
			}
			if(n==b) {
				n=0;
				kp++;
				if(k<w) {
					for(i=0; i<k; i++)R[i]=C[i];
					w=k;
					k2=k;
				}
				for(i=0; i<k; i++)printf("%c",ch[C[i]]);
				if(cina<cina1) {
					cina1=cina;
					for(i=0; i<k; i++) Q[i]=C[i];
					k1=k;
				}
				printf("+ price - %d\n",cina);
				cina=cina-A[j][b];
				for(i=0; i<b; i++) {
					B[i]=0;
				}
			}
		}
		if (C[j]==a) break;
	}
	printf("\n\n");
	printf("answer:\n number of options - %d \nnumber of coatings - %d \n",kil,kp);

	printf("the cheapest cover - ");
	for(i=0; i<k1; i++) printf("%c",ch[Q[i]]);
	printf("\n");
	printf("the shortest cover - ");
	for(i=0; i<k2; i++) printf("%c",ch[R[i]]);
	printf("\n");
	return 0;
}
