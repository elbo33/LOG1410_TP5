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
	// À compléter pour copier tous les éléments contenus dans le répertoire
	for (const std::unique_ptr<class AbsDirectoryComponent>& element : mdd.m_documents) {
		AbsDirectoryComponent* newElement = element.get()->clone();
		DirectoryComponentPtr newElementPtr = std::make_unique<AbsDirectoryComponent>(*newElement);
		m_documents.push_back(newElementPtr);
	}
}

Directory* Directory::clone(void) const
{
	// À compléter pour construire un nouvel objet Directory en appelant le constructeur de copie
	return  new Directory(*this);
}

AbsDirectoryComponent& Directory::addDirectoryComponent(const AbsDirectoryComponent& member)
{
	// À compléter pour construire par clonage une copie de l'objet reçu en paramètre
	// et l'insérer dans le conteneur de documents. On retourne une référence à l'objet
	// qui vient d'être inséré dans le conteneur.
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
	// À compléter pour éliminer du répertoire l'élément auquel réfère l'itérateur

	for (auto&& it = m_documents.begin(); it == m_documents.end(); it++) {
		if (it == child) {
			m_documents.erase(it);
		}
	}
}

void Directory::deleteAllComponents(void)
{
	// À compléter pour éliminer tous les éléments du répertoire
	for (auto&& it = m_documents.begin(); it == m_documents.end(); it++) {
		m_documents.erase(it);
		m_indent = 0;
	}
}

const AbsDocument* Directory::findDocument(std::string productName) const
{
	// À compléter pour itérer sur les éléments contenus dans le répertoire à la recherche d'un document
	// portant le nom reçu en argument. Si aucun document n'est trouvé, on retourne nullptr
	const AbsDocument* foundDocument = nullptr;
	
	// À compléter

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
	// À compléter pour imprimer sur un stream une catégorie et son contenu

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
