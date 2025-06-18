// FileReader.cpp - ���������� ������� ������ FileReader
#include "FileReader.h"
#include <fstream>  // ��� ������ � �������
#include <sstream>  // ��� ������� �����

using namespace std;

vector<pair<int, string>> FileReader::ReadData(const string& Filename) {
    vector<pair<int, string>> Data; // ������ ��� �����������
    ifstream File(Filename);        // ��������� ����

    if (!File.is_open()) {  // �������� ���������� ��������
        throw runtime_error("�� ������� ������� ����: " + Filename);
    }

    string Line;    // ����� ��� ������ �����
    while (getline(File, Line)) {   // ������ ���� ���������
        // ������� ������ ������� � ������ � ����� ������
        Line.erase(0, Line.find_first_not_of(" \t"));
        Line.erase(Line.find_last_not_of(" \t") + 1);

        if (Line.empty()) continue; // ���������� ������ ������

        // ��������� ������ �� �����
        istringstream Iss(Line);
        vector<string> Parts;
        string Part;

        while (Iss >> Part) {   // ��������� �� ��������
            Parts.push_back(Part);
        }

        // ��������� ������������ ������� (������ ���� 2 �����)
        if (Parts.size() != 2) {
            throw runtime_error("�������� ������ ������: " + Line);
        }

        try {
            // �������� ������������� ������ ����� � �����
            int Value = stoi(Parts[0]);
            // ��������� ���� (�����, ����) � ���������
            Data.emplace_back(Value, Parts[1]);
        }
        catch (const exception& E) { // ��������� ������ ��������������
            throw runtime_error("������ ��� ��������� ������: " + Line + " - " + E.what());
        }
    }

    return Data;    // ���������� ���������
}