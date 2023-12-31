# Algorithms
Репозиторий содержит реализации различных алгоритмов

## Aho-Corasick

Реализация решения двух задач:

1. Поиск набора образцов.

*Вход*: Первая строка содержит текст. Вторая – число n, каждая следующая из n строк содержит шаблон. Все строки содержат символы из алфавита {A, C, G, T, N}.

*Выход*: Для каждого шаблона 2 числа – позиция в тексте (начиная с 1) и номер образца.
 
2. Используя реализацию точного множественного поиска, решите задачу точного поиска для одного образца с джокером.

*Вход*: Первая строка содержит текст. Вторая – шаблон. Третья – символ джокера.

*Выход*: Строки с номерами позиций вхождений шаблона.

## Backtracking

Решение задачи методом поиска с возвратом. Формулировка задачи: У Вовы много квадратных обрезков доски. Их стороны (размер) изменяются от 1 до N - 1, и у него есть неограниченное число обрезков любого размера. Но ему очень хочется получить большую столешницу - квадрат размера N. Он может получить ее, собрав из уже имеющихся обрезков (квадратов). Внутри столешницы не должно быть пустот, обрезки не должны выходить за пределы столешницы и не должны перекрываться. Кроме того, Вова хочет использовать минимально возможное число обрезков.

*Вход*: Размер столешницы - одно целое число N (2 <= N <= 20)

*Выход*: Одно число K, задающее минимальное количество обрезков (квадратов), из которых можно построить столешницу (квадрат) заданного размера N. Далее должны идти K строк, каждая из которых должна содержать три целых числа x, y и w, задающие координаты левого верхнего угла и длину стороны соответствующего обрезка (квадрата).

## Ford-Fulkerson

Решение задачи поиска максимального потока в ориентированном графе.

*Вход*:

N – количество ориентированных рёбер графа

v_0 – исток

v_n – сток

v_i v_j w_ij – ребро графа

*Выход*:

P_max – величина максимального потока

v_i v_j w_ij – ребро графа с фактической величиной протекающего потока

## Greedy and A-Star

Решение задачи построения пути в ориентированном графе с помощью двух алгоритмов:

1. Жадный алгоритм. Жадность в данном случае понимается следующим образом: на каждом шаге выбирается последняя посещённая вершина. Переместиться необходимо в ту вершину, путь до которой является самым дешёвым из последней посещённой вершины. Вершины именуются буквами.

2. Алгоритм A-Star. В качестве эвристической функции следует взять близость символов, обозначающих вершины графа, в таблице ASCII. Вершины именуются целыми числами.

## Knuth-Morris-Pratt

Решение задачи поиска подстроки в строке.

1. Реализуйте алгоритм КМП и с его помощью для заданных шаблона P(|P| <= 15000) и текста T(|T| <= 500000) найдите все вхождения P в T .
2. Заданы две строки A(|A| <= 500000) и B(|B| <= 500000). Определить, является ли A циклическим сдвигом B.
