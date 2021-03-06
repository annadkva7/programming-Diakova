# Лабораторна робота №15. Динамічні масиви.

## 1 Вимоги

-програма має мати документацію, що оформлена за допомогою утиліти doxygen;
-звіт повинен бути оформлений згідно “Вимогам до структурної побудови звіту”;
-продемонструвати відсутність витоків пам’яті за допомогою утиліти valgrind;
-доступ до елементів масиву здійснювати через розіменування покажчиків, а не через
-оператор індексування ([ ]);
-продемонструвати роботу розроблених методів за допомогою модульних тестів;
-у звіті навести ступень покриття коду модульними тестами. 50% - є мінімально допустимим
відсотком покриття коду тестами.

### 1.1 Розробник

* Дʼякова Анна Юріївна;
* студентка групи КН-921г;
* 03-трав-2022.

### 1.2 Загальне завдання

На базі попередньо розробленого функціоналу по роботі з прикладною областю сформувати
динамічний масив елементів розробленої структури. Реалізувати наступні функції роботи зі
списком:
• вивід вмісту списку на екран;
• реалізувати функцію №1 з категорії “Методи для роботи з колекцією” (див. завдання з РЗ);
• додавання об’єкта у кінець списку;
• видалення об’єкта зі списку за індексом.
• сортування вмісту списку за одним з критеріїв
Зверніть увагу. Проект має складатися з 6 файлів (main.c, test.c, list.h, list.c, entity.c, entity.h).

### 1.3 Індивідуальне завдання

Згідно варіанту, обрати базовий клас та функції №1 з категорії "Методи для роботи з колекцією".

## 2 Опис програми

### 2.1 Функціональне призначення

Програма призначена для роботи і опрацювання базового класу у динамічній структурі.

### 2.2 Опис логічної структури

void print_on_screen(struct worker *array, int amount_of_workers)

Виводить на екран інформацію про структуру.

void free_struct(struct worker *array, int amount_of_workers, int index, int temp)

Видаляє елемент структури варіативно: елемент, що буде видалений, обирається користувачем.

Функція void does_not_have_insurance(struct worker *array, int amount_of_workers)

За допомогою порівняння, кожної ітерації циклу порівнює елементи, що містить інформацію про страхування та компанію. Якщо умова виконується - виводить ім'я й фамілію цього робітника
на екран.

int compare_seniority(const void *a, const void *b)

Допоміжна функція для бібліотечної функції qsort.

void add_worker(struct worker *array, struct worker *new_array, int new_amount_of_workers)

Додає новий елемент динамічної структури.

#### Основна функція

```c
		int main() 
```

*Призначення*: головна функція.

#### Структура проекту

```
.
├── dist
│   ├── main.bin
│   └── test.bin
├── doc
│   └── lab15.md
├── Doxyfile
├── Makefile
├── README.md
├── src
│   ├── entity.c
│   ├── entity.h
│   ├── list.c
│   ├── list.h
│   └── main.c
└── test
    └── test.c


```

## Висновки

    Наводжу ступень покриття коду модульними тестами:
LLVM_PROFILE_FILE="dist/test.profraw" ./dist/test.bin
Running suite(s): Programing
100%: Checks: 1, Failures: 0, Errors: 0
test/test.c:67:P:lab15:test_free_struct:0: Passed
llvm-profdata merge -sparse dist/test.profraw -o dist/test.profdata
llvm-cov report dist/test.bin -instr-profile=dist/test.profdata src/*.c
Filename                      Regions    Missed Regions     Cover   Functions  Missed Functions  Executed       Lines      Missed Lines     Cover
-------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------
entity.c                           16                16     0.00%           3                 3     0.00%          53                53     0.00%
list.c                             12                 5    58.33%           2                 1    50.00%          33                10    69.70%
-------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------
TOTAL                              28                21    25.00%           5                 4    20.00%          86                63    26.74%
llvm-cov show dist/test.bin -instr-profile=dist/test.profdata src/*.c --format html > dist/coverage.html

Висновок: під час виконання цієї лабораторної роботи я закріпила навички реалізації структурованих типів даних, а також покращила свої навички володіння динамічними масивами і написання програм мовою С.