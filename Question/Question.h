/*
 * Question.h
 *
 *  Created on: Jun 23, 2015
 *      Author: regismark5
 */

#ifndef QUESTION_H_
#define QUESTION_H_
#include "cloneable.h"

class Question: public Cloneable
{
	char* text;
public:
	Question(const char* _text="<no text>");
	Question(const Question&);
	Question& operator=(const Question&);
	virtual ~Question();
	void setText(const char*);
	const char* getText()const{return text;}
	virtual void ask() = 0;
	virtual double grade() = 0;
};




#endif /* QUESTION_H_ */
