#ifndef MODELFLASCHENLABELTAGS_H
#define MODELFLASCHENLABELTAGS_H

#include "sqltablemodel.h"

class Brauhelfer;

class ModelFlaschenlabelTags : public SqlTableModel
{
    Q_OBJECT

public:

    enum Column
    {
        ColID,
        ColSudID,
        ColTagname,
        ColValue,
        // virtual
        ColDeleted,
        ColGlobal
    };

public:

    ModelFlaschenlabelTags(Brauhelfer* bh, QSqlDatabase db = QSqlDatabase());
    QVariant dataExt(const QModelIndex &index) const Q_DECL_OVERRIDE;
    bool setDataExt(const QModelIndex &index, const QVariant &value) Q_DECL_OVERRIDE;
    Qt::ItemFlags flags(const QModelIndex &index) const Q_DECL_OVERRIDE;
    void defaultValues(QMap<int, QVariant> &values) const Q_DECL_OVERRIDE;

private:

    bool isUnique(const QModelIndex &index, const QVariant &value, const QVariant &sudId, bool ignoreIndexRow = false) const;
    QString getUniqueName(const QModelIndex &index, const QVariant &value, const QVariant &sudId, bool ignoreIndexRow = false) const;

private:

    Brauhelfer* bh;
};

#endif // MODELFLASCHENLABELTAGS_H
