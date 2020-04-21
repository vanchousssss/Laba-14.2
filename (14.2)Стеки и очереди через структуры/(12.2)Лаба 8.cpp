// Суслов Иван. 8 вариант. Лабраторная 14.2 (Стеки и очереди через структуры)(8э)
//

#include <iostream>
#include <string>
#include <Windows.h>
#include <fstream>
#include <stack>
#include <queue>

using namespace std;

//СТЕК---------------------------------------------------------------------------------
struct stackSt {
	int data;
	stackSt* prev;
};

//создание стека
stackSt* makeStack(int n) {
	stackSt* first = new stackSt;
	cout << "Введите 1-ый элемент стека: ";
	cin >> first->data;
	first->prev = NULL;
	stackSt* p = new stackSt;
	p->prev = first;
	if (n != 1) {
		for (int i = 1; i < n; i++) {
			stackSt* temp = new stackSt;
			cout << "Введите " << i + 1 << "-ый элемент стека: ";
			cin >> p->data;
			temp->prev = p;
			p = temp;
		}
	}
	return p->prev;
}
//печать
void printStack(stackSt* top) {
	if (top == NULL) {
		cout << "Стек пуст";
		return;
	}
	stackSt* p = top;
	while (p->prev != NULL) {
		cout << p->data << " ";
		p = p->prev;
	}
	cout << p->data;
}
//Добавление элемента
stackSt* additionStack(stackSt* top, int n) {
	stackSt* p = new stackSt;
	p->prev = top;
	for (int i = 0; i < n; i++) {
		stackSt* temp = new stackSt;
		cout << "Введите новый элемент стека: ";
		cin >> p->data;
		temp->prev = p;
		p = temp;
	}
	return p->prev;
}

//удаление элемента
stackSt* deleteStackEl(stackSt* top, int n) {
	if (top == NULL)
	{
		cout << "Стек пустой!" << endl;
		return 0;
	}
	for (int i = n; i > 0; i--) {
		top = top->prev;
	}
	return top;
}
//удаление стека
stackSt* deleteStack(stackSt* top) {
	while (top != NULL) top = top->prev;
	return top;
}
//--------------------------------------------------------------------------------------

//ОЧЕРЕДЬ-------------------------------------------------------------------------------
struct queueSt {
	int data;
	queueSt* next;
};

//создание очереди
queueSt* makeQueue(int n) {
	queueSt* first = new queueSt;
	cout << "Введите 1-ый элемент очереди ";
	cin >> first->data;
	first->next = NULL;
	if (n != 1) {
		queueSt* p = new queueSt;
		first->next = p;
		for (int i = 1; i < n; i++) {
			queueSt* temp = new queueSt;
			cout << "Введите " << i + 1 << "-ый элемент очереди ";
			cin >> p->data;
			if (i != n - 1) {
				p->next = temp;
				p = temp;
			}
			p->next = NULL;
		}
	}
	return first;
}
//печать
void printQueue(queueSt* first) {
	if (first == NULL) {
		cout << "Очередь пуста";
		return;
	}
	queueSt* p = first;
	while (p->next != NULL) {
		cout << p->data << " ";
		p = p->next;
	}
	cout << p->data;
}
//добавление элемента
queueSt* additionQueue(queueSt* first, int n) {
	queueSt* p = first;
	while (p->next != NULL) p = p->next;
	queueSt* temp1 = new queueSt;
	p->next = temp1;
	p = p->next;
	for (int i = 0; i < n; i++) {
		queueSt* temp = new queueSt;
		cout << "Введите новый элемент очереди ";
		cin >> p->data;
		if (i != n - 1) {
			p->next = temp;
			p = temp;
		}
		p->next = NULL;
	}
	return first;
}
//удаление элемента
void deleteQueueEl(queueSt*& first, int& n) {
	queueSt* p = first;
	first = first->next;
	n--;
	delete p;
	return;
}
//удаление очереди
queueSt* deleteQueue(queueSt* first) {

	while (first->next != NULL) {
		queueSt* top = first;
		while (top->next != NULL) top = top->next;
		queueSt* p = first;
		while (p->next != top) p = p->next;
		p->next = NULL;
	}
	first = NULL;
	return first;
}
//---------------------------------------------------------------------------------------



