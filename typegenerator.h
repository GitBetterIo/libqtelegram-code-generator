#ifndef TYPEGENERATOR_H
#define TYPEGENERATOR_H

#include "abstractgenerator.h"

#include <QStringList>
#include <QRegExp>
#include <QMap>
#include <QSet>

class TypeGenerator : public AbstractGenerator
{
public:
    TypeGenerator(const QString &dest);
    ~TypeGenerator();

    void extract(const QString &data);

protected:
    QString typeToFetchFunction(const QString &arg, const QString &type, const GeneratorTypes::ArgStruct &argStruct);
    QString fetchFunction(const QString &name, const QList<GeneratorTypes::TypeStruct> &types);
    QString typeToPushFunction(const QString &arg, const QString &type, const GeneratorTypes::ArgStruct &argStruct);
    QString pushFunction(const QString &name, const QList<GeneratorTypes::TypeStruct> &types);
    void writeTypeHeader(const QString &name, const QList<GeneratorTypes::TypeStruct> &types);
    void writeTypeClass(const QString &name, const QList<GeneratorTypes::TypeStruct> &types);
    void writeType(const QString &name, const QList<GeneratorTypes::TypeStruct> &types);
    void writePri(const QStringList &types);
    void writeMainHeader(const QStringList &types);
    void copyEmbeds();

private:
    QString m_dst;
};

#endif // TYPEGENERATOR_H