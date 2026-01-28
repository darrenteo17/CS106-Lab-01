#include <stdio.h>

/* 
 * bitMatch - Create mask indicating which bits in x match those in y
 *            using only ~ and & 
 *   Example: bitMatch(0x7, 0xE) = 0x6
 *            0111
 *            1110
 *            0110
 *   Legal ops: ~ & |
 *   Max ops: 14
 *   Rating: 1
 */
int bitMatch(int x, int y)
{
    /*
        0001 0001
        1001 0001
        ---------
        0001 0001 (match on 1) using &
        0110 1110 (match on 0) how?

        ~x: 1110 1110
        ~y: 0110 1110
        -------------
        &:  0110 1110
    */
    return (x & y) | (~x & ~y);
    // same as ~(x ^ y);
    //         ~((x|y) & (~(x&y)));
}

int test_bitMatch(int x, int y)
{
    int i;
    int result = 0;
    for (i = 0; i < 32; i++) {
        int mask = 1 << i;
        int bit = (x & mask) == (y & mask);
        result |= bit << i;
    }
    return result;
}

int main(void)
{
    int x = 0;
    int y = 5;
    printf("expected: %x\n", bitMatch(x, y));
    printf("actual  : %x\n", test_bitMatch(x, y));
}
