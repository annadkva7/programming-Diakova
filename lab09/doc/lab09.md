# Лабораторна робота № 9. Модульне тестування.

## 1 Вимоги

### 1.1 Розробник

* Дʼякова Анна Юріївна;
* студентка групи КІТ-121г;
* 22-лют-2022.

### 1.2 Загальне завдання

1) Переробити проект на багатофайлову структуру.
2) Для попередньо розробленої функції додати методи - модульні тести, що демонструють коректність роботи розробленого функціоналу.

### 1.3 Індивідуальне завдання

Переробити проект на багатофайлову структуру, додати модульні тести, що демонструють коректність роботи розробленого функціоналу.

## 2 Опис програми

### 2.1 Функціональне призначення

Програма призначена для вирішення індивідуального завдання та розробки модульного тесту.

### 2.2 Опис логічної структури

Функція get_words_amount.


Рахує кількість слів у заданому тексті.

Має лічильник word_counter. Вважає за розділювач символ пробілу. З кожною ітерацією на новий символ строки, перевіряє, чи є цей символ чимось, окрім пробілу. Якщо is_word == 1 && (line[i] != ' ' && line[i] != '\0') && (line[i + 1] == ' ' || line[i + 1] == '\0'), то лічильник залишається яким як був, якщо (line[i] == ' ' && line[i + 1] != ' ') || line[i] != ' ', лічильник збільшується на одне слово. 

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
│   └── lab09.md
├── Doxyfile
├── Makefile
├── README.md
├── src
│   ├── lib.c
│   ├── lib.h
│   └── main.c
└── test
    └── test.c
```

## Висновки

Під час виконання цієї лабораторної роботи я навчилась ефективно реалізувати перевірку роботи функцій через написання модульних тестів, а також покращила свої навички написання програм мовою С.

