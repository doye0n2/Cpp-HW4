#ifndef PRINTER_H  // ��� ������ �� ���� ���Խ�Ű�� ���� ���ǹ�
#define PRINTER_H

#include <iostream>
#include <string>
using namespace std;

// Printer Ŭ���� ����
class Printer {
protected:
    string model;            // ������ �𵨸�
    string manufacturer;      // ������ ������
    int printedCount;         // �μ�� ������ ��
    int availableCount;       // ���� ���� ��

    // ������: �⺻���� ������ ��, ������, ���� ���� �ʱ�ȭ
    Printer(string mo = "", string me = "", int a = 0);

    // ������ ������� Ȯ���ϴ� �Լ�
    bool isValidPrint(int pages) const;

    // �μ��ϴ� �Լ�: �־��� ������ ����ŭ ����Ʈ
    void print(int pages);

    // �������� ���¸� ����ϴ� �Լ�
    void showPrinter() const;
};

// InkJetPrinter Ŭ���� ���� (Printer Ŭ������ ���)
class InkJetPrinter : public Printer {
    int availableInk;  // ��ũ ��

public:
    // ������: ��, ������, ���� ��, ��ũ ���� �ʱ�ȭ
    InkJetPrinter(string mo = "", string me = "", int a = 0, int i = 0);

    // ��ũ�� ������� Ȯ���ϴ� �Լ�
    bool isValidInkJetPrint(int pages) const;

    // ��ũ�� �����ͷ� �μ��ϴ� �Լ�
    void printInkJet(int pages);

    // ��ũ�� �������� ���¸� ����ϴ� �Լ�
    void showInkJetPrinter() const;
};

// LaserPrinter Ŭ���� ���� (Printer Ŭ������ ���)
class LaserPrinter : public Printer {
    int availableToner;  // ��� ��

public:
    // ������: ��, ������, ���� ��, ��� ���� �ʱ�ȭ
    LaserPrinter(string mo = "", string me = "", int a = 0, int t = 0);

    // ��ʰ� ������� Ȯ���ϴ� �Լ�
    bool isValidLaserPrint(int pages) const;

    // ������ �����ͷ� �μ��ϴ� �Լ�
    void printLaser(int pages);

    // ������ �������� ���¸� ����ϴ� �Լ�
    void showLaserPrinter() const;
};

#endif  // ��� ���� ��
