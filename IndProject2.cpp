// IndProject2.cpp - основной файл программы
#include "BinaryTree.h" // Для работы с деревом
#include "FileReader.h" // Для чтения данных
#include <iostream>     // Для ввода/вывода
#include <fstream>      // Для работы с файлами

using namespace std;

// Функция вывода приветственного сообщения
void WelcomeMessage() {
    cout << "Программа для построения бинарного дерева по заданным путям\n";
    cout << "Формат входного файла: <число> <двоичный путь>\n";
    cout << "Пример: 15 111\n18 101\n3 10\n";
}

// Функция получения имени файла от пользователя
string InputFilename() {
    string Filename;
    while (true) {
        cout << "\nВведите имя файла с данными (или 'exit' для выхода): ";
        cin >> Filename;

        if (Filename == "exit") {   // Команда выхода
            exit(0);
        }

        // Проверка существования файла
        ifstream TestFile(Filename);
        if (TestFile.good()) {
            TestFile.close();
            return Filename;    // Возвращаем корректное имя файла
        }

        cout << "Ошибка: файл '" << Filename << "' не существует или недоступен.\n";
        cout << "Пожалуйста, попробуйте еще раз.\n";
    }
}

// Точка входа в программу
int main() {
    setlocale(LC_ALL, "russian");
    WelcomeMessage();   // Выводим приветствие

    try {
        while (true) {  // Основной цикл программы
            string Filename = InputFilename();  // Получаем имя файла

            try {
                // Чтение данных из файла
                auto Data = FileReader::ReadData(Filename);

                // Построение и вывод дерева
                BinaryTree Tree;
                Tree.BuildFromData(Data);
                Tree.Print();
            }
            catch (const exception& E) {    // Обработка ошибок при работе с файлом
                cerr << "\nОшибка при обработке файла: " << E.what() << "\n\n";
            }
        }
    }
    catch (...) {   // Обработка непредвиденных ошибок
        cerr << "Произошла непредвиденная ошибка. Программа завершает работу.\n";
        return 1;
    }

    return 0;
}