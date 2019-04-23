
#include <stdio.h>
#include <locale.h>
int main() {
	setlocale(LC_ALL,"");
	int n=0, A[100][100], K[100], B[100]= {0};
	int l, k, x, y, i, j, q, w, e, r, temp, p;
	char ch[10] = "";
	printf(": \n");
	scanf("%d", &y);
	printf("(1-9):\n");
	scanf("%d", &x);
	printf(" ");
	for(i=0; i<x; i++) {
		printf(" ");
		printf("%d", i+1);
	}
	printf(" ");

	for (i=0; i<y; i++) {
		printf("\n");
		printf("%c", ch[i]);
		for(j=0; j<=x; j++) {
			printf(" ");
			scanf("%d", &A[i][j]);
		}
	}
	for(j=0; j<y; j++) {
		for(i=0; i<x; i++) {
			B[i]=0;
			n=0;
		}
		for(i=0; i<x; i++) {
			if(B[i]==0)
				B[i]+=A[j][i];

			if(B[i]!=0)
				n++;
		}
		temp=A[j][i];
		if(n==x)
			printf("\n %c ++%d", ch[j], temp);
		else

			printf("\n %c - ", ch[j]);
	}
	printf("\n\n\n");
	for(j=0; j<y-1; j++) {
		for(k=j+1; k<y; k++) {
			p=0;
			for(i=0; i<x; i++)
				B[i]=0;
			n=0;
			for(i=0; i<x; i++) {
				if(B[i]==0)
					B[i] += A[j][i] + A[k][i];
				if(B[i]!=0)
					n++;
			}
			for(i=0; i<x; i++) {
				if(B[i]>1)
					p++;
			}
			temp = A[j][i] + A[k][i];
			if(n==x)
				printf(" %c%c ++%d - - %d\n", ch[j], ch[k], temp, p);
			else
				printf(" %c%c - \n", ch[j], ch[k]);
		}
	}
	printf("\n\n\n");
	for(j=0; j<y-2; j++) {
		for(k=j+1; k<y-1; k++) {
			for(l=k+1; l<y; l++) {
				p=0;
				for(i=0; i<x; i++)
					B[i]=0;
				n=0;
				for(i=0; i<x; i++) {
					if(B[i]==0)
						B[i] += A[j][i] + A[k][i] + A[l][i];
					if(B[i]!=0)
						n++;
				}
				for(i=0; i<x; i++) {
					if(B[i]>1)
						p++;
				}
				temp = A[j][i] + A[k][i] + A[l][i];
				if(n==x)
					printf(" %c%c%c ++%d - - %d\n", ch[j], ch[k], ch[l], temp, p);
				else printf(" %c%c%c - \n", ch[j], ch[k], ch[l]);
			}
		}
	}
	printf("\n\n\n");
	for(j=0; j<y-2; j++) {
		for(k=j+1; k<y-1; k++) {
			for(l=k+1; l<y; l++) {
				for(q=l+1; q<y; q++) {
					p=0;
					for(i=0; i<x; i++)
						B[i] = 0;
					n = 0;
					for(i=0; i<x; i++) {
						if(B[i]==0)
							B[i] += A[j][i] + A[k][i] + A[l][i] + A[q][i];
						if(B[i]!=0)
							n++;
					}
					for(i=0; i<x; i++) {
						if(B[i] > 1)
							p++;
					}

					temp = A[j][i] + A[k][i] + A[l][i] + A[q][i];
					if(n==x)
						printf(" %c%c%c%c ++%d - - %d\n", ch[j], ch[k], ch[l], ch[q], temp, p);
					else
						printf(" %c%c%c%c - \n", ch[j], ch[k], ch[l], ch[q]);
				}
			}
		}
	}
	printf("\n\n\n");

	for(j=0; j<y-2; j++) {
		for(k=j+1; k<y-1; k++) {
			for(l=k+1; l<y; l++) {
				for(q=l+1; q<y; q++) {
					for(w=q+1; w<y; w++) {
						p=0;
						for(i=0; i<x; i++)
							B[i] = 0;
						n = 0;
						for(i=0; i<x; i++) {
							if(B[i]==0)
								B[i] += A[j][i] + A[k][i] + A[l][i] + A[q][i] + A[w][i];
							if(B[i]!=0)
								n++;
						}
						for(i=0; i<x; i++) {
							if(B[i] > 1)
								p++;
						}

						temp = A[j][i] + A[k][i] + A[l][q] + A[q][i] + A[w][i];
						if(n==x)
							printf(" %c%c%c%c%c ++%d - - %d\n", ch[j], ch[k], ch[l], ch[q], ch[w], temp, p);
						else
							printf(" %c%c%c%c%c - \n", ch[j], ch[k], ch[l], ch[q], ch[w]);
					}
				}
			}
		}
	}
	printf("\n\n\n");
	for(j=0; j<y-2; j++) {
		for(k=j+1; k<y-1; k++) {
			for(l=k+1; l<y; l++) {
				for(q=l+1; q<y; q++) {
					p=0;
					for(w=q+1; w<y; w++) {
						for(e=w+1; e<y; e++) {
							p=0;
							for(i=0; i<x; i++)
								B[i] = 0;
							n = 0;
							for(i=0; i<x; i++) {
								if(B[i]==0)
									B[i] += A[j][i] + A[k][i] + A[l][i] + A[q][i] + A[w][i] + A[e][i];
								if(B[i]!=0)
									n++;
							}
							for(i=0; i<x; i++) {
								if(B[i] > 1)
									p++;
							}

							temp = A[j][i] + A[k][i] + A[l][i] + A[q][i] + A[w][i] + A[e][i];
							if(n==x)
								printf(" %c%c%c%c%c%c ++%d -- %d\n", ch[j], ch[k], ch[l], ch[q], ch[w], ch[e], temp, p);
							else
								printf(" %c%c%c%c%c%c - \n", ch[j], ch[k], ch[l], ch[q], ch[w], ch[e]);
						}
					}
				}
			}
		}
	}
	printf("\n\n\n");

	for(j=0; j<y-2; j++) {
		for(k=j+1; k<y-1; k++) {
			for(l=k+1; l<y; l++) {
				for(q=l+1; q<y; q++) {
					for(w=q+1; w<y; w++) {
						for(e=w+1; e<y; e++) {
							for(r=e+1; r<y; r++) {
								p=0;
								for(i=0; i<x; i++)
									B[i]=0;
								n=0;
								for(i=0; i<x; i++) {
									if(B[i]==0)
										B[i] += A[j][i] + A[k][i] + A[l][i] + A[q][i] + A[w][i] + A[e][i] + A[r][i];
									if(B[i]!=0)
										n++;
								}
								for(i=0; i<x; i++) {
									if(B[i] > 1)
										p++;
								}

								temp = A[j][i]+ A[k][i]+ A[l][i]+ A[q][i]+ A[w][i]+ A[e][i]+ A[r][i];
								if(n==x)
									printf(" %c%c%c%c%c%c%c ++%d - - %d\n", ch[j], ch[k], ch[l], ch[q], ch[w], ch[e],    ch[r], temp, p);
								else
									printf(" %c%c%c%c%c%c%c - \n", ch[j], ch[k], ch[l], ch[q], ch[w], ch[e], ch[r]);
							}
						}
					}
				}
			}
		}
	}
	return 0;
}
