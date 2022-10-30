#  include 	<stdio.h>
#  include 	<malloc.h>
#  include 	<time.h>
#  include 	<stdlib.h>
#  include 	<assert.h>
# include <unistd.h>
# include <fcntl.h>
# include <sys/types.h>
# include <sys/stat.h>


#  define length(x) 	(sizeof (x)/sizeof (x[0]))

#  ifndef _N
#    define _N	(1e7+7)
#  endif

#  define true (1)
#  define false (0)

typedef unsigned char bool;

const int N= _N;

void quicksort(int a[], int l, int r);
void print_arr(int a[],int n);
bool is_sorted(int a[], int n);

int main()
{
    int *a = (int *) calloc(N, sizeof N);
    assert(a && "Out of Memory!");
    srand(time(NULL));
    printf("%s: Test case : N = %.0e\n",__FILE__, (double) N);
    
    for(int i=0;i < N; i++)
	a[i]=rand();
    
    clock_t c = clock();
    // the quicksort algorithm
    if(!is_sorted(a, N))
        quicksort(a, 0, N-1);
    printf("Took %.6f sec...\n", (float)(clock() - c) / CLOCKS_PER_SEC);
    free(a);
    return 0;
}

void quicksort(int a[], int l, int r)
{
     if(l<r)
     {
	 int j=l;
	 for(int i=l;i < r; i++)
	     if(a[i] < a[r])
	     {
		int c=a[i];
		a[i] =a[j];
		a[j++]=c;
	     }
	 int c=a[r];
	 a[r]=a[j];
	 a[j]=c;
	 quicksort(a, j+1, r);
	 quicksort(a, l, j-1);
     }
}

bool is_sorted(int a[], int n)
{
    for(int i=1;i < n; i++)
	if(a[i-1] > a[i])
	    return false;
    return true;
}

void print_arr(int a[],int n)
{
    for(int i=0;i < n;i++)
	printf("%d ", a[i]);
}
