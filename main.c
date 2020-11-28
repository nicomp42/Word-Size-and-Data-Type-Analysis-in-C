#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include <time.h>
#include <sys/time.h>
#include <stdint.h>
#include <stdbool.h>
#include <limits.h>
#include <unistd.h>
#include <math.h>

//// Global tools for bit-boolean operations.

typedef uint64_t pNo;       //.. When used as a bit index.
typedef uint64_t boolWord;  //.. When used as a bit-map.

//.. Bits available in a boolWord.
#define bitsBoolWord ( CHAR_BIT * sizeof (boolWord) )

//// Sieve of booleans representing possible primes.

typedef struct {

    pNo     Low;    //.. Requested range of values.
    pNo     High;

    boolWord *Sieve;    //.. Malloc for bit-array.
    size_t sz_Sieve;    //.. Sizeof for Malloc.
    pNo     maxSieve;   //.. Highest integer mapped.

    boolWord *Slice;    //.. Malloc for bit-array.
    size_t sz_Slice;    //.. Sizeof for Malloc.
    pNo     bitSlice;   //.. Capacity of Slice in integers.
    pNo     minSlice;   //.. Base integer mapped.
    pNo     maxSlice;   //.. Highest integer mapped.
} Control_t;

//// Check data type characteristics.

LOCAL void DataTypes (void)

{
Control_t myPrime;
char *fmt = "sizeof %-24s is %2zu\n";

    fprintf (stderr, fmt, "size_t", sizeof (size_t));
    fprintf (stderr, fmt, "myPrime", sizeof (myPrime));
    fprintf (stderr, fmt, "*myPrime", sizeof (& myPrime));
    fprintf (stderr, fmt, "bool", sizeof (bool));
    fprintf (stderr, fmt, "int", sizeof (int));
    fprintf (stderr, fmt, "long int", sizeof (long int));
    fprintf (stderr, fmt, "long long int", sizeof (long long int));
    fprintf (stderr, fmt, "uint32_t", sizeof (uint32_t));
    fprintf (stderr, fmt, "uint64_t", sizeof (uint64_t));
    fprintf (stderr, fmt, "long double", sizeof (long double));
}

int main (int argc, char *argv[]) {
    DataTypes ();
}
