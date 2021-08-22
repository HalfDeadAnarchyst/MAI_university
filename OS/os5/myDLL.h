

#ifndef MYDLL_H_INCLUDED
#define MYDLL_H_INCLUDED

#ifdef _F_
#define F __declspec(dllexport)
#else
#define F __declspec(dllimport)
#endif

#include <windows.h>

VOID F tree();
#endif // MYDLL_H_INCLUDED
