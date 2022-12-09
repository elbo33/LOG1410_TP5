// GenericDocument.cpp : À COMPLÉTER

#include "GenericDocument.h"
#include "AddAnnotationVisitor.h"

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

AbsDirectoryComponent& GenericDocument::accept(AddAnnotationVisitor& v) const
{
	// TODO: insérer une instruction return ici
	return v.processGenericDocument(*this->clone());
};




