/*
 * Movie.h
 *
 *  Created on: Aug 23, 2015
 *      Author: regismark5
 */
#include <iostream>

using namespace std;

#ifndef MOVIE_H_
#define MOVIE_H_

class Movie
{
	char* summary;
	int rating;
	int top;
	void copy(const Movie&);
public:
	Movie();
	Movie(const char*,int,int);
	Movie(const Movie&);
	Movie& operator=(const Movie&);
	virtual~Movie();
	const char* getSummary() const {return summary;}
	int GetRating() const {return rating;}
	int GetTop() const {return top;}
	void SetSummary(const char*);
	void SetRating(int r){rating=r;}
	void SetTop(int t){top=t;}
	int getInClass() const;
};
ostream& operator<<(ostream& os,const Movie&);
istream& operator>>(istream& is,Movie&);




#endif /* MOVIE_H_ */
