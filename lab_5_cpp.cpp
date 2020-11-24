// Программа подсчитывает количество столбцов в матрице, содержащих в себе только уникальные элементы

#include <iostream>
#include <string>

int** init_matrix_auto(int rows, int columns);
int** init_matrix(int rows, int columns);
void print_matrix(int** matrix, int rows, int columns);
int input_int(std::string out);
int input_answer();
int input_matrix();
void counting(int** matrix, int rows, int columns);
void user_interface();

int main()
{
	setlocale(LC_ALL, "ru");
	user_interface();
}


void user_interface() {
	int rows = 4;
	int columns = 9;
	std::cout << "Хотите ввести массив вручную или же использовать автоматическое заполнение? " << std::endl;
	std::cout << "Вручную(0)" << std::endl;
	std::cout << "Автоматически(1)" << std::endl;
	if (input_answer() == 0) {
		int rows = input_int("количество строк: ");
		int columns = input_int("количество столбцов: ");
		int** matrix = init_matrix(rows, columns);
		print_matrix(matrix, rows, columns);
		counting(matrix, rows, columns);
	}
	else {
		int** matrix = init_matrix_auto(rows, columns);
		print_matrix(matrix, rows, columns);
		counting(matrix, rows, columns);
	}
}

int** init_matrix(int rows, int columns) {
	int** matrix = new int* [rows];
	for (int i = 0; i < rows; i++) {
		matrix[i] = new int[columns];
		for (int j = 0; j < columns; j++) {
			std::cout << "Введите желаемое значение для "<< i+1 << "-> строчки и "<< j+1 << "-> столбца: ";
			matrix[i][j] = input_matrix();
		}
	}
	std::cout << "\n";
	return matrix;
}

int** init_matrix_auto(int rows, int columns) {
	int** matrix = new int* [rows];
	for (int i = 0; i < rows; i++) {
		matrix[i] = new int[columns];
	}

	for (int i = 0; i < rows; i++) {
		for (int j = 0; j < columns; j++) {
			matrix[i][j] = rand() % 6 + 1;
		}
	}
	std::cout << "\n";
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

int input_matrix() {
	int inp;
	bool correct = false;
	while (!correct) {
		std::cin >> inp;
		if (std::cin.fail()) {
			std::cin.clear();

			while (std::cin.get() != '\n'); //std::cin.ignore();

			std::cout << "Некорректное значение переменной, попробуйте ввести целочисленное значение: " << std::endl;
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

int input_answer() {
	int inp;
	std::cout << "Введите свой ответ: ";

	bool correct = false;
	while (!correct) {
		std::cin >> inp;
		if ((std::cin.fail()) || ((inp != 0) && (inp != 1))) {
			std::cin.clear();

			while (std::cin.get() != '\n'); //std::cin.ignore();

			std::cout << "Некорректное значение переменной, попробуйте ввести положительное целочисленное значение 1 или 0: " << std::endl;
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
