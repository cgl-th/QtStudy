#include "qtmoc.h"
#include <QDebug>

QtMoc::QtMoc(QObject* parent) : QObject(parent) {

}

void QtMoc::showMessage() {
    qDebug() << "I am from Q_INVOKABLE";
}

void QtMoc::mySlot(int reciveData) {
    qDebug() << "mySlot recive data:" << reciveData;
    qDebug() << "sender:" << sender()->metaObject()->className();
}
