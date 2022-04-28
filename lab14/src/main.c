/**
 * @mainpage
 * # Загальне завдання
 * З розділу "Індивідуальні завдання комплексної роботи" взяти прикладну галузь
 * номеру варіанту за попередньо-визначеною формулою. Створити структуру, що
 * відображає "базовий клас".
 *
 * Розробити функції, які 1) читають дані з файлу, 2) записують дані у файл, 3)
 * виводить масив елементів на екран, 4) №1 з категорії "Методи для роботи з
 * колекцією", 5) сортування масиву за заданим критерієм. # Додаткове завдання
 * Виконати запис та читання масиву структур у двох форматах: текстовому та
 * бінарному.
 *
 * @author Diakova A.
 * @date 25-apr-2022
 * @version 1.0
 */

/**
 * @file main.c
 * @brief Файл з демонстрацією роботи функцій read_from_file, write_to_file,
 * convertion, print_on_screen, does_not_have_insurance, sorting_by_seniority;
 *
 * @author Diakova A.
 * @date 25-apr-2022
 * @version 1.0
 */

#include "lib.h"

int main(void) {

  FILE *input_file = fopen("/home/turtlee_/programming-Diakova/lab14/assets/input.txt", "r");
  FILE *output_file = fopen("/home/turtlee_/programming-Diakova/lab14/assets/output.txt", "w");
  FILE *binary_file = fopen("/home/turtlee_/programming-Diakova/lab14/assets/output.bin", "w");
  FILE *binary_ = fopen("/home/turtlee_/programming-Diakova/lab14/assets/output.bin", "r");

  int buffer = 32;
  int amount_of_workers = 0;
  printf("Please, input the amount of workers for processing: ");
  scanf("%d", &amount_of_workers);

  struct worker *array = (struct worker *)malloc(amount_of_workers * sizeof(struct worker));
  struct worker *bin = (struct worker *)malloc(1 * sizeof(struct worker));
  for( int i = 0; i < amount_of_workers; i++) {
    (array + i)->company = (char*)malloc(16 * sizeof(char));
    (array + i)->details.first_name = (char*)malloc(16 * sizeof(char));
    (array + i)->details.last_name = (char*)malloc(16 * sizeof(char));
    (array + i)->details.email = (char*)malloc(16 * sizeof(char));
    (array + i)->characteristics = (char*)malloc(16 * sizeof(char));
  }

  read_from_file(input_file, array, amount_of_workers);
  write_to_file(output_file, array, amount_of_workers);

  qsort(&(array->experience), amount_of_workers, sizeof(struct worker), compare_seniority);
  for( int i = 0; i < amount_of_workers; i++) {
    printf("%s %s: %d\n", (array + i)->details.first_name,(array + i)->details.last_name, (array + i)->experience);
  }

  does_not_have_insurance(array, amount_of_workers);

  write_to_bin(binary_file, array, amount_of_workers);
  read_from_bin(binary_,bin);


  free(array);

  return 0;

}