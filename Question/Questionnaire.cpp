/*
 * Questionnaire.cpp
 *
 *  Created on: Aug 18, 2015
 *      Author: regismark5
 */
#include <iostream>

using namespace std;
#include "Questionnaire.h"

void Test::copy(const Test& toCopy)
{
	del();
	size=toCopy.size;
	cap=toCopy.cap;
	test=new Question*[cap];
	for(int i=0;i<size;i++)
		test[i]= (Question*)toCopy.test[i]->clone();
}

void Test::del()
{
	//for(int i=0;i<size;i++)
		//delete test[i];
	delete[] test;
	test=NULL;
}

void Test::recize()
{
	cap*=2;

	Question** test2;

	test2=new Question*[cap];
	for(int i=0;i<size;i++)
		test2[i]=test[i];

	del();
	test=test2;
}

Test::Test()
:size(0),cap(2),test(NULL)
{
	test=new Question*[size];
}

Test::Test(const Test& toCopy)
:test(NULL)
{
	copy(toCopy);
}

Test& Test::operator=(const Test& toCopy)
{
	if(this!=&toCopy)
		copy(toCopy);
	return *this;
}

Test::~Test()
{
	del();
}

void Test::addQuestion(Question& toPush)
{
	if(size==cap)
		recize();
	test[size]=&toPush;
	//test[size]=(Question*)toPush.clone();
	size++;
}

void Test::ask()
{
	for(int i=0;i<size;i++)
	{
		test[i]->ask();
	}
}

double Test::grade()
{
	double sum=0;

	for(int i=0;i<size;i++)
	{
		cout<<"Grading question "<<i+1<<":"<<endl;
		sum+=test[i]->grade();
	}

	return sum;
}

void Test::doTest()
{
	ask();
}

double Test::gradeTest()
{
	return grade();
}

void Test::print_Questions()
{
	for(int i=0;i<size;i++)
		cout<<"Question "<<i+1<<": "<<endl<<test[i]->getText()<<endl;
}


