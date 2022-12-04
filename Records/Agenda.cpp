#include <string>
#include <utility>

#include "Agenda.h"

Agenda::Agenda(std::string name, std::string dateTime)
	: AbsDocument(std::move(name), std::move(dateTime))
{
}

Agenda* Agenda::clone(void) const
{
	// À compléter pour construire un nouvel objet Agenda en appelant le constructeur de copie
	
	return new Agenda(*this); // À remplacer
}
