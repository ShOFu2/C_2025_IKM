// TreeException.h - ������������ ���� ������ ���������� ��� ������ � �������
#ifndef TREEEXCEPTION_H
#define TREEEXCEPTION_H

#include <stdexcept>  // ������� ����� ����������
#include <string>     // ��� ������ �� ��������

using namespace std;

// ����� ���������� ��� ������, ����������� ��� ������ � �������
// ����������� �� ������������ runtime_error
class TreeException : public runtime_error {
public:
    // ����������� ��������� ��������� �� ������
    explicit TreeException(const string& Message)
        : runtime_error(Message) { // �������� ��������� �������� ������
    }  
};

#endif