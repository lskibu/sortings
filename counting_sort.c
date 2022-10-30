# include <stdio.h>
# include <stdlib.h>
# include <time.h>
# include <assert.h>


const int N = 1e7+7;


void counting_sort(int a[], int n);
void print_arr(int a[], int n);

int main(void)
{
    int *a = (int *) calloc(N, sizeof N);
    assert(a && "out of memory!");

    srand(time(NULL));
    for(int i=0;i < N;i++)
	a[i]=rand()%N;

    //print_arr(a, N);

    clock_t c = clock();
    counting_sort(a, N);
    printf("Took %.6f sec..\n", (float) (clock() - c) / CLOCKS_PER_SEC);

    //print_arr(a, N);
    free(a);
    return 0;
}

void counting_sort(int a[], int n)
{
    int *c = (int *) calloc(n, sizeof n);
    int *b = (int *) calloc(n, sizeof n);
    assert(c && b && "out of memory!");

    for(int i=0;i < n; i++) c[a[i]]++;
    for(int i=1;i < n; i++) c[i] = c[i] + c[i-1];
    for(int i=n-1;i >= 0; i--) b[c[a[i]]] = a[i], c[a[i]]--;
    for(int i=0;i < n; i++) a[i] = b[i];

    free(c);
    free(b);
};

void print_arr(int a[], int n)
{
    for(int i=0;i < n; i++)
    {
	if((i+1)%10==0) printf("\n");
	printf("%d ", a[i]);
    }
    putc(10, stdout);
};
