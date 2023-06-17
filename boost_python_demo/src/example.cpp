#include <boost/python.hpp>

int add(int a, int b) {
    return a + b;
}

BOOST_PYTHON_MODULE(example_module) {
    boost::python::def("add", add);
}