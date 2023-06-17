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


/* 
void fromBinMsg(const autoware_auto_mapping_msgs::msg::HADMapBin & msg, lanelet::LaneletMapPtr map)
{
  if (!map) {
    std::cerr << __FUNCTION__ << ": map is null pointer!";
    return;
  }

  std::string data_str;
  data_str.assign(msg.data.begin(), msg.data.end());

  std::stringstream ss;
  ss << data_str;
  boost::archive::binary_iarchive oa(ss);
  oa >> *map;
  lanelet::Id id_counter = 0;
  oa >> id_counter;
  lanelet::utils::registerId(id_counter);
  // *map = std::move(laneletMap);
}
 */