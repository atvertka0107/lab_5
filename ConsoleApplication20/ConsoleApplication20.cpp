#include <iostream>
#include <iomanip>
#include <Windows.h>
#include <conio.h>
#include "Matrix.h"


// Matrix.h - заголовочный файл с реализацией матрицы
//Функция для считывания данных с клавиатуры.
//В случае некорректного ввода данных, функция отслеживает нажатие клавиши ESC, для 
//завершения работы программы.

void getData(unsigned& n)
{

    std::cout << "Введите размер матрицы...\n";
    std::cin >> n;

    if (std::cin.fail())
    {

        std::cout << "Данные некорректны.\nНажмите ESC для выхода из программы, Enter - для продолжения.\n";
        std::cin.ignore(1000, '\n');

        switch (_getch())
        {

        case 27:

            system("cls");
            std::cout << "Завершение работы.";
            exit(0);
            break;

        default:
            
            system("cls");
            std::cin.clear();
            std::cin.ignore(1000, '\n');
            getData(n);
            break;

        }
    }
    else
        return;
}

// Объявляем hsndle для доступа к аттрибутам текста в консоли
HANDLE handle = GetStdHandle(STD_OUTPUT_HANDLE);
CONSOLE_SCREEN_BUFFER_INFO start_attribute;


int main()
{
    // Получаем начальные атрибуты коммандной строки
    GetConsoleScreenBufferInfo(handle, &start_attribute);

    setlocale(LC_ALL, "RU"); srand(time(0));
    unsigned n; getData(n);
    Matrix m(n); 

    // Выводим начальную матрицу заполненную случайными числами
    m.print_matrix();
    // Заменяем значения элементов ниже главной диагонали матрицы на нули
    m.insert_zeros();
    
    for (unsigned i = 0; i < n; i++) 
    {
        for (unsigned j = 0; j < n; j++)
        {
            if (i > j)
            {
                SetConsoleTextAttribute(handle, 14); // 14 - Yellow
                std::cout << std::setw(3) << std::setfill('0') << m(i, j) << ' ';
                SetConsoleTextAttribute(handle, start_attribute.wAttributes);
            }
            else if (i < j)
            {
                SetConsoleTextAttribute(handle, 2); // 2 - Green
                std::cout << std::setw(3) << std::setfill('0') << m(i, j) << ' ';
                SetConsoleTextAttribute(handle, start_attribute.wAttributes);
            }
            else
                std::cout << std::setw(3) << std::setfill('0') << m(i, j) << ' ';
        }
        std::cout << std::endl;
    }
    std::cout << std::endl;
    system("pause");
    return 0;
}
