/*
 * Question.cpp
 *
 *  Created on: Jun 23, 2015
 *      Author: regismark5
 */
#include <iostream>
#include <cstring>
using namespace std;

#include "Question.h"

Question::Question(const char* _text):text(NULL)
{
	setText(_text);
}

Question::Question(const Question& Q):text(NULL)
{
	setText(Q.text);
}

Question& Question::operator=(const Question& Q)
{
	if(this!=&Q)
		setText(Q.text);
	return *this;
}

Question::~Question()
{
	delete[] text;
}

void Question::setText(const char* _text)
{
	delete[] text;
	text=NULL;
	text=new char[strlen(_text)+1];
	strcpy(text,_text);
}

