#include "Matrix.h"


Matrix::Matrix() : size(0), data(new int[0]) {}

Matrix::Matrix(unsigned size)
{
	this->size = size;
	this->data = new int[size * size];
	this->init_data();
}

void Matrix::init_data() // Заполняем матрицу числами
{
	for (unsigned i = 0; i < this->size * this->size; i++)
		this->data[i] = rand() % 1000;
}

void Matrix::print_matrix() // Метод вывода матрицы в консоль
{
    for (unsigned i = 0; i < this->size; i++)
    {
        for (unsigned j = 0; j < this->size; j++)
        {
            std::cout << std::setw(3) << std::setfill('0') << this->data[i * this->size + j] << ' ';
        }
        std::cout << std::endl;
    }
    std::cout << std::endl;
}

void Matrix::insert_zeros() // Метод для для "зануления" элементов ниже главной диагонали
{
    for (unsigned i = 0; i < this->size; i++)
    {
        for (unsigned j = 0; j < this->size; j++)
        {
            if (i > j)
                this->data[i * this->size + j] = 0;
        }
    }
}

int& Matrix::operator()(unsigned i, unsigned j) // Перегрузка оператора - (), для обращения 
{                                               // к элементам матрицы с помощью скобок (i, j)
    return this->data[i * this->size + j];
}

Matrix::~Matrix() // Деструктор класса для предотвращения утечек памяти.
{                 // "Освобождаем" выделенную память под динамический массив.
    delete[] data;
}
