/* #include <boost/python.hpp>
#include <boost/archive/binary_iarchive.hpp>
#include <boost/serialization/vector.hpp>
#include <vector>
#include <cstdint>

boost::python::object deserializeVector(const std::vector<uint8_t>& message)
{
    // Convert the vector to a string
    std::string strData(message.begin(), message.end());

    // Deserialize the string using boost_iarchive
    std::istringstream iss(strData);
    boost::archive::binary_iarchive ia(iss);

    // Deserialize the vector
    std::vector<int> data;
    ia >> data;

    // Convert the deserialized vector to a Python list
    boost::python::list pyList;
    for (const auto& value : data) {
        pyList.append(value);
    }

    // Return the Python list
    return pyList;
}

BOOST_PYTHON_MODULE(example_module)
{
    using namespace boost::python;
    def("deserializeVector", deserializeVector);
} */


#include <boost/python.hpp>

int add(int a, int b) {
    return a + b;
}

BOOST_PYTHON_MODULE(example_module) {
    boost::python::def("add", add);
}
