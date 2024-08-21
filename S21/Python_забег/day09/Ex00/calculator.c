#include "calculator.h"

PyObject* calculator_add(PyObject* self, PyObject* args) {
    PyObject *a, *b;
    if (!PyArg_ParseTuple(args, "OO", &a, &b)) {
        return NULL;
    }
    return perform_operation(a, b, '+');
}

PyObject* calculator_sub(PyObject* self, PyObject* args) {
    PyObject *a, *b;
    if (!PyArg_ParseTuple(args, "OO", &a, &b)) {
        return NULL;
    }
    return perform_operation(a, b, '-');
}

PyObject* calculator_mul(PyObject* self, PyObject* args) {
    PyObject *a, *b;
    if (!PyArg_ParseTuple(args, "OO", &a, &b)) {
        return NULL;
    }
    return perform_operation(a, b, '*');
}

PyObject* calculator_div(PyObject* self, PyObject* args) {
    PyObject *a, *b;
    if (!PyArg_ParseTuple(args, "OO", &a, &b)) {
        return NULL;
    }
    return perform_operation(a, b, '/');
}

static PyMethodDef CalculatorMethods[] = {
    {"add", calculator_add, METH_VARARGS, "Add two numbers"},
    {"sub", calculator_sub, METH_VARARGS, "Subtract two numbers"},
    {"mul", calculator_mul, METH_VARARGS, "Multiply two numbers"},
    {"div", calculator_div, METH_VARARGS, "Divide two numbers"},
    {NULL, NULL, 0, NULL}
};

static struct PyModuleDef calculatormodule = {
    PyModuleDef_HEAD_INIT,
    "calculator",
    "A simple calculator module",
    -1,
    CalculatorMethods
};

PyMODINIT_FUNC PyInit_calculator(void) {
    return PyModule_Create(&calculatormodule);
}
