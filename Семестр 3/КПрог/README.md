Задания по асемблеру. Первые 3 задания - motorola MC68HC11. Дальше задания написаны на Emu8086 (lab7 на GUI Turbo Assembler).

lab1:
Вариант 7
task1
Произвести обмен содержимого младшего байта регистра X с регистром А.
task2
Напишите программу, позволяющую вычислить адрес элемента, находящегося в двухмерном массиве размерностью 3 x 3. Массив располагается по адресу $8100-$8109. Индекс задается регистрами А и В, где А – номер строки, B – номер столбца массива.

lab2:
Вариант 7
Написать программу, копирующую содержимое регистров A и B в регистр X таким образом, чтобы старшая тетрада регистра А и старшая тетрада регистра В составляли старший байт регистра X, а младшие тетрады – младший.

lab3:
Вариант 7
Произвести сортировку по убыванию чисел, расположенных в ячейках $8200 ... $82ff.

lab4:
Вариант 4
Отсортировать слова в строке по длине слова.

lab5:
Вариант 1
Перевести число из одной системы счисления в другую (системы счисле-ния задаются до ввода-вывода числа в диапазоне [2..16]).

lab6:
Вариант 21
Удалить в файле строки все информативные (не пустые) строки.

lab7:
Вариант 1
Написать программу, запускающую другую программу N раз (N – число в диапазоне [1, 255]). Имя запускаемой программы задается константой.

lab8:
Вариант 1
Расширенный клавиатурный макро-менеджер.
На стороне Assembler: 
Необходимо создать макросы для комбинаций клавиш, выполняя ассемблерные функции в ответ на активацию макроса.
Макросы:
F1 - вывод всех макросов и их описание.
При нажатии комбинации s + d вызывается ассемблерная функция, которая активирует PC Speaker для издания звукового сигнала определенной частоты и длительности.
При нажатии другой комбинации клавиш, например s + c, вызывается ассемблерная функция, которая изменяет цвет фона и/или текста в консоли.
На стороне C++:
В главной функции создайте цикл, который будет проверять состояние клавиатуры с использованием функции, написанной на ассемблере. При обнаружении комбинации клавиш вызывайте соответствующую функцию, написанную на ассемблере.
Логирование: Записывайте все действия пользователя и реакции программы на них в файл лога. Это может быть полезно для отладки или просто для истории использования.

