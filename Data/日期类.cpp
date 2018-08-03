#define _CRT_SECURE_NO_WARNINGS 
#include<iostream>
using namespace std;
#include<stdio.h>
class Date
{
public:
	friend ostream& operator <<(ostream&count, const Date & d);//声明友元函数
	Date(int year = 2018, int month = 6, int day = 10)//构造函数
		: _year(year)
		, _month(month)
		, _day(day)
	{}

	Date(const Date& d)//拷贝构造函数
		: _year(d._year)
		, _month(d._month)
		, _day(d._day)
	{}
	
	//判断是否是闰年
	int Is_leap(int year){
		if ((year % 4 == 0 && year % 100 != 0) || (year % 400 == 0)){
			return 1;
		}
		return 0;
	}
	//获取每个月有多少天
	int get_days(int year,int mounth){
		int array[] = { 0,31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31 };
		if (Is_leap(year)&&mounth==2){
			return 29;
		}
		return array[mounth];
	}
	// 当前日期days天后是什么日期？d1+99 
	Date operator+(int days){
		_day += days;
		while(_day > get_days(_year, _month)){
			_day -= get_days(_year, _month);
			_month += 1;
			if (_month > 12){
				_year += 1;
				_month = 1;
			}
		}
		return *this;
	}

	// 当前日期days天前是什么日期？ d1-99
	Date operator-(int days){
		_day -= days;
		while (_day <0){
			_month -= 1;
			if (_month <1){
				_year -= 1;
				_month = 12;
			}
			_day += get_days(_year, _month);
		}
		return *this;
	}

	// 两个日期之间差了多少天？ 
	Date operator-(const Date& d){
		Date minData(*this);
		Date maxData(d);
		int count = 0;
		if (minData>maxData){
			minData = d;
			maxData = *this;
		}
		while (minData != maxData){
			count++;
			minData+1;
		}
		return count;
	}

	// 日期比大小 
	bool operator>(const Date& d){
		if ((_year > d._year) ||(_year == d._year&&_month>d._month) ||
			(_year== d._year&&_month==d._month&&_day>d._day)){
			return 1;
		}
		return 0;
	}
	bool operator<(const Date& d){
		if ((_year > d._year) || (_year == d._year&&_month>d._month) ||
			(_year == d._year&&_month == d._month&&_day>d._day)){
			return 0;
		}
		return 1;
	}
	bool operator==(const Date& d){
		if (_year == d._year&&_month == d._month&&_day==d._day){
			return 1;
		}
		return 0;
	}
	bool operator!=(const Date& d){
		return !(*this == d);
	}
	Date& operator=(const Date& d){//重载赋值运算符
		if (this != &d){
			_year = d._year;
			_month = d._month;
			_day = d._day;
		}
		return *this;
	}

	// 重载取地址符号 
	Date* operator&(){
		return this;
	}

	// 前置++ 
	Date& operator++(){
		_day += 1;
		return *this;
	}

	// 后置++ 
	Date operator++(int){
		Date temp(*this);
		_day++;
		return temp;
	}

	// 前置-- 
	Date& operator--(){
		_day -= 1;
		return *this;
	}

	// 后置++ 
	Date operator--(int){
		Date temp(*this);
		_day--;
		return temp;
	}
private:
	int _year;
	int _month;
	int _day;
};
ostream& operator <<(ostream&_count, const Date & d){//重载<<
	_count << d._year << "/" << d._month << "/" << d._day;
	return _count;
}
int main(){
	Date d1;
	Date d2(2018,7,10);
	//d1 = d2;
	//cout << d2-d1<<endl;
	printf("%d",d2 - d1);
	system("pause");

}