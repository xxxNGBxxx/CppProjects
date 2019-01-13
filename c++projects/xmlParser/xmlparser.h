#ifndef XMLPARSER_H
#define XMLPARSER_H

#include <QObject>
#include <QFile>
#include <QDebug>
#include <QDomDocument>

class XmlParser : public QObject{
    Q_OBJECT
public:
    explicit XmlParser(QObject *parent = nullptr);
public slots:
    void setDisabled(int indx);
    void setEnabled(int indx);
    bool readXmlFile();
private:
    QString searchId = "-1";
    QString state;
    const QString pathToFile = "C:/Users/Martynuk/Desktop/Dev/FloralMachineListModel4Check/price.xml";
};

#endif // XMLPARSER_H
