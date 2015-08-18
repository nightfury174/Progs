/*
 * main.cpp
 *
 *  Created on: Jun 24, 2015
 *      Author: regismark5
 */
#include <iostream>

using namespace std;
#include "Question.h"
#include "YesNoQuestion.h"
#include "MultipleChoice.h"
#include "OpenQuestion.h"
#include "Questionnaire.h"

int main(){
	YesNoQuestion Q1("Is it you?",100,'Y');

	MultipleChoice Q2("Which is true? 1:All lions drink coffee."
			" 2:WoW is the biggest MMO. 3:All snakes lay eggs."
			" 4:RAM means Random-access memory.",5,"1,2,3,4","2,4");

	OpenQuestion Q3("Wazaaaaaaaaaaaa",100);

	Test T;
	T.addQuestion(Q1);
	T.addQuestion(Q2);
	T.addQuestion(Q3);

	//T.print_Questions();

	T.doTest();

	cout<<T.gradeTest()<<endl;

	cout<<endl<<"No error."<<endl;
	return 0;
}