int main()
{
	setlocale(LC_ALL, "ru");
	SetConsoleCP(1251);
	SetConsoleOutputCP(1251);

	string D;
	int n, K, c = 0;
	stackSt* stackk = 0;
	queueSt* queueq = 0;
	stack <int> stek;
	queue <int> queueqq;
	int key1, key2, key3;
	cout << "\tГлавное меню\n1-Стек\n2-Очередь\n0-Завершить программу" << endl;
	do
	{
		cout << endl << "Вы выбрали - ";
		cin >> key1;
		switch (key1)
		{
			//СТЕК------------------
		case 1:

			int b;
			system("cls");
			cout << "\tСоздать стек через:\n1-Структуру\n2-Стандартную библиотеку\n0-Назад" << endl;
			do
			{
				cout << endl << "Вы выбрали - ";
				cin >> key3;
				switch (key3)
				{
					//стек через структуру		
				case 1:

					system("cls");
					cout << "\tСтек через структуру\n1-Создание стека\n2-Печать стека\n3-Удаление элементов из стека\n4-Добавление элементов в стек\n5-Удаление стека\n0-Назад";
					do
					{
						cout << endl << "Вы выбрали - ";
						cin >> key2;
						switch (key2)
						{
						case 1:
							cout << "Введите количество элементов в стеке - ";
							cin >> n;
							stackk = makeStack(n);
							cout << "Стек создан" << endl;
							break;

						case 2:
							cout << "Исходный стек: " << endl;
							printStack(stackk);
							cout << endl;
							break;

						case 3:
							cout << endl << "Введите количество удаляемых элементов: ";
							cin >> b;
							stackk = deleteStackEl(stackk, b);
							cout << "\nСтек после удаления\n";
							printStack(stackk);
							cout << endl;
							break;

						case 4:
							cout << "Введите количество добавляемых элементов: ";
							cin >> c;
							stackk = additionStack(stackk, c);
							cout << "Стек после добавления элементов:\n";
							printStack(stackk);
							cout << endl;
							break;

						case 5:
							stackk = deleteStack(stackk);
							cout << "Стек удалён!" << endl;
							break;


						default:

							if (key2 != 0)
							{
								cout << "Попробуй поточнее!" << endl;
								break;
							}
						}

					} while (key2 != 0);
					system("cls");
					cout << "\tСоздать стек через:\n1-Структуру\n2-Стандартную библиотеку\n0-Назад" << endl;

					break;

					//стек через библ
				case 2:
					system("cls");
					cout << "\tСтек через стандартную библиотеку\n1-Создание стека\n2-Узнать количество элементов в стеке\n3-Удаление верхнего элемента\n4-Вывод верхнего элемента\n5-Проверить, пуст ли стек\n0-Назад";
					do
					{
						cout << endl << "Вы выбрали - ";
						cin >> key2;
						switch (key2)
						{
						case 1:
							cout << "Введите количество элементов в стеке: ";
							cin >> n;
							cout << "Последовательный ввод элементов:\n";
							for (int i = 0; i < n; i++)
							{
								cout << "Введите элемент стека: ";
								cin >> b;
								stek.push(b);
							}
							cout << "Стек заполнен" << endl;
							break;

						case 2:
							cout << "Количество элементов в стеке - " << stek.size() << endl;
							break;

						case 3:
							if (stek.empty() == true)
								cout << "Стек пустой!" << endl;
							else
							{
								stek.pop();
								cout << "Верхний элемент удалён!" << endl;
							}
							break;

						case 4:
							if (stek.empty() == true)
								cout << "Стек пустой!" << endl;
							else
								cout << "Верхний элемент стека - " << stek.top() << endl;
							break;
						case 5:
							if (stek.empty() == true)
								cout << "Стек пустой!" << endl;
							else cout << " Стек не пустой!" << endl;
							break;


						default:

							if (key2 != 0)
							{
								cout << "Попробуй поточнее!" << endl;
								break;
							}
						}

					} while (key2 != 0);
					system("cls");
					cout << "\tСоздать стек через:\n1-Структуру\n2-Стандартную библиотеку\n0-Назад" << endl;

					break;

				default:
					if (key1 != 0)
					{
						cout << "Попробуй поточнее!" << endl;
						break;
					}
				}
			} while (key3 != 0);
			system("cls");
			cout << "\tГлавное меню\n1-Однонаправленный список целых чисел\n2-Двунаправленный список слов\n3-Стек\n4-Очередь\n0-Завершить программу" << endl;

			break;

			//ОЧЕРЕДЬ----------------------
		case 2:

			system("cls");
			cout << "\tСоздать очередь через:\n1-Структуру\n2-Стандартную библиотеку\n0-Назад" << endl;
			do
			{
				cout << endl << "Вы выбрали - ";
				cin >> key3;
				switch (key3)
				{
					//очередь через структ
				case 1:

					system("cls");
					cout << "\tОчередь через структуру\n1-Создание очереди\n2-Печать очереди\n3-Удаление элемента из очереди\n4-Добавление элементов в очередь\n5-Удаление очереди\n0-Назад";
					do
					{
						cout << endl << "Вы выбрали - ";
						cin >> key2;
						switch (key2)
						{
						case 1:
							cout << "Введите количество элементов в очереди - ";
							cin >> n;
							queueq = makeQueue(n);
							cout << "Очередь создана" << endl;
							break;

						case 2:
							cout << "Исходная очередь: " << endl;
							printQueue(queueq);
							cout << endl;
							break;

						case 3:
							deleteQueueEl(queueq, b);
							cout << "\nОчередь после удаления\n";
							printQueue(queueq);
							cout << endl;
							break;

						case 4:
							cout << "Введите количество добавляемых элементов: ";
							cin >> c;
							queueq = additionQueue(queueq, c);
							cout << "Очередь после добавления элементов:\n";
							printQueue(queueq);
							cout << endl;
							break;

						case 5:
							queueq = deleteQueue(queueq);
							cout << "Очередь удалена!" << endl;
							break;

						default:
							cout << "Попробуй поточнее!" << endl;
							break;
						}

					} while (key2 != 0);
					system("cls");
					cout << "\tСоздать очередь через:\n1-Структуру\n2-Стандартную библиотеку\n0-Назад" << endl;

					break;

					//очередь через библ
				case 2:

					system("cls");
					cout << "\tОчередь через стандартную библиотеку\n1-Создание очереди\n2-Узнать количество элементов в очереди\n3-Удаление первого элемента\n4-Вывести первый и последний элементы очереди\n5-Проверить, пуста ли очередь\n0-Назад";
					do
					{
						cout << endl << "Вы выбрали - ";
						cin >> key2;
						switch (key2)
						{
						case 1:
							cout << "Введите количество элементов в очереди: ";
							cin >> n;
							cout << "Последовательный ввод элементов:\n";
							for (int i = 0; i < n; i++)
							{
								cout << "Введите элемент очереди: ";
								cin >> b;
								queueqq.push(b);

							}
							cout << "Очередь заполнена" << endl;
							break;

						case 2:
							cout << "Количество элементов в очереди - " << queueqq.size() << endl;
							break;

						case 3:
							if (queueqq.empty() == true)
								cout << "Очередь пустая!" << endl;
							else
							{
								queueqq.pop();
								cout << "Первый элемент удалён!" << endl;
							}
							break;

						case 4:
							if (queueqq.empty() == true)
								cout << "Очередь пустая!" << endl;
							else
							{
								cout << "Первый элемент очереди - " << queueqq.front() << endl;
								cout << "Последний элемент очереди - " << queueqq.back() << endl;
							}
							break;

						case 5:
							if (queueqq.empty() == true)
								cout << "Очередь пустая!" << endl;
							else cout << "Очередь не пустая!" << endl;
							break;

						default:

							if (key2 != 0)
							{
								cout << "Попробуй поточнее!" << endl;
								break;
							}
						}

					} while (key2 != 0);
					system("cls");
					cout << "\tСоздать стек через:\n1-Структуру\n2-Стандартную библиотеку\n0-Назад" << endl;

				default:
					if (key2 != 0)
					{
						cout << "Попробуй поточнее!" << endl;
						break;
					}
				}
			} while (key3 != 0);
			system("cls");
			cout << "\tГлавное меню\n1-Однонаправленный список целых чисел\n2-Двунаправленный список слов\n3-Стек\n4-Очередь\n0-Завершить программу" << endl;
			break;

		default:
			if (key1 != 0)
			{
				cout << "Попробуй поточнее!" << endl;
				break;
			}
		}
	} while (key1 != 0);

	system("pause");
	return 0;
}
