// FileReader.cpp - реализация методов класса FileReader
#include "FileReader.h"
#include <fstream>  // Для работы с файлами
#include <sstream>  // Для разбора строк

using namespace std;

vector<pair<int, string>> FileReader::ReadData(const string& Filename) {
    vector<pair<int, string>> Data; // Вектор для результатов
    ifstream File(Filename);        // Открываем файл

    if (!File.is_open()) {  // Проверка успешности открытия
        throw runtime_error("Не удалось открыть файл: " + Filename);
    }

    string Line;    // Буфер для чтения строк
    while (getline(File, Line)) {   // Читаем файл построчно
        // Удаляем лишние пробелы в начале и конце строки
        Line.erase(0, Line.find_first_not_of(" \t"));
        Line.erase(Line.find_last_not_of(" \t") + 1);

        if (Line.empty()) continue; // Пропускаем пустые строки

        // Разбиваем строку на части
        istringstream Iss(Line);
        vector<string> Parts;
        string Part;

        while (Iss >> Part) {   // Разделяем по пробелам
            Parts.push_back(Part);
        }

        // Проверяем корректность формата (должно быть 2 части)
        if (Parts.size() != 2) {
            throw runtime_error("Неверный формат строки: " + Line);
        }

        try {
            // Пытаемся преобразовать первую часть в число
            int Value = stoi(Parts[0]);
            // Добавляем пару (число, путь) в результат
            Data.emplace_back(Value, Parts[1]);
        }
        catch (const exception& E) { // Обработка ошибок преобразования
            throw runtime_error("Ошибка при обработке строки: " + Line + " - " + E.what());
        }
    }

    return Data;    // Возвращаем результат
}