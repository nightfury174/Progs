/*
 * main.cpp
 *
 *  Created on: Aug 23, 2015
 *      Author: regismark5
 */
#include <iostream>

using namespace std;
#include "Movie.h"

class Action: public Movie
{
	int inclass;
public:
	Action(const char* s,int r,int t,int i):Movie(s,r,t),inclass(i){}
	Action(const Action& toCopy):Movie(toCopy),inclass(toCopy.inclass){}
	Action& operator=(const Action& toCopy)
	{
		if(this!=&toCopy)
		{
			Movie::operator=(toCopy);
			inclass=toCopy.inclass;
		}
		return *this;
	}
	int getInClass() const {return inclass;}
	void setInClass(int i) {inclass=i;}
};

class Romance: public Movie
{
	int inclass;
public:
	Romance(const char* s,int r,int t,int i):Movie(s,r,t),inclass(i){}
	Romance(const Romance& toCopy):Movie(toCopy),inclass(toCopy.inclass){}
	Romance& operator=(const Romance& toCopy)
	{
		if(this!=&toCopy)
		{
			Movie::operator=(toCopy);
			inclass=toCopy.inclass;
		}
		return *this;
	}
	int getInClass() const {return inclass;}
	void setInClass(int i) {inclass=i;}
};
class Comedy: public Movie
{
	int inclass;
	public:
	Comedy(const char* s,int r,int t,int i):Movie(s,r,t),inclass(i){}
	Comedy(const Comedy& toCopy):Movie(toCopy),inclass(toCopy.inclass){}
	Comedy& operator=(const Comedy& toCopy)
		{
			if(this!=&toCopy)
			{
				Movie::operator=(toCopy);
				inclass=toCopy.inclass;
			}
			return *this;
		}
	int getInClass() const {return inclass;}
	void setInClass(int i) {inclass=i;}
};
class Mystery: public Movie
{
	int inclass;
	public:
	Mystery(const char* s,int r,int t,int i):Movie(s,r,t),inclass(i){}
	Mystery(const Mystery& toCopy):Movie(toCopy),inclass(toCopy.inclass){}
	Mystery& operator=(const Mystery& toCopy)
		{
			if(this!=&toCopy)
			{
				Movie::operator=(toCopy);
				inclass=toCopy.inclass;
			}
			return *this;
		}
	int getInClass() const {return inclass;}
	void setInClass(int i) {inclass=i;}
};
class Rescue: public Action, public Romance
{
	int inclass;
	public:
	Rescue(const char* s,int r,int t,int i,int ir,int ia)
	:Romance(s,r,t,ir),Action(s,r,t,ia),inclass(i){}
	Rescue(const Rescue& toCopy)
	:Romance(toCopy),Action(toCopy),inclass(toCopy.inclass){}
	Rescue& operator=(const Rescue& toCopy)
		{
			if(this!=&toCopy)
			{
				Romance::operator=(toCopy);
				Action::operator=(toCopy);
				inclass=toCopy.inclass;
			}
			return *this;
		}
	int getInClass() const {return inclass;}
	void setInClass(int i) {inclass=i;}
};
class RomanticComedy: public Romance, public Comedy
{
	int inclass;
	public:
	RomanticComedy(const char* s,int r,int t,int i,int ir,int ic)
	:Romance(s,r,t,ir),Comedy(s,r,t,ic),inclass(i){}
	RomanticComedy(const RomanticComedy& toCopy)
	:Romance(toCopy),Comedy(toCopy),inclass(toCopy.inclass){}
	RomanticComedy& operator=(const RomanticComedy& toCopy)
		{
			if(this!=&toCopy)
			{
				Romance::operator=(toCopy);
				Comedy::operator=(toCopy);
				inclass=toCopy.inclass;
			}
			return *this;
		}
	int getInClass() const {return inclass;}
	void setInClass(int i) {inclass=i;}
};
class HollywoodBlockbuster: public Action, public Romance,
public Comedy, public Mystery
{
	int inclass;
	public:
	HollywoodBlockbuster(const char* s,int r,int t,int i,int ir,int ic,int ia,int im)
	:Romance(s,r,t,ir),Comedy(s,r,t,ic),Action(s,r,t,ia),Mystery(s,r,t,im),inclass(i){}
	HollywoodBlockbuster(const HollywoodBlockbuster& toCopy)
	:Romance(toCopy),Comedy(toCopy),Action(toCopy),Mystery(toCopy),inclass(toCopy.inclass){}
	HollywoodBlockbuster& operator=(const HollywoodBlockbuster& toCopy)
		{
			if(this!=&toCopy)
			{
				Romance::operator=(toCopy);
				Comedy::operator=(toCopy);
				Action::operator=(toCopy);
				Mystery::operator=(toCopy);
				inclass=toCopy.inclass;
			}
			return *this;
		}
	int getInClass() const {return inclass;}
	void setInClass(int i) {inclass=i;}
};

class Person
{
	int rating;
	const Movie* ticket;
public:
	Person():ticket(NULL),rating(0){}
	Person(int r):ticket(NULL),rating(r){}
	Person(const Person& toCopy):rating(toCopy.rating),ticket(toCopy.ticket){}
	Person& operator=(const Person& toCopy)
	{
		if(this!=&toCopy)
		{
			ticket=toCopy.ticket;
			rating=toCopy.rating;
		}
		return *this;
	}
	void setTicket(const Movie& M){ticket=&M;}
	const Movie& getTicket() const {return *ticket;}
	void setRating(int r){rating=r;}
	int getRating() const {return rating;}
};

ostream& operator<<(ostream& os,const Action& A)
{
	os<<(Movie)A;
	os<<"In class: "<<A.getInClass();
	return os;
}

int main(){

	int n,m,rating,inclass,type;

	cout<<"Enter number of movies: ";
	cin>>n;
	Movie** book;
	book=new Movie*[n];

	for(int i=0;i<n;i++)
	{
		cout<<"Enter the type of the movie: ";
		cin>>type;

		cout<<"Enter movie "<<i<<":"<<endl;
		book[i]=new Movie;
		cin>>*book[i];

		cout<<"Enter inclass rating: ";
		cin>>inclass;
		switch (type)
			{
			case 1:
				{
					book[i]=new Action(book[i]->getSummary(),book[i]->GetRating(),
							book[i]->GetTop(),inclass);
				}
			}
	}

	for(int i=0;i<n;i++)
	{
		cout<<*book[i];
		cout<<"In class: "<<book[i]->getInClass()<<endl;
	}

	cout<<endl<<"Enter number of friends: ";
	cin>>m;
	Person friends[m];

	for(int i=0;i<m;i++)
	{
		cout<<"Set rating for friend "<<i<<" :";
		cin>>rating;
		friends[i].setRating(rating);
		cout<<endl;
	}


	cout<<endl<<"No error."<<endl;
	return 0;
}

