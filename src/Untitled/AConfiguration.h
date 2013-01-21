#ifndef ACONFIGURATION_H
#define ACONFIGURATION_H

#include <QMap>
#include <QString>
#include <QVariant>

typedef QMap<QString,QVariant>      Parameters;
typedef Parameters::ConstIterator   ParameterItr;

class AConfiguration : private Parameters
{

    public:
        QVariant    getParameter(QString parameterCode) const
        {

            ParameterItr parameterItr = this->find(parameterCode);

            return parameterItr != this->end() ? parameterItr.value() : "";

        }
        void        setParameter(QString parameterName, QString parameterValue)
        {

            this->insert(parameterName,parameterValue);

        }
        bool        isSet(QString parameterCode) const
        {

            return this->contains(parameterCode);

        }

};

#endif // ACONFIGURATION_H
