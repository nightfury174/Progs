/*
 * YesNoQuestion.h
 *
 *  Created on: Jun 23, 2015
 *      Author: regismark5
 */

#ifndef YESNOQUESTION_H_
#define YESNOQUESTION_H_
#include "Question.h"

class YesNoQuestion: public Question
{
	int points;
	char answer;// Y or N, as Yes or No
	char uanswer;//user answer
public:
	Cloneable* clone() const
	{
		return new YesNoQuestion(*this);
	}
	YesNoQuestion(const char* _text,int _points=0, char _answer='0');
	YesNoQuestion(const YesNoQuestion&);
	YesNoQuestion& operator=(const YesNoQuestion&);
	~YesNoQuestion(){}
	void setAnswer(const char){cin>>answer;}
	void setPoints(const int){cin>>points;}
	void ask();
	double grade();
};



#endif /* YESNOQUESTION_H_ */
