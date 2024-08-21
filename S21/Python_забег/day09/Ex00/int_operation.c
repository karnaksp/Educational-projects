#include "calculator.h"

PyObject* perform_operation(PyObject* a, PyObject* b, char op) {
    long num_a, num_b, result;
    num_a = PyLong_AsLong(a);
    num_b = PyLong_AsLong(b);

    if (PyErr_Occurred()) {
        return NULL;
    }

    switch (op) {
        case '+': result = num_a + num_b; break;
        case '-': result = num_a - num_b; break;
        case '*': result = num_a * num_b; break;
        case '/':
            if (num_b == 0) {
                PyErr_SetString(PyExc_ZeroDivisionError, "Cannot divide by zero");
                return NULL;
            }
            result = num_a / num_b; break;
        default:
            PyErr_SetString(PyExc_ValueError, "Invalid operation");
            return NULL;
    }
    return PyLong_FromLong(result);
}
