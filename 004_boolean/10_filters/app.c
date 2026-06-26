#include <stdio.h>
#include <stdbool.h>

int main()
{
    int price;
    int rooms;
    int floor;
    int max_floor;
    int metro_m;

    scanf("%d %d %d %d %d", &price, &rooms, &floor, &max_floor, &metro_m);

    // --- простые условия ---
    bool is_studio = rooms == 1;
    bool is_not_studio = !is_studio;              // отрицание: rooms != 1
    bool is_two_room = rooms == 2;
    bool is_three_plus = rooms >= 3;

    // --- интервалы по цене (руб/мес) ---
    bool is_budget = price >= 40000 && price <= 70000;       // [40k; 70k]
    bool is_mid_price = price > 70000 && price < 120000;      // (70k; 120k)
    bool is_expensive = price >= 120000;                      // [120k; +inf)
    bool is_not_expensive = !is_expensive;                    // price < 120000

    // --- этаж ---
    bool is_first_floor = floor == 1;
    bool is_last_floor = floor == max_floor;
    bool is_not_ground = floor > 1;                           // (1; max_floor]
    bool is_not_top = floor < max_floor;                      // [1; max_floor)
    bool is_middle_floor = floor > 1 && floor < max_floor;    // (1; max_floor)

    // --- метро ---
    bool is_near_metro = metro_m <= 500;                      // [0; 500]
    bool is_far_from_metro = metro_m > 1500;                  // (1500; +inf)
    bool is_walk_distance = metro_m > 500 && metro_m <= 1000; // (500; 1000]

    // --- составные фильтры (поисковые запросы) ---
    bool is_student_flat = is_studio && is_budget && is_near_metro;
    bool is_family_flat = is_three_plus && is_not_ground && is_not_top && is_not_expensive;
    bool is_penthouse_like = is_last_floor && rooms >= 2 && !is_budget;

    // отрицание составного: «не подходит для семьи»
    bool is_unfit_for_family = !is_family_flat;

    bool is_good_deal = is_mid_price && is_two_room && is_middle_floor && is_walk_distance;
    bool is_too_far_but_cheap = is_budget && is_far_from_metro;

    printf("studio:              %d\n", is_studio);
    printf("budget:              %d\n", is_budget);
    printf("mid price:           %d\n", is_mid_price);
    printf("near metro:          %d\n", is_near_metro);
    printf("middle floor:        %d\n", is_middle_floor);
    printf("student flat:        %d\n", is_student_flat);
    printf("family flat:         %d\n", is_family_flat);
    printf("unfit for family:    %d\n", is_unfit_for_family);
    printf("good deal:           %d\n", is_good_deal);
    printf("far but cheap:       %d\n", is_too_far_but_cheap);

    return 0;
}
