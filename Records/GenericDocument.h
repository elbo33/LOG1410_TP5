/****************************************************************************
**
** Classe GenericDocument
** Date: 2022-10-11
** Based on previous material (2021-11-08)
**
****************************************************************************/

#ifndef _GenericDocument_Header_
#define _GenericDocument_Header_

#include "AbsDocument.h"

class GenericDocument : public AbsDocument
{
public:
	GenericDocument(std::string name, std::string dateTime, std::string description);

    GenericDocument(std::string name, std::string dateTime, const char *string, const char *string1,
                    int i, float d);

    virtual ~GenericDocument() {}
	virtual GenericDocument* clone(void) const;

	std::string getDescription() const { return m_description; }

private:
	std::string m_description;
};

#endif
