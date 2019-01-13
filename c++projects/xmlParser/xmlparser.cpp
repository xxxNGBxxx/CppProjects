#include "xmlparser.h"

XmlParser::XmlParser(QObject *parent) : QObject(parent){}

void XmlParser::setDisabled(int indx){
    searchId = QString::number(indx);
    state = "false";
    readXmlFile();
}

void XmlParser::setEnabled(int indx){
    searchId = QString::number(indx);
    state = "true";
    readXmlFile();
}

bool XmlParser::readXmlFile(){

    QDomDocument xmlDoc;

    QFile xmlFile(pathToFile);
        if(!xmlFile.open(QFile::ReadWrite)){
            qDebug() << "cant open file";
            return false;
        }

    QByteArray xmlData(xmlFile.readAll());

    xmlDoc.setContent(xmlData);

    QDomElement tbl = xmlDoc.documentElement();

    QDomNode itemNode = tbl.firstChild();

    QDomNodeList listId = tbl.elementsByTagName("id");

    QDomNodeList listAvail = tbl.elementsByTagName("availability");

    for(int i = 0; i < listId.size(); i++){

        QDomNode idNode = listId.item(i);
        QDomNode availNode = listAvail.item(i);

        QDomElement idElement = idNode.toElement();
        QDomElement availElement = availNode.toElement();

        for(QDomNode n = availElement.firstChild(); !n.isNull(); n = n.nextSibling()){
            QDomText t = n.toText();
                if(idElement.text() == searchId){
                    t.setData(state);
                }
        }
    }

    xmlFile.resize(0);
    QTextStream stream;
    stream.setDevice(&xmlFile);
    xmlDoc.save(stream,4);
    xmlFile.close();

    return true;
}
