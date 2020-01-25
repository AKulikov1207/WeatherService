#include "weatherdata.h"

weatherData::weatherData()
{
    netwMan = new QNetworkAccessManager(this);
    connect(netwMan, SIGNAL(finished(QNetworkReply*)), this, SLOT(slot_netwMan(QNetworkReply*)));

    request.setUrl(QUrl("http://api.openweathermap.org/data/2.5/weather?id=524894&APPID=e2955f054e0963c4146846ca31e41ec8"));

    tmr = new QTimer();
    tmr->setInterval(10000);
    connect(tmr, SIGNAL(timeout()), this, SLOT(sendReq()));
    tmr->start(10000);

    qDebug() << "Timer started";
}

weatherData::~weatherData()
{
    tmr->stop();
    tmr->deleteLater();

    delete netwMan;
}

void weatherData::sendReq()
{
    qDebug() << "OK";
    netwMan->get(request);
}

void weatherData::slot_netwMan(QNetworkReply *rep)
{
    rep->waitForReadyRead(100);
    doc = QJsonDocument::fromJson(rep->readAll(), &docEr);
    if (docEr.errorString().toInt() == QJsonParseError::NoError)
    {
        temp = doc.object().value("main").toObject();

        qDebug() << "Temp: " << temp.value("temp").toDouble() - 273;
        qDebug() << "Data: " << QDateTime::currentDateTime().date();
        qDebug() << "Time: " << QDateTime::currentDateTime().time().toString();
    }

    rep->deleteLater();
}
