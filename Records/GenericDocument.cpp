// GenericDocument.cpp : � COMPL�TER

#include "GenericDocument.h"

GenericDocument::GenericDocument(std::string name, std::string dateTime, std::string description)
	:AbsDocument(name, dateTime), m_description(description)
{
}

GenericDocument* GenericDocument::clone() const
{
	// � compl�ter pour construire un nouvel objet Artifact en appelant le constructeur de copie
	return new GenericDocument(*this); // � remplacer
}

GenericDocument::GenericDocument(std::string name, std::string dateTime, const char *string, const char *string1,
                                 int i, float d) : AbsDocument(std::move(name), std::move(dateTime)) {
    // TODO implement GenericDocument constructor
}



