#include <string>

#include "Minutes.h"

Minutes::Minutes(std::string name, std::string dateTime)
	: AbsDocument(name, dateTime)
{
}

Minutes* Minutes::clone(void) const
{
	// À compléter pour construire un nouvel objet Minutes en appelant le constructeur de copie
	return new Minutes(*this); // À remplacer
}