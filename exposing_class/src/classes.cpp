#include <iostream>

#include <boost/python.hpp>

#include "classes.h"

namespace python = boost::python;

void RealWorld::Welcome()
{
    std::cout << "Welcome to real world" << std::endl;
}

int RealWorld::GetAge()
{
    return age;
}

void RealWorld::SetAge(int value)
{
    age = value;
}

std::string RealWorld::GetName()
{
    return name;
}

char RealWorld::GetSex()
{
    return sex;
}

// 转换成classes module
BOOST_PYTHON_MODULE(classes)
{
    python::class_<RealWorld> ("RealWorld", python::init<std::string, char>())
        // Expose functions
        .def ("Welcome", &RealWorld::Welcome)
        .def ("GetAge", &RealWorld::GetAge)
        .def ("SetAge", &RealWorld::SetAge, python::args("value"))
        .def ("GetName", &RealWorld::GetName)
        .def ("GetSex", &RealWorld::GetSex)

        // Expose member
        .def_readwrite("name", &RealWorld::name)
        .add_property("age", &RealWorld::GetAge, &RealWorld::SetAge)
        .add_property("sex", &RealWorld::GetSex)
    ;
}
