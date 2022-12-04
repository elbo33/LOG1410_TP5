#include <string>
#include <utility>

#include "Minutes.h"

Minutes::Minutes(std::string name, std::string dateTime)
	: AbsDocument(std::move(name), std::move(dateTime))
{
}

Minutes* Minutes::clone(void) const
{
	// � compl�ter pour construire un nouvel objet Minutes en appelant le constructeur de copie
	return new Minutes(*this); // � remplacer
}