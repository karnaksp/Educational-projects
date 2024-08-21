from cython cimport boundscheck, wraparound

cdef int MAX_SIZE = 100

@boundscheck(False)
@wraparound(False)
def mul(list m1, list m2):
    cdef int r1 = len(m1)
    cdef int c1 = len(m1[0])
    cdef int r2 = len(m2)
    cdef int c2 = len(m2[0])

    if r1 > MAX_SIZE or c1 > MAX_SIZE or r2 > MAX_SIZE or c2 > MAX_SIZE:
        raise ValueError(f"Matrix size exceeds maximum allowed size of {MAX_SIZE}x{MAX_SIZE}")
    if c1 != r2:
        raise ArithmeticError("Matrix dimensions do not match for multiplication")
    for row in m1:
        if not all(isinstance(x, int) for x in row):
            raise TypeError("Matrix m1 contains non-integer elements")
    for row in m2:
        if not all(isinstance(x, int) for x in row):
            raise TypeError("Matrix m2 contains non-integer elements")
    
    cdef list res = [[0 for _ in range(c2)] for _ in range(r1)]
    for i in range(r1):
        for j in range(c2):
            for k in range(c1):
                res[i][j] += m1[i][k] * m2[k][j]

    return res

