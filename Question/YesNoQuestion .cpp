/*
 * YesNoQuestion .cpp
 *
 *  Created on: Jun 23, 2015
 *      Author: regismark5
 */
#include <iostream>

using namespace std;

#include "YesNoQuestion.h"

YesNoQuestion::YesNoQuestion(const char* _text,int _points, char _answer)
:Question(_text),points(_points),answer(_answer),uanswer('0'){}

YesNoQuestion::YesNoQuestion(const YesNoQuestion& toCopy)
:Question(toCopy),points(toCopy.points),
 answer(toCopy.answer),uanswer(toCopy.uanswer){}

YesNoQuestion& YesNoQuestion::operator=(const YesNoQuestion& toCopy)
{
	if(this!=&toCopy)
	{
		setText(toCopy.getText());
		points=toCopy.points;
		answer=toCopy.answer;
		uanswer=toCopy.uanswer;
	}
	return *this;
}

void YesNoQuestion::ask()
{
	cout<<getText()<<endl;
	cout<<"Please answer with 'Y' or 'N', as 'Yes' or 'No'."<<endl;
	cin>>uanswer;
}

double YesNoQuestion::grade()
{
	if(uanswer==answer || answer=='0')
		return points;
	return 0;
}

