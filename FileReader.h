// FileReader.h - ������������ ���� ��� ������ ������ �� �����
#include <vector>   // ��� �������� ������� ������
#include <string>   // ��� ������ �� ��������
#include <stdexcept>    // ��� ����������

using namespace std;

class FileReader {
public:
    // ����������� ����� ��� ������ ������ �� �����
    // ���������: ��� �����
    // ����������: ������ ��� (��������, ����)
    // ����� ����������� ���������� ��� �������
    static vector<pair<int, string>> ReadData(const string& Filename);
};