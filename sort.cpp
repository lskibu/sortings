#  include <cstdio>
#  include <cstdlib>
#  include <ctime>
#  include <algorithm>
# include <unistd.h>
# include <fcntl.h>
# include <sys/types.h>
# include <sys/stat.h>


#ifndef _N
#  define _N (1e7+7)
#endif

const int N = _N;

int main()
{
    int *a = new int[N];
    printf("%s: Test case : N = %.0e\n",__FILE__, (double) N);
    srand(time(NULL));
    
    for(int i=0;i < N; i++)
        a[i]=rand();

    clock_t c = clock();
    std::sort(a, a + N);
    printf("Took %.6f secs...\n", (float) (clock() - c)/CLOCKS_PER_SEC);
    //for(int i=0;i < 10; i++)
   //	printf("%d %d \n", a[i], a[N-i-1]);
    delete a;
}
