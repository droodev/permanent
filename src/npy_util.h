// Array access macros.
#define SM(x0, x1) (*(npy_complex128*)(((char*)PyArray_DATA(submatrix) + \
                    (x0) * PyArray_STRIDES(submatrix)[0] +  \
                    (x1) * PyArray_STRIDES(submatrix)[1])))
#define SM_shape(x0) (int) PyArray_DIM(submatrix, x0)

#if defined(_MSC_VER)
  static const npy_complex128 complex_one = {1.0f, 0.0f};
  static const npy_complex128 complex_zero = {0.0f, 0.0f};
#else /* !defined(_MSC_VER) */
  static const npy_complex128 complex_one = 1 + 0 * I;
  static const npy_complex128 complex_zero = 0 + 0 * I;
#endif

// Complex numbers

// Add two numbers
npy_complex128 complex_add(npy_complex128 a, npy_complex128 b) { 
    return a+b;
}

// Product of two numbers
npy_complex128 complex_prod(npy_complex128 a, npy_complex128 b) { 
    #if defined(_MSC_VER)
      return _FCmulcc(a, b); 
    #else /* !defined(_MSC_VER) */
      return a*b;
    #endif
}

// Product of complex and float
npy_complex128 complex_float_prod(npy_complex128 a, float b) { 
    #if defined(_MSC_VER)
      return _FCmulcr(a, b); 
    #else /* !defined(_MSC_VER) */
      return a*b;
    #endif
}

// Increment a number
void complex_inc(npy_complex128 *a, npy_complex128 b) { 
    #if defined(_MSC_VER)
      npy_complex128 tmp = {creal(*a) + creal(b), cimag(*a) + cimag(b)};
      npy_csetreal(a, creal(tmp));
      npy_csetimag(a, cimag(tmp));
      return; 
    #else /* !defined(_MSC_VER) */
      *a *= b;
    #endif
    return;
}

// Multipy a number by another one
void complex_multiply(npy_complex128 *a, npy_complex128 b) { 
    #if defined(_MSC_VER)
      npy_complex128 tmp = _FCmulcc(a, b);
      npy_csetreal(a, creal(tmp));
      npy_csetimag(a, cimag(tmp));
      return ; 
    #else /* !defined(_MSC_VER) */
      *a *= b;
    #endif
    return;
}

