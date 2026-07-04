#include <stdio.h>
#include <stdbool.h>

int main(void)
{
  int hero_hp = 100;
  int hero_damage = 25;
  int enemy_hp = 80;
  int enemy_damage = 15;
  int choice;
  bool is_end_game = false;

  printf("=== Simple battle (event loop) ===\n");

  while (1) {
    printf("\n1 - show status\n");
    printf("2 - attack enemy\n");
    printf("3 - drink potion\n");
    printf("0 - exit\n");
    printf("Choice: ");

    if (scanf("%d", &choice) != 1) {
      fprintf(stderr, "Invalid input\n");
      return 1;
    }

    switch (choice) {
      case 1:
        printf("\n--- Status ---\n");
        printf("Hero:  HP %d, damage %d\n", hero_hp, hero_damage);
        printf("Enemy: HP %d, damage %d\n", enemy_hp, enemy_damage);
        break;
      case 2:
        enemy_hp -= hero_damage;
        if (enemy_hp < 0) {
          enemy_hp = 0;
        }
        printf("Hero deals %d damage. Enemy has %d HP left\n", hero_damage,
               enemy_hp);
        if (enemy_hp > 0 && hero_hp > 0) {
          hero_hp -= enemy_damage;
          if (hero_hp < 0) {
            hero_hp = 0;
          }
          printf("Enemy strikes back for %d damage. Hero has %d HP left\n",
                 enemy_damage, hero_hp);
        }
        break;
      case 3:
        hero_hp += 40;
        if (hero_hp > 100) {
          hero_hp = 100;
        }
        printf("Hero drank a potion (+40 HP). Now at %d HP\n", hero_hp);
        break;
      case 0:
        printf("Exiting game\n");
        is_end_game = true;
        break;
      default:
        printf("Unknown command\n");
        break;
    }

    if (hero_hp == 0) {
      printf("\nHero died. Game over.\n");
      break;
    } else if (enemy_hp == 0) {
      printf("\nEnemy defeated. Victory!\n");
      break;
    } else if (is_end_game) {
      printf("End game\n");
      break;
    }
  }

  return 0;
}
