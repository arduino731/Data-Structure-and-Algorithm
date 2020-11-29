/*
Insertion Sort
Test Size:      Test #0         Test #1         Test #2         Test #3         Test #4         Test #5         Test #6         Test #7         Test #8      
Test #9         Average
1000            0.006           0.004           0.003           0.003           0.003           0.003           0.003           0.003           0.002        
        0.003           0.003
2500            0.014           0.014           0.013           0.013           0.011           0.012           0.011           0.011           0.011        
        0.011           0.012
5000            0.043           0.044           0.043           0.044           0.044           0.044           0.043           0.042           0.043        
        0.044           0.043
7500            0.098           0.098           0.096           0.097           0.098           0.098           0.098           0.097           0.097        
        0.096           0.097
10000           0.171           0.171           0.172           0.170           0.173           0.172           0.173           0.169           0.170        
        0.171           0.171
quicksort (uses insertion sort when sorting <30 numbers)
Test Size:      Test #0         Test #1         Test #2         Test #3         Test #4         Test #5         Test #6         Test #7         Test #8      
Test #9         Average
1000            0.000           0.000           0.000           0.000           0.001           0.000           0.001           0.001           0.000        
        0.001           0.000
2500            0.001           0.001           0.001           0.001           0.001           0.001           0.001           0.001           0.001
        0.001           0.001
5000            0.002           0.002           0.001           0.001           0.001           0.002           0.001           0.002           0.001
        0.002           0.002
7500            0.002           0.002           0.003           0.002           0.003           0.002           0.002           0.003           0.003
        0.003           0.003
10000           0.003           0.004           0.003           0.003           0.003           0.003           0.003           0.004           0.003
        0.003           0.003
Mystery 1
Test Size:      Test #0         Test #1         Test #2         Test #3         Test #4         Test #5         Test #6         Test #7         Average
10000           0.002           0.002           0.003           0.003           0.003           0.003           0.003           0.003           0.003
20000           0.006           0.006           0.006           0.005           0.006           0.006           0.006           0.006           0.006
40000           0.011           0.010           0.010           0.010           0.010           0.010           0.010           0.010           0.010
80000           0.020           0.020           0.020           0.020           0.020           0.020           0.020           0.020           0.020
Mystery 2
Test Size:      Test #0         Test #1         Test #2         Test #3         Test #4         Test #5         Test #6         Test #7         Average
10000           0.168           0.164           0.164           0.165           0.166           0.169           0.167           0.164           0.166
20000           0.652           0.651           0.649           0.649           0.654           0.654           0.652           0.653           0.652
40000           2.655           2.618           3.015           2.610           2.605           2.600           2.595           2.608           2.663
80000           10.491          10.505          10.342          10.331          10.348          10.327          10.458          10.353          10.394
Mystery 3
Test Size:      Test #0         Test #1         Test #2         Test #3         Test #4         Test #5         Test #6         Test #7         Average
10000           0.040           0.039           0.038           0.039           0.038           0.038           0.039           0.039           0.039
20000           0.086           0.087           0.084           0.086           0.086           0.086           0.085           0.086           0.086
40000           0.193           0.195           0.192           0.193           0.195           0.193           0.192           0.195           0.194
80000           0.423           0.423           0.420           0.420           0.420           0.419           0.421           0.420           0.421
*/
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <math.h>

const char DATA_FILE_NAME[] = "TestData.txt";

typedef struct functionRuntimes
{
    char *name;             //name of the function being tested
    double **times;         //run times
    double *avg;            //average runtime
    int numTestCases;       //number of times to repeat each test size
    int numTestCaseSizes;   //number of test sizes
    int *testCaseSizes;     //array containing the test sizes
} functionRuntimes;

//Functions used to test the runtimes
functionRuntimes timeAlgorithm( char*, int, int, int[], void (*f)(FILE *) );
FILE *generateTestInput( int, int, int );
void computeAvg( functionRuntimes fRT );
void printRuntimeTable( functionRuntimes fRT );
void freeFunctionRuntimes( functionRuntimes fRT );

//Functions whose runtime will be tested (and helper functions)
void insertionSortInitial( FILE* input );
void insertionSort( int* points, int low, int high );
void quickSortOptInitial( FILE* input );
void quickSortOpt( int* points, int low, int high );
int partition( int* points, int low, int high );

void mysteryRuntime1( FILE* input );
void mysteryRuntime2( FILE* input );
void mysteryRuntime3( FILE* input );

/*
 * Provided code - DO NOT CHANGE THIS METHOD
 * (if you make alterations plan to revert them before submission)
 */
