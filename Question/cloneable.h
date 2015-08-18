/*
 * cloneable.h
 *
 *  Created on: Jun 23, 2015
 *      Author: regismark5
 */

#ifndef CLONEABLE_H_
#define CLONEABLE_H_

class Cloneable {
public:
	virtual Cloneable* clone() const = 0;
	virtual ~Cloneable() {}
};

#endif /* CLONEABLE_H_ */
