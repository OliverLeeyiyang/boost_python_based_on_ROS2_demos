#include <boost/python.hpp>
#include <boost/archive/binary_iarchive.hpp>
#include <lanelet2_io/Io.h>
#include "converter.h"

namespace py = boost::python;
using namespace lanelet;

struct DictToConfigurationConverter {
  DictToConfigurationConverter() { py::converter::registry::push_back(&convertible, &construct, py::type_id<io::Configuration>()); }
  static void* convertible(PyObject* obj) {
    if (!PyDict_CheckExact(obj)) {  // NOLINT
      return nullptr;
    }
    return obj;
  }
  static void construct(PyObject* obj, py::converter::rvalue_from_python_stage1_data* data) {
    py::dict d(py::borrowed(obj));
    py::list keys = d.keys();
    py::list values = d.values();
    io::Configuration attributes;
    for (auto i = 0u; i < py::len(keys); ++i) {
      std::string key = py::extract<std::string>(keys[i]);
      std::string value = py::extract<std::string>(values[i]);
      attributes.insert(std::make_pair(key, value));
    }
    using StorageType = py::converter::rvalue_from_python_storage<io::Configuration>;
    void* storage = reinterpret_cast<StorageType*>(data)->storage.bytes;  // NOLINT
    new (storage) io::Configuration(attributes);
    data->convertible = storage;
  }
};

std::shared_ptr<LaneletMap> dealbinmsg(const std::string& data_str)
{
  std::shared_ptr<LaneletMap> map = std::make_shared<LaneletMap>();
  std::stringstream ss;
  ss << data_str;
  boost::archive::binary_iarchive oa(ss);
  oa >> *map;
  lanelet::Id id_counter = 0;
  oa >> id_counter;
  lanelet::utils::registerId(id_counter);
  return map;
}

BOOST_PYTHON_MODULE(example_module)
{
    using namespace boost::python;
    def("dealbinmsg", dealbinmsg);
}


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