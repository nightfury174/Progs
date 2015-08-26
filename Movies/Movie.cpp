/*
 * Movie.cpp
 *
 *  Created on: Aug 23, 2015
 *      Author: regismark5
 */
#include <iostream>
#include <cstring>

using namespace std;
#include "Movie.h"

void Movie::copy(const Movie& toCopy)
{
	delete[] summary;
	summary=NULL;

	summary=new char[strlen(toCopy.summary+1)];
	strcpy(summary,toCopy.summary);

	rating=toCopy.rating;
	top=toCopy.top;
}

Movie::Movie():summary(NULL),rating(0),top(0){}

Movie::Movie(const char* s,int r,int t)
:summary(NULL), rating(r), top(t)
{
	summary=new char[strlen(s+1)];
	strcpy(summary,s);
}

Movie::Movie(const Movie& toCopy)
:summary(NULL)
{
	copy(toCopy);
}

Movie& Movie::operator=(const Movie& toCopy)
{
	if(this!=&toCopy)
		copy(toCopy);
	return *this;
}

Movie::~Movie()
{
	delete[] summary;
}

void Movie::SetSummary(const char* s)
{
	delete[] summary;
	summary=NULL;

	summary=new char[strlen(s+1)];
	strcpy(summary,s);
}

ostream& operator<<(ostream& os,const Movie& M)
{
	os<<endl<<"Summary: "<<M.getSummary()<<endl;
	os<<"Rating: "<<M.GetRating()<<endl;
	os<<"Top: "<<M.GetTop()<<endl;
	return os;
}

istream& operator>>(istream& is,Movie& M)
{
	char summ[1000];
	int _rating;
	int _top;

	cout<<"Set summary: ";
	cin.ignore();
	cin.getline(summ,1000);
	M.SetSummary(summ);

	cout<<"Set rating: ";
	is>>_rating;
	M.SetRating(_rating);

	cout<<"Set top: ";
	is>>_top;
	M.SetTop(_top);

	cout<<endl;

	return is;
}
