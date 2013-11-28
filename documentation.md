Neodymium Lite: Object interface
================================

namespace nd:
namespace for neodymium objects and support functions

solution:
administrator of applications (app objects)

app:
class that maintain all the information about a system described into the JSON document. all objects, relationship data are stored here ready to cast any object on-demand, also maintain the storage and the CRUD from the casted object

protoObject:
basic object with the property of signal/slotting for property changes and the posibility of binding with Qt Widgets

model:
model generated from a modelDefinition, also can be initialize with a json. is a inheritance of protoobject

modelDefinition:
definition about a model in the application

api:
maintain information to persistence of model for the application

ajax:
helper class to create a AJAX-like object to work with a REST Api