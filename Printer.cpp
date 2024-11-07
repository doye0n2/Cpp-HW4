// Printer.cpp
#include "Printer.h"  // Printer.h 헤더 파일 포함 (클래스 정의 및 함수 선언 접근)
#include <iostream>    // 표준 입출력 객체인 cout, cin 사용을 위한 라이브러리 포함

using namespace std;   // std 네임스페이스의 객체와 함수를 쉽게 사용하도록 설정

// Printer 클래스 생성자와 멤버 함수 구현
Printer::Printer(const string& model, const string& manufacturer, int availableCount)
    : model(model), manufacturer(manufacturer), printedCount(0), availableCount(availableCount) {
    // 생성자: 모델명, 제조사, 남은 종이 수를 초기화하고 인쇄된 페이지 수는 0으로 설정
}

// Printer 클래스의 showStatus 함수 구현
void Printer::showStatus() const {
    // 모델명, 제조사, 남은 종이 수를 출력
    cout << model << " , " << manufacturer << " , 남은 종이 " << availableCount << "장";
}

// InkjetPrinter 클래스 생성자와 멤버 함수 구현
InkjetPrinter::InkjetPrinter(const string& model, const string& manufacturer, int availableCount, int availableInk)
    : Printer(model, manufacturer, availableCount), availableInk(availableInk) {
    // InkjetPrinter 생성자: 기본 Printer 생성자를 호출하여 모델명, 제조사, 종이 수 초기화하고
    // 추가적으로 잉크 잔량을 초기화
}

// InkjetPrinter 클래스의 print 함수 구현
void InkjetPrinter::print(int pages) {
    // 인쇄할 페이지 수가 남은 종이와 잉크 잔량을 초과하지 않으면 인쇄 가능
    if (availableCount >= pages && availableInk >= pages) {
        availableCount -= pages;  // 종이 수 차감
        availableInk -= pages;    // 잉크 잔량 차감
        printedCount += pages;    // 인쇄된 페이지 수 증가
        cout << "프린트하였습니다.\n";  // 인쇄 완료 메시지 출력
    }
    else {
        cout << "용지가 부족하여 프린트할 수 없습니다.\n";  // 자원 부족 시 경고 메시지 출력
    }
}

// InkjetPrinter 클래스의 showStatus 함수 구현
void InkjetPrinter::showStatus() const {
    // Printer 클래스의 showStatus를 호출하여 기본 상태 출력
    Printer::showStatus();
    // 잉크 잔량도 함께 출력
    cout << " , 남은 잉크 " << availableInk << "\n";
}

// LaserPrinter 클래스 생성자와 멤버 함수 구현
LaserPrinter::LaserPrinter(const string& model, const string& manufacturer, int availableCount, int availableToner)
    : Printer(model, manufacturer, availableCount), availableToner(availableToner) {
    // LaserPrinter 생성자: 기본 Printer 생성자를 호출하여 모델명, 제조사, 종이 수 초기화하고
    // 추가적으로 토너 잔량을 초기화
}

// LaserPrinter 클래스의 print 함수 구현
void LaserPrinter::print(int pages) {
    // 인쇄할 페이지 수가 남은 종이와 토너 잔량을 초과하지 않으면 인쇄 가능
    if (availableCount >= pages && availableToner >= pages) {
        availableCount -= pages;  // 종이 수 차감
        availableToner -= pages;  // 토너 잔량 차감
        printedCount += pages;    // 인쇄된 페이지 수 증가
        cout << "프린트하였습니다.\n";  // 인쇄 완료 메시지 출력
    }
    else {
        cout << "용지가 부족하여 프린트할 수 없습니다.\n";  // 자원 부족 시 경고 메시지 출력
    }
}

// LaserPrinter 클래스의 showStatus 함수 구현
void LaserPrinter::showStatus() const {
    // Printer 클래스의 showStatus를 호출하여 기본 상태 출력
    Printer::showStatus();
    // 토너 잔량도 함께 출력
    cout << " , 남은 토너 " << availableToner << "\n";
}
