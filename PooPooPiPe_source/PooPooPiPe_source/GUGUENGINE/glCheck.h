#pragma once
/*
 *juhye.son
 *9.15.2019
 *juhye.son990902@gmail.com
 *glcheck.h
 *this is clcheck header
 */

void glCheckError(const char* file, unsigned int line, const char* expression);
void glClearErrors();


// Note that this macro calls glClearErrors, does expression, semicolon, and then calls glCheckError,
// so you shouldn't use this macro under an if statement without { } and
// you shouldn't use it in a return statement.
#ifdef _DEBUG
#define glCheck(expr)                                                                                                  \
    glClearErrors();                                                                                                   \
    (expr);                                                                                                            \
    glCheckError(__FILE__, __LINE__, #expr)
#else
#define glCheck(expr) (expr)
#endif
