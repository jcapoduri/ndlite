#ifndef MODELEXCEPTION_H
#define MODELEXCEPTION_H
#include <QException>

class modelException : public QException
{
public:
    void    raise()  const { throw *this; }
    modelException* clone() const { return new modelException(*this); }
    
};

#endif // MODELEXCEPTION_H
