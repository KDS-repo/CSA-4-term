# Компиляция и запуск программы на C

В этой лабораторной работе мы будем использовать программу командной строки gcc для компиляции программ на C. Самый простой способ запустить gcc следующий:

```
$ gcc program.c
```

Это компилирует program.c в исполняемый файл с именем a.out. Этот файл можно запустить с помощью следующей команды:

```
$ ./a.out
```

Исполняемый файл - a.out, почему добавляется ./? Когда вы хотите запустить исполняемый файл, вам нужно добавить путь к файлу, чтобы отличить вашу команду от такой команды, как python3, например. Точка указывает на текущую директорию. Таким образом, мы говорим, что запускаем a.out из текущей директории. Между прочим, двойные точки (..) исплользуются для именования родительской директории.

gcc имеет различные параметры командной строки, которые вам рекомендуется изучить. Особое внимание уделите параметрам `-Wall`, `-Werr`, `-O0`, `-O1`, `-O2`, `-O3` Однако в этой лабораторной работе мы будем использовать только `-o`, который используется для указания имени исполняемого файла, создаваемого gcc. Если вы не хотите, чтобы все ваши исполняемые файлы назывались a.out, вы можете использовать следующие команды, чтобы скомпилировать program.c в программу с именем program:

```
$ gcc -o program program.c
$ ./program
```

# Необязательно: локальная установка компилятора C
## Mac

Установите инструмент командной строки Xcode, запустив
```
$ xcode-select --install
```

Затем вы можете проверить, успешно ли установлен gcc, запустив
```
$ gcc --version
```
## Ubuntu / Debian

Установите пакет, необходимый для сборки, запустив
```
$ sudo apt install build-essential cgdb valgrind
```

При этом будет установлено множество пакетов, таких как gcc и make, а также инструменты отладки cgdb и valgrind. Если вам интересно, вот подробное описание пакета, необходимого для сборки, начиная с Ubuntu 18.04.

## Windows

Для пользователей Windows рекомендуется использовать среду `cygwin`

# Задание 1. Условные конструкции

В этом задании мы увидим примеры условных конструкций. Поведение кода будет определятся константам времени компиляции `V0`, `V1`, `V2`, `V3`, определеяемыми как `constexpr int`.

В данном задании вам предстоит работать с кодом в файле `speciality.cpp`. Обратите внимание на четыре различных примера условных конструкций C.

Сначала скомпилируйте и запустите программу, чтобы увидеть, что она делает. Поиграйте с постоянными значениями четырех констант: от `V0` до `V3`. Посмотрите, как изменение каждого из них меняет вывод программы.

### Задача

Задайте набор констант таким образом, чтобы получить
```
Специальности ФКСИС
===================
Лучшая специальность:
Только Информатика и технологии программирования
БАТЭ чемпион!
```
Добавьте обновленный файл в свой репозиторий. На самом деле существует несколько различных комбинаций значений констант, которые могут дать такой результат. В этом упражнении перед вами стоит задача: подумать, какое минимальное количество различных значений может иметь от V0 до V3, чтобы они по-прежнему давали такой точный результат. Например, теоретический максимум - четыре, когда все они отличаются друг от друга.

Не знаете, как запустить программу? Вернитесь к введению. Скомпилируйте программу в исполняемый файл под названием `speciality`; Вы можете использовать для этого флаг -o.

# Задание 2. Дебажим!

Отладчик, как следует из названия, - это программа, которая разработана специально для того, чтобы помочь отладить программу, найти логические ошибки и ошибки в вашем коде. У разных отладчиков разные функции, но обычно все отладчики могут выполнять следующие действия:

* Установить точку останова в своей программе. Точка останова - это определенная строка в вашем коде, где вы хотите остановить выполнение программы, чтобы вы могли посмотреть, что происходит поблизости.
* Построчно исполнить код программы. Код всегда выполняется последовательно, строка за строкой, но это происходит слишком быстро, чтобы мы могли понять, какие строки вызывают ошибки. Возможность поэтапного выполнения кода позволяет вам точно определить, что именно вызывает ошибку в вашей программе.

Для этого упражнения вам будет полезна справочная карта `GDB`, которая приложена отдельным файлом. `GDB` означает `GNU De-Bugger`. Скомпилируйте `hello.cpp` с флагом `-g`:

```
$ gcc -g -o hello hello.cpp
```
Это флаг указывает, что надо сохранить информацию в исполняемой программе, чтобы gdb мог ее понять. Теперь запустим наш отладчик `(c)gdb`:

```
$ gdb hello
```

Обратите внимание на то, что делает эта команда. Вы запускаете программу `gdb` передав путь к исполняемому файлу `hello` в качестве аргумента. Не пытайтесь запустить `gdb` с исходным кодом `hello.c`. 

