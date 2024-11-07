// Printer.h
#ifndef PRINTER_H // ��� ������ ����: PRINTER_H�� ���ǵ��� �ʾҴٸ� ������ ����
#define PRINTER_H // PRINTER_H�� �����Ͽ� �ߺ� ������ ����

#include <string> // ���ڿ��� ����ϱ� ���� ���̺귯�� ����
using namespace std; // std ���ӽ����̽� ��� (ǥ�� ���̺귯�� �Լ��� ��ü ��� �� std:: ����)

class Printer { // Printer Ŭ���� ���� ����
protected: // ��ӹ��� Ŭ�������� ������ �� �ֵ��� ����
    string model; // ������ �𵨸�
    string manufacturer; // ������ ������
    int printedCount; // �μ�� ������ ��
    int availableCount; // ���� ���� ��

public:
    // Printer Ŭ���� ������ ����: �𵨸�, ������, ���� �ܷ��� �ʱ�ȭ
    Printer(const string& model, const string& manufacturer, int availableCount);

    // ���� ���� �Լ�: �μ� ����� ��ӹ��� Ŭ�������� �ݵ�� �����ؾ� ��
    virtual void print(int pages) = 0;

    // ������ ���� ��� �Լ�: �𵨸�, ������, ���� �ܷ� ���
    virtual void showStatus() const;
};

class InkjetPrinter : public Printer { // InkjetPrinter Ŭ���� ���� (Printer Ŭ���� ���)
private:
    int availableInk; // ��ũ �ܷ�

public:
    // InkjetPrinter Ŭ���� ������ ����: �⺻ ������ ��ũ �ܷ� �ʱ�ȭ
    InkjetPrinter(const string& model, const string& manufacturer, int availableCount, int availableInk);

    // print �Լ� �������̵�: ��ũ�� ���̸� üũ�ϰ� �μ� ����
    void print(int pages) override;

    // showStatus �Լ� �������̵�: �⺻ ���¿� ��ũ �ܷ��� �߰��� ���
    void showStatus() const override;
};

class LaserPrinter : public Printer { // LaserPrinter Ŭ���� ���� (Printer Ŭ���� ���)
private:
    int availableToner; // ��� �ܷ�

public:
    // LaserPrinter Ŭ���� ������ ����: �⺻ ������ ��� �ܷ� �ʱ�ȭ
    LaserPrinter(const string& model, const string& manufacturer, int availableCount, int availableToner);

    // print �Լ� �������̵�: ��ʿ� ���̸� üũ�ϰ� �μ� ����
    void print(int pages) override;

    // showStatus �Լ� �������̵�: �⺻ ���¿� ��� �ܷ��� �߰��� ���
    void showStatus() const override;
};

#endif // ��� ������ ��: PRINTER_H�� �̹� ���ǵǾ� �ִٸ� ������ �������� ����
