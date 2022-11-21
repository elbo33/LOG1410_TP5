/****************************************************************************
**
** Classe Agenda
** Date: 2022-10-11
** Based on previous material (2021-11-08)
**
****************************************************************************/

#ifndef _Agenda_Header_
#define _Agenda_Header_

#include "AbsDocument.h"

static const std::string descriptionAgenda = "Agenda";

class Agenda : public AbsDocument
{
public:
	Agenda(std::string name, std::string dateTime);

    Agenda(std::string name, std::string dateTime, const char *string, const char *string1, int i, float d);

    virtual ~Agenda() {}
	virtual Agenda* clone(void) const;

	std::string getDescription() const { return descriptionAgenda; }
};

#endif
