// GenericDocument.cpp : À COMPLÉTER

#include "GenericDocument.h"

#include <utility>

GenericDocument::GenericDocument(std::string name, std::string dateTime, std::string description)
	:AbsDocument(std::move(name), std::move(dateTime)), m_description(std::move(description))
{
}

GenericDocument* GenericDocument::clone() const
{
	// À compléter pour construire un nouvel objet Artifact en appelant le constructeur de copie
	return new GenericDocument(*this); // À remplacer
}

GenericDocument::GenericDocument(std::string name, std::string dateTime) : AbsDocument(std::move(name), std::move(dateTime)) {
}