**Примечание.** `gdb` может не устанавливаться на компьютерах с macOS. Вы можете использовать lldb, еще один отличный отладчик. Команды немного отличаются, но есть руководства, которые помогут вам начать работу.

### Задача

Пройдите через всю программу, выполнив следующие действия:

1. Установка точки останова на функции main
2. Исполните команду `run`
3. Исполните команду `step`

Введите `help` в `gdb`, чтобы узнать команды для выполнения этих действий, или воспользуйтесь справкой.

## Примечание: cgdb против gdb

В этом упражнении мы используем `gdb` для отладки наших программ, но также стоит упомянуть `cgdb`. `cgdb` идентичен `cgdb`, за исключением того, что он предоставляет некоторые дополнительные приятные функции, которые делают его более удобным в использовании на практике.

В `cgdb` вы можете нажать `ESC`, чтобы перейти в окно кода (вверху), `i` чтобы вернуться в окно команд (внизу). В самом низу вы найдете окно команд, где вводятся команды `GDB`.

### Пункт действия

Изучение этих команд окажется полезным для остальной части этой лабораторной работы и для вашей карьеры программиста на языке C++ в целом. В текстовом файле с именем gdb.txt ответьте на следующие вопросы.

1. Когда вы находитесь в сеансе gdb, как вы устанавливаете аргументы, которые будут передаваться программе при ее запуске?
2. Как создать точку останова?
2. Как выполнить следующую строку кода C в программе после остановки в точке останова?
3. Если следующая строка кода является вызовом функции, вы выполните весь вызов функции сразу, если воспользуетесь своим ответом на # 3. (Если нет, рассмотрите другую команду для # 3!) Как вы сообщите GDB, что хотите вместо этого отладить код внутри функции (т.е. перейти внутрь функции)?
4. Как продолжить выполнение программы после остановки на точке останова?
5. Как вы можете распечатать значение переменной (или даже выражение типа 1 + 2) в gdb?
6. Как настроить gdb так, чтобы он отображал значение переменной после каждого шага?
7. Как вы показываете список всех переменных и их значений в текущей функции?
8. Как выйти из GDB?

# Задание 3. Интерактивная отладка

Давайте посмотрим, что произойдет, если ваша программа требует ввода данных пользователем, и вы попытаетесь запустить её в `GDB`. Во-первых, соберите и запустите программу, определенную в `interactive_hello.cpp`, чтобы поговорить с слишком дружелюбной программой.
```
$ gcc -g -o int_hello interactive_hello.c
$ ./int_hello
```
Теперь попробуем отладить его (хотя на самом деле ошибок нет).
```
$ gdb int_hello
```
Что происходит, когда вы пытаетесь запустить программу до конца исполнения? Цель этого задания - избавить вас от боязни запуска отладчика, даже если вашей программе требуется ввод данных пользователем. Оказывается, вы можете отправлять текст на стандартный ввод `stdin`, файловый поток, читаемый через объект `std::cin`, в этой глупой программе, с некоторыми специальными символами прямо из командной строки.

*Подсказка 1.* Если вы создаете текстовый файл, содержащий введенные вами данные, вы на правильном пути! 
*Подсказка 2.* Помните, что вы также можете запускать программы с аргументами командной строки (включая символы перенаправления) из `GDB`!

# Задание 4. Valgrind

Даже с отладчиком мы не сможем отловить все ошибки. Некоторые ошибки мы называем ошибки Борбагами, что означает, что они надежно проявляются при четко определенном, но, возможно, неизвестном наборе условий. Другие ошибки мы называем Гейзенбагами, и вместо того, чтобы быть четко определенными, они исчезают или изменяют свое поведение, когда их пытаются изучить. Мы можем обнаружить первый тип с помощью отладчиков, но второй тип может ускользнуть от нас, потому что они (по крайней мере, в `C/С++`) часто возникают из-за неправильного управления памятью.

Помните, что в отличие от других языков программирования, `C` требует, чтобы вы (программист) вручную управляли своей памятью.

Чтобы помочь отловить этих Гейзенбагов, мы будем использовать инструмент под названием `Valgrind`. `Valgrind` - это программа, которая имитирует ваш процессор и отслеживает обращения к вашей памяти. Это замедляет выполняемый вами процесс (поэтому мы, например, не всегда запускаем все исполняемые файлы внутри `Valgrind`), но также может выявить ошибки, которые могут отображать только видимое неправильное поведение при уникальном стечении обстоятельств.

*Примечание.* `Valgrind` доступен для установки в большинстве Unix-подобных дистрибутивов, а также в macOS, однако возможны проблемы совместимости между `Valgrind` и последними версиями macOS. Если у вас не получается запустисть `Valgrind` из `homebrew`, придется собрать вручную на своей машине следую инструкциям.

