/*
 * OpenQuestion.cpp
 *
 *  Created on: Aug 18, 2015
 *      Author: regismark5
 */
#include "OpenQuestion.h"
#include <iostream>

using namespace std;
#include <cstring>

void OpenQuestion::copy(const OpenQuestion& toCopy)
{
	setText(toCopy.getText());
	points=toCopy.points;
}

OpenQuestion::OpenQuestion(const char* _text, int _points)
:Question(_text), points(_points), answer(NULL){}

OpenQuestion::OpenQuestion(const OpenQuestion& toCopy)
{
	copy(toCopy);
}

OpenQuestion& OpenQuestion::operator=(const OpenQuestion& toCopy)
{
	if(this!=&toCopy)
		copy(toCopy);
	return *this;
}

void OpenQuestion::ask()
{
	cout<<getText()<<endl;


	answer=new char[1000];
	cin.ignore();

	cout<<"Answer:"<<endl;

	cin.getline(answer,1000);
}

double OpenQuestion::grade()
{
	cout<<"Text: "<<getText()<<endl;
	cout<<"Answer: "<<answer<<endl;

	int percentage;
	double res;

	if(strlen(answer)==0)
		return 0;
	else
		cin>>percentage;

	res=percentage*points/100;

	return res;
}
