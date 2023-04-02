/**
  * \class CreationDateFormWidget
  * \brief A form widget representing the creation date of the widget.
  * \author Giorgio Wicklein - GIOWISYS Software
  * \date 01/11/2012
  */

#ifndef CREATIONDATEFORMWIDGET_H
#define CREATIONDATEFORMWIDGET_H


//-----------------------------------------------------------------------------
// Headers
//-----------------------------------------------------------------------------

#include "abstractformwidget.h"

#include <QtCore/QDateTime>


//-----------------------------------------------------------------------------
// Forward declarations
//-----------------------------------------------------------------------------

class QLabel;
class QVBoxLayout;
class QLineEdit;


//-----------------------------------------------------------------------------
// CreationDateFormWidget
//-----------------------------------------------------------------------------

class CreationDateFormWidget : public AbstractFormWidget
{
    Q_OBJECT

public:
    CreationDateFormWidget(QWidget *parent = nullptr);

    void setFieldName(const QString &name);
    QString getFieldName() const;
    void clearData();
    void setData(const QVariant &data);
    QVariant getData() const;

    /**
     * Supported display properties are:
     * - dateFormat: 1, 2, 3, 4, 5, 6, 7
     */
    void loadMetadataDisplayProperties(const QString &metadata);

protected slots:
    /**
     * Supported edit properties are:
     * (none for now)
     */
    void validateData();

private:
    /** Set the focus policy to accept focus and to redirect it to input line */
    void setupFocusPolicy();

    QLabel *m_fieldNameLabel;
    QLineEdit *m_lineEdit;
    QVBoxLayout *m_mainLayout;
    QDateTime m_dateTime;
    QString m_dateFormat;
};

#endif // CREATIONDATEFORMWIDGET_H
