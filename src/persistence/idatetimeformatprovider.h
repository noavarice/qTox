#ifndef IDATETIMEFORMATPROVIDER_H
#define IDATETIMEFORMATPROVIDER_H

#include <QObject>

class IDateTimeFormatProvider : public QObject
{
    Q_OBJECT
public:
    virtual ~IDateTimeFormatProvider();

    virtual const QString& getDateFormat() const = 0;
    virtual const QString& getTimestampFormat() const = 0;

signals:
    void dateFormatChanged(const QString& newFormat);
    void timestampFormatChanged(const QString& newFormat);
};

#endif // IDATETIMEFORMATPROVIDER_H
