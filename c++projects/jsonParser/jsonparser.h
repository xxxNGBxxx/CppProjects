#ifndef JSONPARSER_H
#define JSONPARSER_H

#include <QJsonDocument>
#include <QFile>
#include <QTextStream>
#include <QJsonObject>
#include <QJsonArray>
#include <fstream>


class JsonParser{
public:
    JsonParser();
    bool readJsonFile(std::string file_path, QVariantList& result);
    bool writeJsonFile(QVariantList point_map, std::string file_path);
    bool writeJsFile(std::string file_path);
    void setId(int indx, bool stt);
    void setSearchKey(QString key);
    void setChangeKey(QString key);
private:
    int m_index;
    QString parse_string;
    bool state;
    QString key_search = "id";
    QString key_change = "canBuy";
};

#endif // JSONPARSER_H
