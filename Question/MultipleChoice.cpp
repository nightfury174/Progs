/*
 * MultipleChoice.cpp
 *
 *  Created on: Aug 17, 2015
 *      Author: regismark5
 */
#include <iostream>
#include <cstring>
using namespace std;

#include "MultipleChoice.h"

void MultipleChoice::copy(const MultipleChoice& toCopy)
{
	del();
	setText(toCopy.getText());
	number=toCopy.number;
	points=toCopy.points;
	options=new char[strlen(toCopy.options)+1];
	strcpy(options,toCopy.options);
	answers=new char[strlen(toCopy.answers)+1];
	strcpy(answers,toCopy.answers);
}

void MultipleChoice::del()
{
	delete[] options;
	delete[] answers;
	delete[] uanswers;
	options=NULL;
	answers=NULL;
	uanswers=NULL;
}
MultipleChoice::MultipleChoice(const char* _text, int _points,const char* _options, const char* _answers)
:Question(_text), points(_points), options(NULL),
 answers(NULL), uanswers(NULL), number(0)
{
	options=new char[strlen(_options)+1];
	strcpy(options,_options);
	answers=new char[strlen(_answers)+1];
	strcpy(answers,_answers);
}

MultipleChoice::MultipleChoice(const MultipleChoice& toCopy)
{
	copy(toCopy);
}

MultipleChoice& MultipleChoice::operator=(const MultipleChoice& toCopy)
{
	if(this!=&toCopy)
	{
		copy(toCopy);
	}
	return *this;
}

MultipleChoice::~MultipleChoice()
{
	del();
}

bool MultipleChoice::isNumber(char c)
{
	if(c>=48 && c<=57)
		return true;
	return false;
}

bool MultipleChoice::isCorrect(int num)
{
	int copy_num=0;

	for(int i=0;i<strlen(answers);i++)
	{
		if(isNumber(answers[i]))
		{
			copy_num*=10;
			copy_num+=(answers[i]-48);
		}
		if(answers[i]==' ' || answers[i]==',')
		{
			if(copy_num==num)
				return true;
			else
				copy_num=0;
		}
	}
	if(copy_num==num)
		return true;

	return false;
}

void MultipleChoice::ask()
{
	cout<<getText()<<endl;
	for(int i=0; i<strlen(options);i++)
	{
		if(options[i]==' ' || options[i]==',')
		{
			number++;
		}
		else
		{
			if(!isNumber(options[i]))
			{
				cout<<"The options must be only the numbers of the answers."<<endl;
				throw;
			}
		}
	}
	number++;

	uanswers=new int[number];

	cout<<"Enter the numbers of the correct answers separated with space, others mark with 0."<<endl;
	for(int i=0;i<number;i++)
	{
		cin>>uanswers[i];
	}
}

double MultipleChoice::grade()
{
	int sum=0;

	for(int i=0;i<number;i++)
	{
		if(isCorrect(uanswers[i]))
			sum+=points;
		else
		{
			if(uanswers[i]!=0)
				sum-=points;
		}
	}

	return sum;
}

