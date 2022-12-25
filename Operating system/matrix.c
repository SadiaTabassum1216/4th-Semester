/**
 * Matrix (N*N) multiplication with multiple threads.
 */
#include <stdio.h>
#include <stdlib.h>
#include <sys/time.h>
#include <pthread.h>

int msize, num_threads=9;
double mat1[msize][msize], mat2[msize][msize], mat3[msize][msize];
int count=0;
pthread_mutex_t mutex1 = PTHREAD_MUTEX_INITIALIZER;

void print_matrix( double matrix[msize][msize], int size )
{
  int i, j;

  for (i = 0; i < size; ++i) {
    for (j = 0; j < size-1; ++j) {
      printf( "%.2lf, ", matrix[ i ][ j ] );
    }
    printf( "%.2lf", matrix[ i ][ j ] );
    putchar( '\n' );
  }
}


void init_matrix( double matrix[msize][msize], double val )
{
  int i, j;

  for (i = 0; i < msize; ++i) {
    for (j = 0; j < msize; ++j) {
       matrix[ i ][ j ] = val;
    }
  }
}
/**
 * Thread routine.
 * Each thread works on a portion of the 'matrix1'.
 * The start and end of the portion depend on the 'arg' which
 * is the ID assigned to threads sequentially. 
 */
void * worker( void *arg )
{
  int i, j, k,  tid;
  double sum;

  tid = *(int *)(arg); 

  i = tid;


  for (j = 0; j < msize; ++j) {
    sum = 0.0;
    for (k = 0; k < msize; ++k) {
       pthread_mutex_lock( &mutex1 );
       sum += mat1[ i ][ k ] * mat2[ k ][ j ];
       pthread_mutex_unlock( &mutex1 );
    }
    mat3[ i ][ j ] = sum;
	
	//pthread_mutex_lock( &mutex1 );
	if(mat3[ i ][ j ] == 1){
 		//pthread_mutex_lock( &mutex1 );
		count++;
		//pthread_mutex_unlock( &mutex1 );
		}
	pthread_mutex_unlock( &mutex1 );

  }
}

int main( int argc, char *argv[] )
{
  int i;
  double sum = 0;
  struct timeval tstart, tend;
  double exectime;
  pthread_t  threads[9];

	
  if (argc != 2) {
    fprintf( stderr, "%s <matrix size>\n", argv[0] );
    return -1;
  }

  msize = atoi( argv[1] );

  init_matrix (mat1, 1);
  init_matrix (mat2, 2);

gettimeofday( &tstart, NULL );

  for ( i = 0; i < num_threads; ++i ) {
    int *tid;
    tid = (int *) malloc( sizeof(int) );
    *tid = i;
    pthread_create( &threads[i], NULL, worker, (void *)tid );
  }

  for ( i = 0; i < num_threads; ++i ) {
    pthread_join( threads[i], NULL );
  }
gettimeofday( &tend, NULL );

exectime = (tend.tv_sec - tstart.tv_sec) * 1000.0; // sec to ms
  exectime += (tend.tv_usec - tstart.tv_usec) / 1000.0; // us to ms   

  printf( "Number of threads: %d\tExecution time:%.3lf sec\n",
          num_threads, exectime/1000.0);

  if ( msize <= 10 ) {
    printf( "Matrix 1:\n" );
    print_matrix( mat1, msize );
    printf( "Matrix 2:\n" );
    print_matrix( mat2, msize );
    printf( "Matrix 3:\n" );
    print_matrix( mat3, msize );
  }

	printf("\nCount: %d\n",count);

  return 0;
}