В этом упражнении мы продемонстрируем два разных примера выходных данных `Valgrind` и рассмотрим, как каждый из них может быть полезен.

Сначала создайте два новых исполняемых файла, `segfault_ex` из `segfault_ex.cpp` и `no_segfault_ex` из `no_segfault_ex.cpp` (используйте флаг `-o`). На этом этапе вы сможете использовать `gcc` для успешной сборки этих исполняемых файлов.

Теперь попробуем запустить исполняемые файлы. Какие результаты вы наблюдаете?

Начнем с `segfault_ex`. Вы должны были наблюдать ошибку сегментации (`segfault`), которая возникает, когда программа вылетает из-за попытки получить доступ к памяти, которая ей недоступна (подробнее об этом вы узнаете позже в курсе; на самом деле это артефакт из раннего проектирования памяти. Сегодня мы работаем с «выгружаемой памятью» вместо «сегментированной памяти», но сообщение об ошибке осталось).

Этот файл исходный код очень мал, поэтому вы должны иметь возможность открыть файл и понять, что вызывает `segfault`. Сделайте это сейчас, но не меняйте файл. Почему возникает `segfault`?

Теперь давайте разберемся, что делать, если у нас очень большой файл и нужно найти `segfault`. Вот где нам поможет `Valgrind`. Для запуска программы в `Valgrind` используйте команду:

```
$ valgrind ./segfault_ex
```
Это должно привести к тому, что `Valgrind` выведет информацию о том, где произошел незаконный доступ. Сравните эти результаты с вашими предположениями. Как `Valgrind` может помочь вам устранить ошибку сегментации в будущем?

Теперь попробуйте запустить `Valgrind` на `no_segfault_ex`. Программа не должна была дать сбой, но проблема с файлом все еще существует. `Valgrind` может помочь нам найти (на первый взгляд невидимую) проблему.

К сожалению, здесь вы увидите, что `Valgrind`, похоже, не может сказать вам, где именно возникает проблема. Используйте сообщение, предоставленное `Valgrind`, чтобы определить, какая переменная вызывает некорректное поведение, а затем попытайтесь сделать вывод, что должно было произойти (Подсказка: что такое неинициализированное значение?).

Надеюсь, пройдя этот пример, вы сможете понять и ответить на следующие вопросы:

1. Почему важен `Valgrind` и чем он полезен?
2. Как запустить программу в `Valgrind`?
3. Как вы интерпретируете сообщения об ошибках?
4. Почему неинициализированные переменные могут приводить к появлению Гейзенбагов?

`Valgrind` чрезвычайно важный инструмент, который вам понадобится, как только вы начнете писать на C++. Будьте готовы ответить на следующие вопросы:

1. Почему не произошел segfault программы no_segfault_ex?
2. Почему no_segfault_ex выдает несогласованные выходные данные?
3. Почему указан неправильный размер? Как можно было исправить код используя sizeof?

# Задание 5. Указатели и структуры.

Одна из задач, которая поможет вам на собеседовании. Сам решал такую задачу на собеседовании в Яндекс)). В `ll_cycle.cpp` завершите функцию `ll_has_cycle()`, чтобы реализовать следующий алгоритм проверки наличия цикла в односвязном списке.

1. Начните с двух указателей в начале списка. Первого назовем черепахой, а вторую зайцем.
2. Продвинуть зайца на два узла. Если это невозможно из-за нулевого указателя, значит, мы нашли конец списка, поэтому список ациклический.
3. Продвинуть черепаху на один узел. (Проверка нулевого указателя не требуется. Почему?)
4. Если черепаха и заяц указывают на один и тот же узел, список циклический. В противном случае вернитесь к шагу 2.

Если вы хотите увидеть определение структуры узла, откройте файл заголовка `ll_cycle.h`.

### Задача

Реализуйте `ll_has_cycle()`. Как только вы это сделаете, вы можете выполнить следующие команды, чтобы запустить тесты для вашего кода. Если вы вносите какие-либо изменения, обязательно снова выполните ВСЕ следующие команды по порядку.

```
$ gcc -g -o test_ll_cycle test_ll_cycle.cpp ll_cycle.cpp
$ ./test_ll_cycle
```

*Подсказка.* Эту функцию можно реализовать двумя способами. Они различаются тем, как кодируется критерий остановки. Если вы сделаете это одним способом, вначале вам придется учитывать особый случай. Если вы сделаете это по-другому, у вас будет несколько дополнительных проверок NULL, и это нормально. Предыдущие два предложения призваны убедить вас не беспокоиться о чистоте. Если они вам не помогают, просто игнорируйте их. Цель этого упражнения - убедиться, что вы знаете, как использовать указатели. 