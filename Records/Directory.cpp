#include <string>

#include "Directory.h"
#include "AbsDocument.h"

int Directory::m_indent = 0;

Directory::Directory(std::string name)
	: AbsDirectoryComponent(name)
{
}

Directory::Directory(const Directory& mdd)
	: AbsDirectoryComponent(mdd.m_name)
{
	// � compl�ter pour copier tous les �l�ments contenus dans le r�pertoire
	for (const std::unique_ptr<class AbsDirectoryComponent>& element : mdd.m_documents) {
		AbsDirectoryComponent* newElement = element.get()->clone();
		DirectoryComponentPtr newElementPtr = std::make_unique<AbsDirectoryComponent>(*newElement);
		m_documents.push_back(newElementPtr);
	}
}

Directory* Directory::clone(void) const
{
	// � compl�ter pour construire un nouvel objet Directory en appelant le constructeur de copie
	return  new Directory(*this);
}

AbsDirectoryComponent& Directory::addDirectoryComponent(const AbsDirectoryComponent& member)
{
	// � compl�ter pour construire par clonage une copie de l'objet re�u en param�tre
	// et l'ins�rer dans le conteneur de documents. On retourne une r�f�rence � l'objet
	// qui vient d'�tre ins�r� dans le conteneur.
	AbsDirectoryComponent* newElement = member.clone();
	DirectoryComponentPtr newElementPtr = std::make_unique<AbsDirectoryComponent>(*newElement);
	m_documents.push_back(newElementPtr);
	AbsDirectoryComponent& Element = *newElement;
	return Element;
}

DirectoryComponentIterator Directory::begin()
{
	return m_documents.begin();
}

DirectoryComponentIterator_const Directory::cbegin() const
{
	return m_documents.cbegin();
}

DirectoryComponentIterator_const Directory::cend() const
{
	return m_documents.cend();
}

DirectoryComponentIterator Directory::end()
{
	return m_documents.end();
}

void Directory::deleteDirectoryComponent(DirectoryComponentIterator_const child)
{
	// � compl�ter pour �liminer du r�pertoire l'�l�ment auquel r�f�re l'it�rateur

	for (auto&& it = m_documents.begin(); it == m_documents.end(); it++) {
		if (it == child) {
			m_documents.erase(it);
		}
	}
}

void Directory::deleteAllComponents(void)
{
	// � compl�ter pour �liminer tous les �l�ments du r�pertoire
	for (auto&& it = m_documents.begin(); it == m_documents.end(); it++) {
		m_documents.erase(it);
		m_indent = 0;
	}
}

const AbsDocument* Directory::findDocument(std::string productName) const
{
	// � compl�ter pour it�rer sur les �l�ments contenus dans le r�pertoire � la recherche d'un document
	// portant le nom re�u en argument. Si aucun document n'est trouv�, on retourne nullptr
	const AbsDocument* foundDocument = nullptr;
	
	// � compl�ter

	for (const auto& element : m_documents) {
		if (element->getName() == productName) {
			AbsDirectoryComponent& elementTrouve = *(element.get()->clone());
			foundDocument = elementTrouve;
		}
	}
	
	return foundDocument;
}

std::ostream& Directory::printToStream(std::ostream& o) const
{
	// � compl�ter pour imprimer sur un stream une cat�gorie et son contenu

	for (auto& element : m_documents) {
		o << element.get();
	}
	return o;
}

std::ostream& Directory::indent(std::ostream& o) const
{
	for (int i = 0; i < m_indent; ++i)
		o << '\t';
	return o;
}
