/*
 * Questionnaire.h
 *
 *  Created on: Aug 18, 2015
 *      Author: regismark5
 */

#ifndef QUESTIONNAIRE_H_
#define QUESTIONNAIRE_H_
#include "Question.h"

class Test: public Question
{
	Question** test;
	int size;
	int cap;
	void copy(const Test&);
	void del();
	void recize();
public:
	Cloneable* clone() const
	{
		return new Test(*this);
	}
	Test();
	Test(const Test&);
	Test& operator=(const Test&);
	~Test();
	void addQuestion(Question&);
	void ask();
	double grade();
	void doTest();
	double gradeTest();
	void print_Questions();
};




#endif /* QUESTIONNAIRE_H_ */
