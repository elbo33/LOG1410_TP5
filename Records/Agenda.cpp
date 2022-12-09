#include <string>
#include <utility>

#include "Agenda.h"
#include "AddAnnotationVisitor.h"


Agenda::Agenda(std::string name, std::string dateTime)
	: AbsDocument(std::move(name), std::move(dateTime))
{
}

Agenda* Agenda::clone(void) const
{
	// � compl�ter pour construire un nouvel objet Agenda en appelant le constructeur de copie
	
	return new Agenda(*this); // � remplacer
}

AbsDirectoryComponent& Agenda::accept(AddAnnotationVisitor& v) const
{
	
	
	return v.processAgenda(*this->clone());
}
