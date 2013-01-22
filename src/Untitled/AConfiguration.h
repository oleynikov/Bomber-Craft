#ifndef ACONFIGURATION_H
#define ACONFIGURATION_H

#include <QMap>
#include <QString>
#include <QVariant>
#include <QVector>

typedef QMap<QString,QVariant>      Parameters;
typedef Parameters::ConstIterator   ParametersItr;
typedef QVector<QString>            ParametersList;
typedef ParametersList::Iterator    ParametersListItr;

class AConfiguration : private Parameters
{

    public:
        AConfiguration* getSubConfiguration(ParametersList parameters)
        {

            AConfiguration* subConfiguration = new AConfiguration();

            while (!parameters.empty())
            {

                ParametersItr parameterItr = this->find(parameters.last());

                if(parameterItr != this->end())
                {

                    subConfiguration->setParameter(parameterItr.key(),parameterItr.value().toString());

                }

                parameters.pop_back();

            }

            return subConfiguration;

        }
        QVariant        getParameter(QString parameterCode) const
        {

            ParametersItr parameterItr = this->find(parameterCode);

            return parameterItr != this->end() ? parameterItr.value() : "";

        }
        void            setParameter(QString parameterName, QString parameterValue)
        {

            this->insert(parameterName,parameterValue);

        }
        bool            isSet(QString parameterCode) const
        {

            return this->contains(parameterCode);

        }

};

#endif // ACONFIGURATION_H
