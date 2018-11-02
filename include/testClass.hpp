#ifndef TESTCLASS_H
#define TESTCLASS_H

#include <string>
#include <glm/glm.hpp>

class TestClass{
	public:
		TestClass(const std::string& n, const glm::vec3& v);
		std::string& getName();
	private:
		std::string name;
		glm::vec3 pos;
};

#endif
