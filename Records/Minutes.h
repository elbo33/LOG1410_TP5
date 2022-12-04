/****************************************************************************
**
** Classe Minutes
** Date: 2022-10-11
** Based on previous material (2021-11-08)
**
****************************************************************************/

#ifndef _Minutes_Header_
#define _Minutes_Header_

#include "AbsDocument.h"

static const std::string descriptionMinutes = "Minutes";

class Minutes : public AbsDocument
{
public:
	Minutes(std::string name, std::string dateTime);

    Minutes(std::string name, std::string dateTime, const char *string, const char *string1, int i, float d);

    virtual ~Minutes() {}
	virtual Minutes* clone(void) const;

	std::string getDescription() const { return descriptionMinutes; }
};

#endif