int main( int argc, char *argv[] )
{
    functionRuntimes fRT;

    int sizes1[] = { 1000, 2500, 5000, 7500, 10000};
    int sizes2[] = { 10000, 20000, 40000, 80000};

    srand(time(0));

    fRT = timeAlgorithm("Insertion Sort", 10, 5, sizes1, insertionSortInitial );
    printRuntimeTable(fRT);
    freeFunctionRuntimes(fRT);

    fRT = timeAlgorithm("quicksort (uses insertion sort when sorting <30 numbers)", 10, 5, sizes1, quickSortOptInitial );
    printRuntimeTable(fRT);
    freeFunctionRuntimes(fRT);

    fRT = timeAlgorithm("Mystery 1", 8, 4, sizes2, mysteryRuntime1 );
    printRuntimeTable(fRT);
    freeFunctionRuntimes(fRT);

    fRT = timeAlgorithm("Mystery 2", 8, 4, sizes2, mysteryRuntime2 );
    printRuntimeTable(fRT);
    freeFunctionRuntimes(fRT);

    fRT = timeAlgorithm("Mystery 3", 8, 4, sizes2, mysteryRuntime3 );
    printRuntimeTable(fRT);
    freeFunctionRuntimes(fRT);

    return 0;
}

/*************************************** Functions to have their runtimes tested *********************************************/

/* provided code - DO NOT CHANGE
 */
void mysteryRuntime1( FILE* input )
{
    int temp;
    int size;
    int i=0;
    int *array;

    if( fscanf( input, "%d", &size ) != 1 )
    {
        exit(-1);
    }
    array = (int *) malloc( size*sizeof(int) );
    if( array == NULL )
    {
        exit(-1);
    }

    while( fscanf( input, "%d", &temp ) == 1 && i<size)
    {
        array[i] = temp;
        i++;
    }

    while( size>1 )
    {
        size = size/2;
        array[size/2] = array[size];
    }

    free(array);
}

/* provided code - DO NOT CHANGE
 */
void mysteryRuntime2( FILE* input )
{
    int temp;
    int size;
    int i=0, j=0;
    int *array;

    if( fscanf( input, "%d", &size ) != 1 )
    {
        exit(-1);
    }
    array = (int *) malloc( size*sizeof(int) );
    if( array == NULL )
    {
        exit(-1);
    }

    while( fscanf( input, "%d", &temp ) == 1 && i<size)
    {
        array[i] = temp;
        i++;
    }

    i=0;
    while( j<size )
    {
        array[j] = array[i];

        i++;
        if( i>=size )
        {
            j++;
            i=0;
        }
    }

    free(array);
}

/* provided code - DO NOT CHANGE
 */
void mysteryRuntime3( FILE* input )
{
    int temp;
    int size;
    int n;
    int i=0;
    int *array;

    if( fscanf( input, "%d", &size ) != 1 )
    {
        exit(-1);
    }
    array = (int *) malloc( size*sizeof(int) );
    if( array == NULL )
    {
        exit(-1);
    }

    while( fscanf( input, "%d", &temp ) == 1 && i<size)
    {
        array[i] = temp;
        i++;
    }

    for( i=0; i<size; i++ )
    {
        for( n=size-1; n>1; n/=1.01 )
        {
            array[n-1] = array[n];
        }
    }

    free(array);
}


/*
 * Provided code - DO NOT CHANGE THIS METHOD
 */
void insertionSortInitial( FILE* input )
{
    int i;
    int size;
    int *array;

    fscanf( input, "%d", &size );
    array = (int *) malloc( size*sizeof(int) );

    for( i=0; i<size; i++)
    {
        fscanf( input, "%d", &array[i] );
    }

    insertionSort( array, 0, size-1 );

    //Error check to verify the array is sorted
    /*for( i=1; i<size; i++)
    {
        if(array[i-1]>array[i])
        {
            printf("Not sorted!");
            exit(-1);
        }
    }*/

    free(array);
}

/*
 * Provided code - DO NOT CHANGE THIS METHOD
 */
void insertionSort( int* points, int low, int high )
{
    int i, j;
    double temp;

    for( i = low+1; i <= high; i++)
    {
        for( j = i; j > low && points[j]<points[j-1]; j--)
        {
            temp = points[j];
            points[j] = points[j-1];
            points[j-1] = temp;
        }
    }
}

/*
 * Provided code - DO NOT CHANGE THIS METHOD
 */
void quickSortOptInitial( FILE* input )
{
    int i;
    int size;
    int *array;

    fscanf( input, "%d", &size );
    array = (int *) malloc( size*sizeof(int) );

    for( i=0; i<size; i++)
    {
        fscanf( input, "%d", &array[i] );
    }

    quickSortOpt( array, 0, size-1 );

    //Error check to verify the array is sorted
    /*for( i=1; i<size; i++)
    {
        if(array[i-1]>array[i]){
            printf("Not sorted!");
            exit(-1);
        }
    }*/

    free(array);
}

/*
 * Provided code - DO NOT CHANGE THIS METHOD
 */
void quickSortOpt( int* points, int low, int high )
{
    if( high < low+30 )
    {
        insertionSort( points, low, high );
    }
    else
    {
        int pivot = partition( points, low, high );

        quickSortOpt( points, low, pivot-1 );
        quickSortOpt( points, pivot+1, high );
    }
}

/*
 * Provided code - DO NOT CHANGE THIS METHOD
 */
