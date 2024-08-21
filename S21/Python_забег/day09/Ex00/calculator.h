#ifndef PYTHON_CALCULATOR_H
#define PYTHON_CALCULATOR_H

#include <python3.12/Python.h>

PyObject* perform_operation(PyObject* a, PyObject* b, char op);

PyObject* calculator_add(PyObject* self, PyObject* args);
PyObject* calculator_sub(PyObject* self, PyObject* args);
PyObject* calculator_mul(PyObject* self, PyObject* args);
PyObject* calculator_div(PyObject* self, PyObject* args);

#endif // PYTHON_CALCULATOR_H
