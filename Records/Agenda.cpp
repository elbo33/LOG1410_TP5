#include <string>
#include <utility>

#include "Agenda.h"

Agenda::Agenda(std::string name, std::string dateTime)
	: AbsDocument(std::move(name), std::move(dateTime))
{
}

Agenda* Agenda::clone(void) const
{
	// � compl�ter pour construire un nouvel objet Agenda en appelant le constructeur de copie
	
	return new Agenda(*this); // � remplacer
}

Agenda::Agenda(std::string name, std::string dateTime, const char *agendaName, const char *string1, int i, float d)
        : AbsDocument(std::move(name), std::move(dateTime)) {
}
