#include <iostream>
#include <string>
using namespace std;

#include "AirlineBook.h"
#include "Schedule.h"
#include "Console.h"

// 생성자
AirlineBook::AirlineBook(string name, int nSchedules, string scheduleTime[]){
	this->name = name; // 예약 시스템 이름
	this->nSchedules = nSchedules;
	sche = new Schedule[nSchedules]; // 3 개의 스케쥴 객체 생성

	// 각 스케쥴에 해당 시간 설정
	for(int i=0; i<nSchedules; i++)
		sche[i].setTime(scheduleTime[i]);
}

// 소멸자
AirlineBook::~AirlineBook(){
	if(sche) 
		delete [] sche;
}

// 예약 시스템을 시작하는 함수
void AirlineBook::run(){
	cout << "***** 한성항공에 오신것을 환영합니다 *****" << endl;
    while (true) {
			showMenu();
			switch (menu) {
			case 1:
				reservation(); break;
			case 2:
				cancle(); break;
			case 3:
				show(); break;
			case 4:
				return;
			}
		}



}

// 스케쥴을 예약한다.
void AirlineBook::book(){
	


/*필요한 코드를 작성하시오.*/



}

// 스케쥴을 취소한다.
void AirlineBook::cancel(){
	


/*필요한 코드를 작성하시오.*/



}

// 현재 모든 스케쥴의 예약 상황을 출력한다.
void AirlineBook::view(){
	for(int i=0;i<3;i++){
		sche[i].view();
	}
}

// 스케쥴 s의 좌석 예약 상황을 출력한다. s는 1,2,3
void AirlineBook::view(int s){
	sche[s-1].view(); //배열의 인덱스는 0부터 시작
}