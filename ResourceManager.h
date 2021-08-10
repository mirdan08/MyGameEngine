#pragma once
#ifndef RESOURCEMANAGER_H
#define RESOURCEMANAGER_H

#include <Map>
#include <string>

template <class T>
class ResourceManager {
public:
	T& getResource(const std::string& name) {
		if (m_Resources.find(name) == m_Resources.end()) {
			T resource;
			resource.loadFromFile(name);
			m_Resources[name] = resource;
		}
		return m_Resources[name];
	};
private:
	std::map<std::string, T> m_Resources;
};

#endif