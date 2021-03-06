#ifndef MODELHEFEGABEN_H
#define MODELHEFEGABEN_H

#include "sqltablemodel.h"

class Brauhelfer;

class ModelHefegaben : public SqlTableModel
{
    Q_OBJECT

public:

    enum Column
    {
        ColID,
        ColSudID,
        ColName,
        ColMenge,
        ColZugegeben,
        ColZugabeNach,
        // virtual
        ColDeleted,
        ColZugabeDatum,
        ColAbfuellbereit
    };

public:

    ModelHefegaben(Brauhelfer* bh, QSqlDatabase db = QSqlDatabase());
    QVariant dataExt(const QModelIndex &index) const Q_DECL_OVERRIDE;
    bool setDataExt(const QModelIndex &index, const QVariant &value) Q_DECL_OVERRIDE;
    void defaultValues(QMap<int, QVariant> &values) const Q_DECL_OVERRIDE;

private slots:

    void onSudDataChanged(const QModelIndex &index);

private:

    Brauhelfer* bh;
};

#endif // MODELHEFEGABEN_H
