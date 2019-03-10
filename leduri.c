#include<stdio.h>
#include<stdlib.h>
#include <math.h>
#include <string.h>
typedef struct leduri
{
	char* nume;
	char* culoare;
	int intensitate;
}leduri;
typedef struct  rezistente
{
	char* nume;
	int val;
}rezistente;
void cerinta1(int N, leduri* led, FILE *f4)
{
	int i, MAX, k=0, nr=0;
	int *perechi;
	perechi=(int*)malloc(sizeof(int)*100);
	MAX=abs(led[0].intensitate-led[1].intensitate);
	for(i=0;i<N-1;i++){
			perechi[k]=abs(led[i].intensitate-led[i+1].intensitate);
			k=k+1;
		}
	for(i=0;i<k;i++)
		if(perechi[i]>MAX)
			MAX=perechi[i];
	for(i=0;i<k;i++){
		if(MAX==perechi[i])
			nr++;
	}
	fprintf(f4, "%d ",MAX);
	fprintf(f4, "%d\n",nr);
}
void swap(int *xp, int *yp)
{
    int temp = *xp;
    *xp = *yp;
    *yp = temp;
}
void bubbleSort(int *arr, int n)
{
   int i, j;
   for (i = 0; i < n-1; i++)      
       for (j = 0; j < n-i-1; j++) 
           if (arr[j] < arr[j+1])
              swap(&arr[j], &arr[j+1]);
}
void cerinta3(int N, int Y, int M, leduri* led, rezistente* rezistenta,FILE *f4)
{
	int i, j, MIN=0, l=0,  ok=0, a;
	int  *rezistente_ordonat;
	rezistente_ordonat=(int*)malloc(sizeof(int)*300);
	for(i=0;i<M;i++){
		rezistente_ordonat[l]=rezistenta[i].val;
		l++;
	}
	bubbleSort(rezistente_ordonat,M);
	for(i=0;i<M;i++){
	}
		for(i=0;i<N;i++){
		printf("%d\n",led[i].intensitate);
	}
	for(i=0;i<N;i++){
		for(j=0;j<M;j++){
			while(led[i].intensitate>Y){
					a=led[i].intensitate;
					led[i].intensitate-=rezistente_ordonat[j];
					MIN+=1;
					if(led[i].intensitate<Y){
						led[i].intensitate=a;
						MIN=MIN-1;
						break;
					}

			}
		}
	}
	for(i=0;i<N;i++){
		if(led[i].intensitate>Y)
			ok=1;
	}
	printf("%d\n",MIN);
	if(ok==0)
		fprintf(f4,"%d\n",MIN);
	else
		fprintf(f4, "-1\n");


}
int longest( int *x, int n, int *lmax_ref){
 	if (n == 1) 
 		return 1; 
 	int res, lmax_ending_here = 1;
 	int i;
 	for ( i = 1; i < n; i++){
 	res = longest(x, i, lmax_ref);
 	if (x[i-1] > x[n-1] && res + 1 > lmax_ending_here)
 		lmax_ending_here = res + 1;
 	}
 	if (*lmax_ref < lmax_ending_here)
 		*lmax_ref = lmax_ending_here;
 	return lmax_ending_here;
}
int longest_subseq(int *x, int n)
{

 	int *max_lenght = (int*) malloc(sizeof(int));
 	*max_lenght = 1;
 	longest( x, n, max_lenght );
 	return *max_lenght;
}
int nr=0;
void swappp(char *x, char* y)
{
    char* temp;
    temp=(char*)malloc(sizeof(char)*100);
    strcpy(temp,x);
    strcpy(x,y);
    strcpy(y,temp);
}
void swapp(int x, int y)
{
	int temp;
	temp=x;
	x=y;
	y=temp;
}
void permute(leduri *a, int l, int r, int K)
{
   int i,j=0;
   if (l == r){
 	for(i=0;i<r;i++){
 		if(strcmp(a[i].culoare,a[i+1].culoare)!=0 && abs(a[i].intensitate-a[i+1].intensitate)<K)
 			j++;
 	}
 	if(j==r)
 		nr++;
 }
   else
   {
       for (i = l; i <= r; i++)
       {
          swappp(a[l].culoare, a[i].culoare);
          swapp(a[l].intensitate, a[i].intensitate);
          permute(a, l+1, r, K);
          swappp(a[l].culoare, a[i].culoare);
          swapp(a[l].intensitate, a[i].intensitate);
       }
   }
}
int main(int argc, char *argv[])
{
	int N, K, Y, M, i,k=0, l=0;
	int c1, c2, c3, c4;
	leduri* led;
	int *a;
	leduri *b;
	a=(int*)malloc(sizeof(int)*100);
	b=(leduri*)malloc(sizeof(leduri)*100);
	rezistente* rezistenta;  
	FILE* f1,*f2, *f3,* f4;
	f1=fopen(argv[2],"r");
	if(f1==NULL)
		printf("fisierul nu a putut fi deschis!");
	fscanf(f1,"%d",&N);
	fscanf(f1,"%d",&Y);
	fscanf(f1,"%d",&K);
	led=(leduri*)malloc(sizeof(led)*300);
	for(i=0;i<N;i++){
		led[i].nume=(char*)malloc(sizeof(char)*100);
		led[i].culoare=(char*)malloc(sizeof(char)*100);
		fscanf(f1,"%s", led[i].nume);
		fscanf(f1,"%s", led[i].culoare);
		fscanf(f1,"%d", &led[i].intensitate);
		a[k]=led[i].intensitate;
		k++;
		b[l].culoare=led[i].culoare;
		b[l].intensitate=led[i].intensitate;
		l++;
	}
	fclose(f1);
	f2=fopen(argv[1],"r");
	if(f2==NULL)
		printf("fisierul nu a putut fi deschis!");
	fscanf(f2,"%d", &M);
	rezistenta=(rezistente*)malloc(sizeof(rezistente)*100);
	for(i=0;i<M;i++){
		rezistenta[i].nume=(char*)malloc(sizeof(char)*100);
		fscanf(f2,"%s", rezistenta[i].nume);
		fscanf(f2,"%d", &rezistenta[i].val);
	}
	fclose(f2);
	f3=fopen(argv[3],"r");
	if(f3==NULL)
		printf("fisierul nu a putut fi deschis!");
	fscanf(f3,"%d",&c1);
	fscanf(f3,"%d",&c2);
	fscanf(f3,"%d",&c3);
	fscanf(f3,"%d",&c4);
	fclose(f3);
	f4=fopen(argv[4],"w");
	if(f4==NULL)
		printf("fisierul nu a putut fi deschis!");
	if(c1==1)
	 	cerinta1(N,led,f4);
	 if(c2==1)
	 	fprintf(f4, "%d\n",N-longest_subseq(a,k));
	if(c3==1)
	 	cerinta3(N,Y, M, led, rezistenta,f4);
	 if(c4==1){
	 	permute(b, 0, l-1, K);
	 	fprintf(f4, "%d\n",nr);
	 }
	fclose(f4);
	free(led->nume);
	free(led->culoare);
	free(led);
	free(rezistenta->nume);
	free(rezistenta);
	free(a);
	free(b);
	return 0;
}