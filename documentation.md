Neodymium Lite: Object interface
================================

namespace nd:
namespace for neodymium objects and support functions

NdLite:
main class from this library, maintains all objects into scope and create a fast look-up for every element in the system

app:
class that maintain all the information about a system described into the JSON document. all objects, relationship data are stored here ready to cast any object on-demand, also maintain the storage and the CRUD from the casted object

storage:
interface that create a facade to all element in the ecosystem of neodydium, all persist operation call some of the function into this interface and depends on the implementacion, is how the storage store and give infomation to th system

object:
maintain the basic information about a object and provide interface to performe CRUD to default storage. also provide a interface to keep the data into JSON for communication with other systems

field:
maintain all the basic information about a attribute from a object and provide the basic control from the data and basic transformation for persist data

relation:
object created from the key fields from the union from the objects in the relation //ToDo

Relationship
object that maintain the relation between a subset of object //ToDo