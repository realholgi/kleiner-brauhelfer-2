#ifndef DLGVOLUMEN_H
#define DLGVOLUMEN_H

#include <QDialog>

namespace Ui {
class DlgVolumen;
}

class DlgVolumen : public QDialog
{
    Q_OBJECT
    
public:
    DlgVolumen(double durchmesser, double hoehe, QWidget * parent = nullptr);
    DlgVolumen(QWidget * parent = nullptr);
    ~DlgVolumen();
	void setLiter(double Liter);
    double getLiter() const;
    
private slots:
	void on_spinBox_VonOben_valueChanged(double );
	void on_spinBox_VonUnten_valueChanged(double );
	void on_spinBox_Temperatur_valueChanged(int );
	void on_spinBox_Liter_valueChanged(double );
	void on_buttonBox_accepted();
	void on_buttonBox_rejected();

private:
    void BerLiter20Grad();
    
private:
    Ui::DlgVolumen *ui;
	double Durchmesser;
    double Hoehe;
};

#endif // DLGVOLUMEN_H





