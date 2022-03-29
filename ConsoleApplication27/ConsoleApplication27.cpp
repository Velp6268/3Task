#include <iostream>

using namespace std;
#define SIZE 100

struct Stack
{
    int* arr;
    int top;
    int capacity;

public:
    Stack(int size = SIZE);
    ~Stack();

    void push(int);
    int pop();
    int peek();

    int size();
    bool isEmpty();
    bool isFull();
};


Stack::Stack(int size)
{
    arr = new int[size];
    capacity = size;
    top = -1;
}


Stack::~Stack() {
    delete[] arr;
}


void Stack::push(int x)
{
    if (isFull())
    {
        exit(EXIT_FAILURE);
    }
    arr[++top] = x;
}

int Stack::pop()
{
    if (isEmpty())
    {
        exit(EXIT_FAILURE);
    }

    return arr[top--];
}

int Stack::peek()
{
    if (!isEmpty()) {
        return arr[top];
    }
    else {
        exit(EXIT_FAILURE);
    }
}


int Stack::size() {
    return top + 1;
}


bool Stack::isEmpty() {
    return top == -1;
}


bool Stack::isFull() {
    return top == capacity - 1;
}



int main()
{

    setlocale(LC_ALL, "rus");

    Stack  numbers, even_elements, odd_elements;//создание три списка типа int, первый с числами, остальные для четных и нечетных элементов

    int size, volue;
    //заполнение стека
    cout << "Кол-во элементов: ";
    cin >> size;// запись введеного значния в переменную
    for (int i = 0; i < size; i++) {
        cout << "Введите " << i + 1 << " Элемент списка: ";
        cin >> volue;
        numbers.push(volue);//добавление элемента в список
    }



    //обход стека с помощью итератора
    for (int i = 0; i < size; i++) {
        if (numbers.peek() % 2 == 0) {
            even_elements.push(numbers.peek());//добавление в список если четное число
        }
        else {
            odd_elements.push(numbers.peek());//добавление в список если нечетное число
        }
        numbers.pop();
    }

    cout << "Список четных чисел: ";
    size = even_elements.size();
    for (int i = 0; i < size; i++) {
        cout << even_elements.peek() << " ";
        even_elements.pop();
    }
    cout << endl;

    cout << "Список нечетных чисел: ";
    size = odd_elements.size();
    for (int i = 0; i < size; i++) {
        cout << odd_elements.peek() << " ";
        odd_elements.pop();
    }
    cout << endl;

    return 0;
}