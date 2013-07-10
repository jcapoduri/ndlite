#ifndef NDLITE_GLOBAL_H
#define NDLITE_GLOBAL_H

#include <QtCore/qglobal.h>

#if defined(NDLITE_LIBRARY)
#  define NDLITESHARED_EXPORT Q_DECL_EXPORT
#else
#  define NDLITESHARED_EXPORT Q_DECL_IMPORT
#endif

#endif // NDLITE_GLOBAL_H
