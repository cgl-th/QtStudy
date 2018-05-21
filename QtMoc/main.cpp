#include <QCoreApplication>
#include <QDebug>
#include <QMetaClassInfo>
#include "qtmoc.h"

int main(int argc, char* argv[]) {
    QCoreApplication a(argc, argv);
    qDebug() << "hello qt";
    QtMoc moc;

    qDebug() << "className:" << moc.metaObject()->className();

    qDebug() << "classInfoCount:" << moc.metaObject()->classInfoCount();
    qDebug() << "classInfo:" << moc.metaObject()->classInfo(0).name();
    qDebug() << "classInfo author:" << moc.metaObject()->classInfo(0).value();

    moc.setProperty("score", "100");
    qDebug() << "property 'score':" << moc.property("score").toString();

    qDebug() << "I_NVOKABLE:" << (QMetaObject::invokeMethod(&moc, "showMessage") ? "success" : "failed");

    QObject::connect(&moc, SIGNAL(mySignal(int)), &moc, SLOT(mySlot(int)));
    qDebug() << "emit mySignal(100).";
    emit moc.mySignal(100);

    return a.exec();
}
