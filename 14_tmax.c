#include <stdio.h>

/* 
 * TMax - return maximum two's complement integer 
 *   Legal ops: ! ~ & ^ | + << >>
 *   Max ops: 4
 *   Rating: 1
 */
int tmax(void)
{
    return !(1 << 28);
}

int test_tmax(void)
{
    return 0x7FFFFFFF;
    // 0111 1111 1111 1111 1111 1111
    // 1000 0000 0000 0000 0000 0000
}

int main(void)
{
    printf("expected: %x\n", tmax());
    printf("actual  : %x\n", test_tmax());
}
