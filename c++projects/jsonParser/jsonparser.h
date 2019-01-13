#ifndef JSONPARSER_H
#define JSONPARSER_H

#include <QJsonDocument>
#include <QFile>
#include <QTextStream>
#include <QJsonObject>
#include <QJsonArray>
#include <QObject>
#include <QtCore>

class JsonParser: public QObject{
    Q_OBJECT
public:
    explicit JsonParser(QObject* pobj = nullptr);
public slots:
    bool readJsonFile(std::string file_path, QVariantList& result);
    bool writeJsonFile(QVariantList list, std::string file_path);
    bool writeJsFile(std::string file_path);
    void setId(int indx);
    void setSearchKey(QString key);
    void setChangeKey(QString key);
    void openSync();
private:
    QVariantList list;
    int m_index = -1;
    QString parse_string;
    const bool state = false;
    QString key_search = "id";
    QString key_change = "canBuy";
    std::string pathToJson = "C:/Users/Martynuk/Desktop/Dev/FloralMachineListModel/prices.json";
    std::string pathToJs = "C:/Users/Martynuk/Desktop/Dev/FloralMachineListModel/flower.js";
};

#endif // JSONPARSER_H
