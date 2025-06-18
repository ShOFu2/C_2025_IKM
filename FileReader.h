// FileReader.h - заголовочный файл для чтения данных из файла
#include <vector>   // Для возврата вектора данных
#include <string>   // Для работы со строками
#include <stdexcept>    // Для исключений

using namespace std;

class FileReader {
public:
    // Статический метод для чтения данных из файла
    // Принимает: имя файла
    // Возвращает: вектор пар (значение, путь)
    // Может выбрасывать исключения при ошибках
    static vector<pair<int, string>> ReadData(const string& Filename);
};