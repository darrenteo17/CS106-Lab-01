#include <stdio.h>

/* 
 * upperBits - pads n upper bits with 1's
 *  You may assume 0 <= n <= 32
 *  Example: upperBits(4) = 0xF0000000
 *  Legal ops: ! ~ & ^ | + << >>
 *  Max ops: 10
 *  Rating: 1
 */
int upperBits(int n)
{
    // 1000 0000 0000 0000 0000
    // 1100 0000 0000 0000 0000 0 
    return (!!n) | ((1 << 31) >> (n+(-1)) );
    // when n = 0;
    //          0000 0000 0000 0000 0000
    //return ~(~0 >> n);
}

int test_upperBits(int x)
{
    int result = 0;
    int i;
    for (i = 0; i < x; i++)
        result |= (1 << (31 - i));
    return result;
}

int main(void)
{
    int x = 32;
    printf("expected: %x\n", upperBits(x));
    printf("actual  : %x\n", test_upperBits(x));
}
