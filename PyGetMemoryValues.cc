#include <Python.h>
#include "MemoryMonitor.h"

static PyObject* GetMemoryValues(PyObject* self, PyObject* arg)
 {
   long mpid = PyLong_AsLong(arg);
   bool verbose=false;

   unsigned long array[4] = {0,0,0,0}; 
   ReadSmaps(mpid, array);
   
   PyObject* tuple = PyTuple_New(4);
   PyTuple_SetItem(tuple, 0, PyInt_FromLong(array[0]));
   PyTuple_SetItem(tuple, 1, PyInt_FromLong(array[1]));
   PyTuple_SetItem(tuple, 2, PyInt_FromLong(array[2]));
   PyTuple_SetItem(tuple, 3, PyInt_FromLong(array[3]));


   return tuple; 
 }

static PyMethodDef methods[]= {{(char *)"GetMemoryValues", (PyCFunction)GetMemoryValues, METH_O, NULL},{ NULL, NULL, 0, NULL }};

PyMODINIT_FUNC initPyMemoryMonitor(void) { Py_InitModule("PyMemoryMonitor", methods); }
