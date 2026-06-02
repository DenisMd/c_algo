#include <stdio.h>

// Описание упражнения в README.md
int main()
{
    const int BYTES_IN_KB = 1024;
    const int BYTES_IN_MB = 1024 * BYTES_IN_KB;
    const int BYTES_IN_GB = 1024 * BYTES_IN_MB;


    long long total_bytes;
    int gigabytes,megabytes,kilobytes,remain_bytes;

    scanf("%lld", &total_bytes);
    gigabytes = total_bytes / BYTES_IN_GB;
    megabytes = (total_bytes % BYTES_IN_GB) / BYTES_IN_MB;
    kilobytes = ((total_bytes % BYTES_IN_GB) % BYTES_IN_MB) / BYTES_IN_KB;
    remain_bytes = total_bytes % BYTES_IN_KB;

    printf("%d GB, %d MB, %d KB, %d bytes\n", gigabytes, megabytes, kilobytes, remain_bytes);

    return 0;
}