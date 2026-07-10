long callee(long a, long b, long c, long d, long e, long f, long g, long h) {
    long x = 5;
    long y = 6;
    long z = 7;
    // long long x1 = 5;
    // long long y1 = 6;
    // long long z1 = 7;
    // long long x2 = 5;
    // long long y2 = 6;
    // long long z2 = 7;
    // long long x3 = 5;
    // long long y3 = 6;
    // long long z3 = 7;
    // long long x4 = 5;
    // long long y4 = 6;
    // long long z4 = 7;
    return x+y+z;
}

void caller()
{
    long x = callee(1, 2, 3, 4, 5, 6, 7, 8);
    x = x+x;
}
