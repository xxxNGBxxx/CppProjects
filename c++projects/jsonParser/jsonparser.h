#ifndef JSONPARSER_H
#define JSONPARSER_H

#include <QJsonDocument>
#include <QFile>
#include <QTextStream>
#include <QJsonObject>
#include <QJsonArray>


class JsonParser{
public:
    JsonParser();
    bool readJsonFile(std::string file_path, QVariantList& result);
    bool writeJsonFile(QVariantList point_map, std::string file_path);
    void setId(int indx, bool stt);
private:
    int m_index;
    QString parse_string;
    bool state;
};

#endif // JSONPARSER_H
