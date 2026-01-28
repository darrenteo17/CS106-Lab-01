#include <stdio.h>
#include <limits.h>

/*
 * isTmax - returns 1 if x is the maximum, two's complement number,
 *     and 0 otherwise 
 *   Legal ops: ! ~ & ^ | + << >>
 *   Max ops: 10
 *   Rating: 1
 */
int isTmax(int x)
{
    //return !(~x ^ (1 << 31));
    return !(x ^ ~(1<<31));

}

int test_isTmax(int x)
{
    return x == 0x7FFFFFFF;
    // 0111 1111 1111 1111 1111 1111 1111 1111
    // !(x ^ !(1 << 28));
}

int main(void)
{
    int x = INT_MAX;
    printf("expected: %x\n", isTmax(x));
    printf("actual  : %x\n", test_isTmax(x));
}
