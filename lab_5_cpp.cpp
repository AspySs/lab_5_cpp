// Программа подсчитывает количество столбцов в матрице, содержащих в себе только уникальные элементы
// При желании можно раскомментировать части кода, для включения взаимодействия с пользователем!

#include <iostream>
// #include <string>

int** init_matrix(int rows, int columns);
void print_matrix(int** matrix, int rows, int columns);
// int input_int(std::string out);
void counting(int** matrix, int rows, int columns);

int main()
{
	setlocale(LC_ALL, "ru");
	int rows = 4;
	int columns = 9;
	// int rows = input_int("количество строк: ");
	// int columns = input_int("количество столбцов: ");
	int** matrix = init_matrix(rows, columns);
	print_matrix(matrix, rows, columns);
	counting(matrix, rows, columns);
}
int** init_matrix(int rows, int columns) {
	int** matrix = new int* [rows];
	for (int i = 0; i < rows; i++) {
		matrix[i] = new int[columns];
	}

	for (int i = 0; i < rows; i++) {
		for (int j = 0; j < columns; j++) {
			matrix[i][j] = rand() % 6 + 1;
		}
	}
	return matrix;
}

void print_matrix(int** matrix, int rows, int columns) {
	for (int i = 0; i < rows; i++) {
		for (int j = 0; j < columns; j++) {
			std::cout << matrix[i][j] << "\t";
		}
		std::cout << '\n';
	}
}

/*
int input_int(std::string out) {
	int inp;
	std::cout << "Введите " + out;

	bool correct = false;
	while (!correct) {
		std::cin >> inp;
		if ((std::cin.fail()) || (inp <= 0)) {
			std::cin.clear();

			while (std::cin.get() != '\n'); //std::cin.ignore();

			std::cout << "Некорректное значение переменной, попробуйте ввести положительное целочисленное значение: " << std::endl;
			correct = false;
			std::cin.clear();
			continue;
		}
		else {
			//std::cin.ignore();
			correct = true;
		}
	}
	return inp;
}
*/

void counting(int** matrix, int rows, int columns) {
	bool status = true;
	int count = 0;
	for (int i = 0; i < columns; i++) {
		for (int j = 0; j < rows; j++) {
			for (int p = j + 1; p < rows; p++) {
				if (matrix[j][i] == matrix[p][i]) {
					status = false;
					break;
				}
			}
			if (!status) {
				break;
			}
		}
		if (status) {
			count++;
		}
		status = true;
	}
	std::cout << '\n';
	std::cout << "Количество столбцов содержащих только уникальные элементы: " << count << std::endl;
}
