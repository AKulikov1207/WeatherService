#include <QCoreApplication>
#include "weatherdata.h"

int main(int argc, char *argv[])
{
    QCoreApplication a(argc, argv);

    weatherData wd;

    return a.exec();
}
