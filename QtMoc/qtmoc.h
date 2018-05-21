#ifndef QTMOC_H
#define QTMOC_H

#include <QObject>

class QtMoc : public QObject {
    Q_OBJECT
  public:
    explicit QtMoc(QObject* parent = nullptr);

    Q_CLASSINFO("author", "shajia")
    Q_CLASSINFO("email", "cgl_th@126.com")

    Q_INVOKABLE void showMessage();

  signals:
    void mySignal(int sendData);

  public slots:
    void mySlot(int reciveData);

};

#endif // QTMOC_H
