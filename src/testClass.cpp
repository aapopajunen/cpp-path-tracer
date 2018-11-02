#include "testClass.hpp"

TestClass::TestClass(const std::string& n, const glm::vec3& v){
    name = n;
    pos = v;
};

std::string& TestClass::getName(){
    return name;
}