int partition( int* points, int low, int high )
{
    int pivot = rand() % (high - low + 1) + low;
    int pivotValue = points[pivot];
    int i = low+1;
    int j = high;
    int temp;

    points[pivot] = points[low];
    points[low] = pivotValue;

    while( i<j )
    {
        while( i<=high && points[i] <= pivotValue )
        {
            i++;
        }
        while( j>=low && points[j] > pivotValue )
        {
            j--;
        }
        if(i<j)  //swap out of order elements
        {
            temp = points[i];
            points[i] = points[j];
            points[j] = temp;
        }
    }
    if( i<=high && points[i] <= pivotValue )
    {
        i++;
    }

    points[low] = points[i-1];
    points[i-1] = pivotValue;

    return i-1;
}

/*************************************** Functions for finding and printing runtime *********************************************/

/*
Give your asymptotic estimates for the runtimes of the following 3 functions:

mysteryRuntime1:  O(  N )
mysteryRuntime2:  O(  N^2 )
mysteryRuntime3:  O(  N )
*/


/* TO BE COMPLETED BY YOU
 * Fill in the missing parts of the code (see TODOs below)
 */
functionRuntimes timeAlgorithm( char *name, int numTestCases, int numTestCaseSizes, int testCaseSizes[], void (*f)(FILE *) )
{
    /* Call and calculate the runtime of the provided function f */
    clock_t start, end;
    int i, j;
    FILE *testData;

    //create functionRuntimes variable to return
    functionRuntimes fRT;
    //TODO: copy passed data into the fRT variable

    fRT.name = name;
    fRT.numTestCases = numTestCases;
    fRT.numTestCaseSizes = numTestCaseSizes;
    fRT.testCaseSizes = testCaseSizes;

    //TODO: initialize and fill in the runtimes table
    fRT.times = (double **)malloc(numTestCaseSizes * sizeof(double*)) /* instead malloc an array of double*s of size numTestCaseSizes */;
    for( i=0; i<numTestCaseSizes; i++ )
    {
        fRT.times[i] = (double *)malloc(numTestCases * sizeof(double)) /* instead malloc an array of doubles of size numTestCases */;

        for( j=0; j<numTestCases; j++ )
        {
            //Generate test data for the function f
            testData = generateTestInput( 0, testCaseSizes[i], testCaseSizes[i] );

            //Run f on the generated test data
            start = clock();
            f( testData );
            end = clock();
            fclose(testData);

            //Enter the elapsed number of seconds into the times array for fRT
            fRT.times[i][j] = (double)(end - start) / CLOCKS_PER_SEC;
        }
    }

    //TODO: Calculate the average runtimes (call computeAvg here)

    return fRT;
}

/*
 * Provided code - DO NOT CHANGE THIS METHOD
 */
FILE *generateTestInput( int min, int max, int size )
{
    int i;
    FILE *data = fopen( DATA_FILE_NAME, "w" );

    if( data==NULL )
    {
        printf("Failed to create file %s\n", DATA_FILE_NAME);
        exit(-1);
    }

    //add size to start of file
    fprintf( data, "%d ", size );
    //Fill the file with random data
    for( i=0; i<size; i++ )
    {
        fprintf( data, "%d ", rand()%(max-min+1)+min );
    }
    fclose(data);

    data = fopen( DATA_FILE_NAME, "r" );
    if( data==NULL )
    {
        printf("Failed to create file %s\n", DATA_FILE_NAME);
        exit(-1);
    }
    return data;
}

/* TO BE COMPLETED BY YOU
 * Calculate and insert the average runtime for each set of test data into fRT
 */
void computeAvg( functionRuntimes fRT )
{

}

/* TO BE COMPLETED BY YOU
 * Print the information in fRT as a 2d table.  Display 3 digits after the decimal point.  You can assume all of the runtimes are <= 99.999 seconds.
 */
void printRuntimeTable( functionRuntimes fRT )
{
    printf("%s\n", fRT.name);
    printf("Test Size: ");
    int testNum=0;
    int x, i, j;
    for (x = 0; x < fRT.numTestCases; x++)
    {
        
        printf("\tTest #%d ", testNum);
        testNum++;
        if(testNum == fRT.numTestCases){
            printf("\tAverage\n");
        };
    }
    for (i = 0; i < fRT.numTestCaseSizes; i++)
    {
        printf("%d ", fRT.testCaseSizes[i]);
        float sum = 0.0;
        float avg;
        int dataRemaining=0;
        for (j = 0; j < fRT.numTestCases; j++)
        { 
            printf("\t\t%2.3f ", fRT.times[i][j]);
            sum += fRT.times[i][j];
            dataRemaining++;
            if(fRT.numTestCases <= dataRemaining){
                printf("\t\t%2.3f\n", (sum/fRT.numTestCases));
            }
        }
    }
}

/* TO BE COMPLETED BY YOU
 * Free all of the dynamically allocated memory in fRT
 */
void freeFunctionRuntimes( functionRuntimes fRT )
{
    
}
