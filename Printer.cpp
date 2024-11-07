// Printer.cpp
#include "Printer.h"  // Printer.h ��� ���� ���� (Ŭ���� ���� �� �Լ� ���� ����)
#include <iostream>    // ǥ�� ����� ��ü�� cout, cin ����� ���� ���̺귯�� ����

using namespace std;   // std ���ӽ����̽��� ��ü�� �Լ��� ���� ����ϵ��� ����

// Printer Ŭ���� �����ڿ� ��� �Լ� ����
Printer::Printer(const string& model, const string& manufacturer, int availableCount)
    : model(model), manufacturer(manufacturer), printedCount(0), availableCount(availableCount) {
    // ������: �𵨸�, ������, ���� ���� ���� �ʱ�ȭ�ϰ� �μ�� ������ ���� 0���� ����
}

// Printer Ŭ������ showStatus �Լ� ����
void Printer::showStatus() const {
    // �𵨸�, ������, ���� ���� ���� ���
    cout << model << " , " << manufacturer << " , ���� ���� " << availableCount << "��";
}

// InkjetPrinter Ŭ���� �����ڿ� ��� �Լ� ����
InkjetPrinter::InkjetPrinter(const string& model, const string& manufacturer, int availableCount, int availableInk)
    : Printer(model, manufacturer, availableCount), availableInk(availableInk) {
    // InkjetPrinter ������: �⺻ Printer �����ڸ� ȣ���Ͽ� �𵨸�, ������, ���� �� �ʱ�ȭ�ϰ�
    // �߰������� ��ũ �ܷ��� �ʱ�ȭ
}

// InkjetPrinter Ŭ������ print �Լ� ����
void InkjetPrinter::print(int pages) {
    // �μ��� ������ ���� ���� ���̿� ��ũ �ܷ��� �ʰ����� ������ �μ� ����
    if (availableCount >= pages && availableInk >= pages) {
        availableCount -= pages;  // ���� �� ����
        availableInk -= pages;    // ��ũ �ܷ� ����
        printedCount += pages;    // �μ�� ������ �� ����
        cout << "����Ʈ�Ͽ����ϴ�.\n";  // �μ� �Ϸ� �޽��� ���
    }
    else {
        cout << "������ �����Ͽ� ����Ʈ�� �� �����ϴ�.\n";  // �ڿ� ���� �� ��� �޽��� ���
    }
}

// InkjetPrinter Ŭ������ showStatus �Լ� ����
void InkjetPrinter::showStatus() const {
    // Printer Ŭ������ showStatus�� ȣ���Ͽ� �⺻ ���� ���
    Printer::showStatus();
    // ��ũ �ܷ��� �Բ� ���
    cout << " , ���� ��ũ " << availableInk << "\n";
}

// LaserPrinter Ŭ���� �����ڿ� ��� �Լ� ����
LaserPrinter::LaserPrinter(const string& model, const string& manufacturer, int availableCount, int availableToner)
    : Printer(model, manufacturer, availableCount), availableToner(availableToner) {
    // LaserPrinter ������: �⺻ Printer �����ڸ� ȣ���Ͽ� �𵨸�, ������, ���� �� �ʱ�ȭ�ϰ�
    // �߰������� ��� �ܷ��� �ʱ�ȭ
}

// LaserPrinter Ŭ������ print �Լ� ����
void LaserPrinter::print(int pages) {
    // �μ��� ������ ���� ���� ���̿� ��� �ܷ��� �ʰ����� ������ �μ� ����
    if (availableCount >= pages && availableToner >= pages) {
        availableCount -= pages;  // ���� �� ����
        availableToner -= pages;  // ��� �ܷ� ����
        printedCount += pages;    // �μ�� ������ �� ����
        cout << "����Ʈ�Ͽ����ϴ�.\n";  // �μ� �Ϸ� �޽��� ���
    }
    else {
        cout << "������ �����Ͽ� ����Ʈ�� �� �����ϴ�.\n";  // �ڿ� ���� �� ��� �޽��� ���
    }
}

// LaserPrinter Ŭ������ showStatus �Լ� ����
void LaserPrinter::showStatus() const {
    // Printer Ŭ������ showStatus�� ȣ���Ͽ� �⺻ ���� ���
    Printer::showStatus();
    // ��� �ܷ��� �Բ� ���
    cout << " , ���� ��� " << availableToner << "\n";
}
