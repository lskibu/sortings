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

void print_arr(int a[],int n);

int int_cmp(const void *p1,const void *p2)
{
    return *(int *)p1 - *(int *)p2;
}

int main()
{
    int *a = (int *) calloc(N, sizeof N);
    assert(a && "Out of Memory!");
    srand(time(NULL));
    printf("%s: Test case : N = %.0e\n",__FILE__, (double) N);
    
    for(int i=0;i < N; i++)
        a[i]=rand();

#ifdef _DEBUG 
	% N
#endif
		;
#ifdef _DEBUG
	print_arr(a, N);
#endif
    clock_t c = clock();
    // qsort
    qsort(a, N, sizeof N, int_cmp);
    printf("Took %.6f sec...\n", (float)(clock() - c) / CLOCKS_PER_SEC);
#ifdef _DEBUG
    print_arr(a, N);
#endif
    free(a);
    return 0;
}


void print_arr(int a[],int n)
{
    for(int i=0;i < n;i++)
	printf("%d ", a[i]);
}
