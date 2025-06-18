// TreeException.h - заголовочный файл класса исключений для работы с деревом
#ifndef TREEEXCEPTION_H
#define TREEEXCEPTION_H

#include <stdexcept>  // Базовый класс исключений
#include <string>     // Для работы со строками

using namespace std;

// Класс исключений для ошибок, специфичных для работы с деревом
// Наследуется от стандартного runtime_error
class TreeException : public runtime_error {
public:
    // Конструктор принимает сообщение об ошибке
    explicit TreeException(const string& Message)
        : runtime_error(Message) { // Передаем сообщение базовому классу
    }  
};

#endif