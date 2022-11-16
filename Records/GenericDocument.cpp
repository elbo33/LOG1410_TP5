// GenericDocument.cpp : À COMPLÉTER

#include "GenericDocument.h"

GenericDocument::GenericDocument(std::string name, std::string dateTime, std::string description)
	:AbsDocument(name, dateTime), m_description(description)
{
}

GenericDocument* GenericDocument::clone() const
{
	// À compléter pour construire un nouvel objet Artifact en appelant le constructeur de copie
	return new GenericDocument(*this); // À remplacer
}

std::string GenericDocument::getDescription() const
{
	return m_description; 
}



