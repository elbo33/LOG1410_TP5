 ///////////////////////////////////////////////////////////
//  Instance.cpp
//  Implementation of the Class Instance
//  Created on:      2022-10-14
//  Based on previous material (2022-03-19)
///////////////////////////////////////////////////////////

#include "Instance.h"

#include <utility>
#include "Directory.h"
#include "AbsInstanceVisitor.h"

Instance::Instance(std::string name)
    : AbsInstanceComponent(std::move(name))
{
}

Instance::Instance(const Instance& mdd)
	: AbsInstanceComponent(mdd.getName())
{
	// � compl�ter pour copier toutes les instances de niveau inf�rieur contenues dans l'instance}
	for (const std::unique_ptr<class AbsInstanceComponent>& element : mdd.m_instanceContainer) {
		AbsInstanceComponent* newElement = element->clone();
		InstanceComponentPtr newElementPtr = std::unique_ptr<AbsInstanceComponent>(newElement);
        m_instanceContainer.push_back(std::move(newElementPtr));
	}

}

Instance* Instance::clone() const
{
	// � compl�ter pour construire un nouvel objet Instance en appelant le constructeur de copie
	return new Instance(*this); // � remplacer
}

void Instance::accept(AbsInstanceVisitor& v)

{
	v.processInstance(*this->clone());
};


InstanceComponentIterator Instance::begin() {

	return m_instanceContainer.begin();
}


InstanceComponentIterator_const Instance::cbegin() const {

	return m_instanceContainer.cbegin();
}


InstanceComponentIterator_const Instance::cend() const
{
	return m_instanceContainer.cend();
}

InstanceComponentIterator Instance::end()
{
	return  m_instanceContainer.end();
}

AbsInstanceComponent& Instance::addInstanceComponent(const AbsInstanceComponent& member)
{
	// � compl�ter pour construire par clonage une copie de l'objet re�u en param�tre
	// et l'ins�rer dans le conteneur des instances. On retourne une r�f�rence � l'objet
	// qui vient d'�tre ins�r� dans le conteneur.

	AbsInstanceComponent* newElement = member.clone();
	InstanceComponentPtr newElementPtr = std::unique_ptr<AbsInstanceComponent>(newElement);
	m_instanceContainer.push_back(std::move(newElementPtr));
	AbsInstanceComponent& Element = *newElement;
	return Element;
}

void Instance::deleteInstanceComponent(InstanceComponentIterator_const child)
{
	// � compl�ter pour �liminer des instances l'�l�ment auquel r�f�re l'it�rateur

	for (auto&& it = m_instanceContainer.begin(); it == m_instanceContainer.end(); it++) {
		if (it == child) {
			m_instanceContainer.erase(it);
		}
	}
}

void Instance::deleteAllComponents(void)
{
	// � compl�ter pour �liminer tous les �l�ments de l'instance
	for (auto&& it = m_instanceContainer.begin(); it == m_instanceContainer.end(); it++) {
		m_instanceContainer.erase(it);
		m_indent = 0;
	}
}

std::ostream& Instance::printToStream(std::ostream& o) const
{
    o << this->getName() << std::endl;
    int i(1);
    for(auto& element : m_instanceContainer) {
        auto* artifactPtr = dynamic_cast<Artifact*>(element.get());
        auto* instancePtr = dynamic_cast<Instance*>(element.get());

        m_indent++;
        if(artifactPtr != nullptr) {
            indent(o);
            o << i << " Artifact: " << artifactPtr->getName() << std::endl;
            indent(o);
            o << "    --> Document: " << artifactPtr->getDocument().getName() << std::endl;

        } else if(instancePtr != nullptr) {
            indent(o);
            o << i << " ";
            instancePtr->printToStream(o);
        }
        m_indent--;
        i++;
    }



	return o;
}

