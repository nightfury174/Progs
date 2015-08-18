/*
 * MultipleChoice.h
 *
 *  Created on: Aug 17, 2015
 *      Author: regismark5
 */

#ifndef MULTIPLECHOICE_H_
#define MULTIPLECHOICE_H_

#include "Question.h"

class MultipleChoice: public Question
{
	int points;
	char* options;
	char* answers;
	int* uanswers;//user answers
	int number;
	bool isNumber(char);
	bool isCorrect(int);
	void copy(const MultipleChoice&);
	void del();
public:
	Cloneable* clone() const
	{
		return new MultipleChoice(*this);
	}
	MultipleChoice(const char* _text, int _points,const char* _options, const char* _answers);
	MultipleChoice(const MultipleChoice&);
	MultipleChoice& operator=(const MultipleChoice&);
	~MultipleChoice();
	void ask();
	double grade();
};


#endif /* MULTIPLECHOICE_H_ */
