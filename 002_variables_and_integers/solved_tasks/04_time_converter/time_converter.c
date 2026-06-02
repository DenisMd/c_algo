#include <stdio.h>

// Описание упражнения в README.md
int main()
{
    const int SECONDS_IN_MINUTE = 60;
    const int SECONDS_IN_HOUR = 60 * SECONDS_IN_MINUTE;


    int total_seconds;
    int hours,minutes,remain_seconds;

    scanf("%d", &total_seconds);
    hours = total_seconds / SECONDS_IN_HOUR;
    minutes = (total_seconds % SECONDS_IN_HOUR) / SECONDS_IN_MINUTE;
    remain_seconds = total_seconds % SECONDS_IN_MINUTE;

    printf("H: %d, Min: %d, Secs: %d\n", hours, minutes, remain_seconds);

    return 0;
}