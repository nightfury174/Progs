/*
 * OpenQuestion.h
 *
 *  Created on: Aug 18, 2015
 *      Author: regismark5
 */

#ifndef OPENQUESTION_H_
#define OPENQUESTION_H_

#include "Question.h"

class OpenQuestion: public Question
{
	int points;
	char* answer;
	void copy(const OpenQuestion&);
public:
	Cloneable* clone() const
	{
		return new OpenQuestion(*this);
	}
	OpenQuestion(const char* _text, int _points);
	OpenQuestion(const OpenQuestion&);
	OpenQuestion& operator=(const OpenQuestion&);
	~OpenQuestion(){delete [] answer;}
	void ask();
	double grade();
};




#endif /* OPENQUESTION_H_ */
