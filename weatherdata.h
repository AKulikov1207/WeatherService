#ifndef WEATHERDATA_H
#define WEATHERDATA_H

#include <QObject>
#include <QJsonDocument>
#include <QJsonObject>
#include <QJsonParseError>
#include <QNetworkAccessManager>
#include <QNetworkRequest>
#include <QNetworkReply>
#include <QTimer>
#include <QDebug>
#include <QUrl>

class weatherData : public QObject
{
    Q_OBJECT
public:
    weatherData();
    ~weatherData();

    QTimer* tmr;

    QJsonDocument doc;
    QJsonObject temp;
    QJsonParseError docEr;

    QNetworkAccessManager* netwMan;
    QNetworkRequest request;

private slots:
    void sendReq();
    void slot_netwMan(QNetworkReply*);
};

#endif // WEATHERDATA_H
