// Printer.h
#ifndef PRINTER_H // 헤더 가드의 시작: PRINTER_H가 정의되지 않았다면 파일을 포함
#define PRINTER_H // PRINTER_H를 정의하여 중복 포함을 방지

#include <string> // 문자열을 사용하기 위한 라이브러리 포함
using namespace std; // std 네임스페이스 사용 (표준 라이브러리 함수나 객체 사용 시 std:: 생략)

class Printer { // Printer 클래스 정의 시작
protected: // 상속받은 클래스에서 접근할 수 있도록 설정
    string model; // 프린터 모델명
    string manufacturer; // 프린터 제조사
    int printedCount; // 인쇄된 페이지 수
    int availableCount; // 남은 종이 수

public:
    // Printer 클래스 생성자 정의: 모델명, 제조사, 종이 잔량을 초기화
    Printer(const string& model, const string& manufacturer, int availableCount);

    // 순수 가상 함수: 인쇄 기능을 상속받은 클래스에서 반드시 구현해야 함
    virtual void print(int pages) = 0;

    // 프린터 상태 출력 함수: 모델명, 제조사, 종이 잔량 출력
    virtual void showStatus() const;
};

class InkjetPrinter : public Printer { // InkjetPrinter 클래스 정의 (Printer 클래스 상속)
private:
    int availableInk; // 잉크 잔량

public:
    // InkjetPrinter 클래스 생성자 정의: 기본 정보와 잉크 잔량 초기화
    InkjetPrinter(const string& model, const string& manufacturer, int availableCount, int availableInk);

    // print 함수 오버라이드: 잉크와 종이를 체크하고 인쇄 수행
    void print(int pages) override;

    // showStatus 함수 오버라이드: 기본 상태에 잉크 잔량도 추가로 출력
    void showStatus() const override;
};

class LaserPrinter : public Printer { // LaserPrinter 클래스 정의 (Printer 클래스 상속)
private:
    int availableToner; // 토너 잔량

public:
    // LaserPrinter 클래스 생성자 정의: 기본 정보와 토너 잔량 초기화
    LaserPrinter(const string& model, const string& manufacturer, int availableCount, int availableToner);

    // print 함수 오버라이드: 토너와 종이를 체크하고 인쇄 수행
    void print(int pages) override;

    // showStatus 함수 오버라이드: 기본 상태에 토너 잔량도 추가로 출력
    void showStatus() const override;
};

#endif // 헤더 가드의 끝: PRINTER_H가 이미 정의되어 있다면 파일을 포함하지 않음
