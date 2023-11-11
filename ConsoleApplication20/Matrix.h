#pragma once
#include <iostream>
#include <iomanip>

// Заголовочный файл
class Matrix
{
private:
	unsigned size;
	int* data;
public:

	Matrix();

	Matrix(unsigned size);

	void init_data();

	void print_matrix();

	void insert_zeros();

	int& operator()(unsigned i, unsigned j);

	~Matrix();
	
};

