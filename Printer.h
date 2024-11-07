#ifndef PRINTER_H  // 헤더 파일을 한 번만 포함시키기 위한 조건문
#define PRINTER_H

#include <iostream>
#include <string>
using namespace std;

// Printer 클래스 선언
class Printer {
protected:
    string model;            // 프린터 모델명
    string manufacturer;      // 프린터 제조사
    int printedCount;         // 인쇄된 페이지 수
    int availableCount;       // 남은 용지 수

    // 생성자: 기본값을 가지며 모델, 제조사, 용지 수를 초기화
    Printer(string mo = "", string me = "", int a = 0);

    // 용지가 충분한지 확인하는 함수
    bool isValidPrint(int pages) const;

    // 인쇄하는 함수: 주어진 페이지 수만큼 프린트
    void print(int pages);

    // 프린터의 상태를 출력하는 함수
    void showPrinter() const;
};

// InkJetPrinter 클래스 선언 (Printer 클래스의 상속)
class InkJetPrinter : public Printer {
    int availableInk;  // 잉크 수

public:
    // 생성자: 모델, 제조사, 용지 수, 잉크 수를 초기화
    InkJetPrinter(string mo = "", string me = "", int a = 0, int i = 0);

    // 잉크가 충분한지 확인하는 함수
    bool isValidInkJetPrint(int pages) const;

    // 잉크젯 프린터로 인쇄하는 함수
    void printInkJet(int pages);

    // 잉크젯 프린터의 상태를 출력하는 함수
    void showInkJetPrinter() const;
};

// LaserPrinter 클래스 선언 (Printer 클래스의 상속)
class LaserPrinter : public Printer {
    int availableToner;  // 토너 수

public:
    // 생성자: 모델, 제조사, 용지 수, 토너 수를 초기화
    LaserPrinter(string mo = "", string me = "", int a = 0, int t = 0);

    // 토너가 충분한지 확인하는 함수
    bool isValidLaserPrint(int pages) const;

    // 레이저 프린터로 인쇄하는 함수
    void printLaser(int pages);

    // 레이저 프린터의 상태를 출력하는 함수
    void showLaserPrinter() const;
};

#endif  // 헤더 파일 끝
