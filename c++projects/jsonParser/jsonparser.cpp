#include "jsonparser.h"
#include <QDebug>

JsonParser::JsonParser(){

}

bool JsonParser::readJsonFile(std::string file_path, QVariantList& result){
    // open file
    QFile file_obj(QString::fromStdString(file_path));
        if (!file_obj.open(QIODevice::ReadOnly)) {
            qDebug()<< "cant open file";
            return false;
        }

    // read json
    QTextStream file_text(&file_obj);
    QString json_string;
    json_string = file_text.readAll();

    file_obj.close();

    QByteArray json_bytes = json_string.toUtf8();
    auto json_doc = QJsonDocument::fromJson(json_bytes);

   // check to errors
    if(!json_doc.isArray()){
        qDebug()<< "doc is'nt array";
        return false;
    }

    if(json_doc.isNull()){
        qDebug()<< "cant create doc";
        return false;
    }

    QJsonArray json_array = json_doc.array();

    if (json_array.isEmpty()) {
        qDebug()<< "array is empty";
        return false;
    }

    // change data

    foreach(const QJsonValue &value, json_array){
        QJsonObject json_obj = value.toObject();
        if(json_obj["id"].toInt() == (m_index)){
            json_obj["canBuy"] = state;
            if(m_index < json_array.size()){
                json_array[m_index] = json_obj;
            }
            else{
                qDebug()<< "index out of array";
            }
        }
    }

    result = json_array.toVariantList();

    return true;
}

bool JsonParser::writeJsonFile(QVariantList list, std::string file_path){
    QJsonArray json_array = QJsonArray::fromVariantList(list);
    QJsonDocument json_doc(json_array);
    QString json_string = json_doc.toJson(QJsonDocument::Indented);
    parse_string = "var jsonModel = " + json_string;
    qDebug()<<parse_string;
    QFile save_file(QString::fromStdString(file_path));
        if (!save_file.open(QIODevice::WriteOnly)) {
            qDebug()<< "cant write file";
            return false;
        }
    save_file.write(json_string.toUtf8());
    save_file.close();
    return true;
}

void JsonParser::setId(int indx,bool stt){
    m_index = indx;
    state = stt;
}
