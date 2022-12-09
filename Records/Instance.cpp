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
	// À compléter pour copier toutes les instances de niveau inférieur contenues dans l'instance}
	for (const std::unique_ptr<class AbsInstanceComponent>& element : mdd.m_instanceContainer) {
		AbsInstanceComponent* newElement = element->clone();
		InstanceComponentPtr newElementPtr = std::unique_ptr<AbsInstanceComponent>(newElement);
        m_instanceContainer.push_back(std::move(newElementPtr));
	}

}

Instance* Instance::clone() const
{
	// À compléter pour construire un nouvel objet Instance en appelant le constructeur de copie
	return new Instance(*this); // À remplacer
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
	// À compléter pour construire par clonage une copie de l'objet reçu en paramètre
	// et l'insérer dans le conteneur des instances. On retourne une référence à l'objet
	// qui vient d'être inséré dans le conteneur.

	AbsInstanceComponent* newElement = member.clone();
	InstanceComponentPtr newElementPtr = std::unique_ptr<AbsInstanceComponent>(newElement);
	m_instanceContainer.push_back(std::move(newElementPtr));
	AbsInstanceComponent& Element = *newElement;
	return Element;
}

void Instance::deleteInstanceComponent(InstanceComponentIterator_const child)
{
	// À compléter pour éliminer des instances l'élément auquel réfère l'itérateur

	for (auto&& it = m_instanceContainer.begin(); it == m_instanceContainer.end(); it++) {
		if (it == child) {
			m_instanceContainer.erase(it);
		}
	}
}

void Instance::deleteAllComponents(void)
{
	// À compléter pour éliminer tous les éléments de l'instance
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

