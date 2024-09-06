#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QLabel>
#include <QLineEdit>
#include <QQuickWidget>
#include <QLayout>

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow() {/*empty*/};

signals:
    void redrawKeyboard();

private:
    QWidget *centralwidget;
    QLineEdit *lineEdit1;
    QLineEdit *lineEdit2;
    QLineEdit *lineEdit3;
    QLineEdit *lineEdit4;
    QLabel *label1;
    QLabel *label2;
    QLabel *label3;
    QLabel *label4;
    QHBoxLayout *horizontalLayout1;
    QHBoxLayout *horizontalLayout2;
    QHBoxLayout *horizontalLayout3;
    QHBoxLayout *horizontalLayout4;
    QVBoxLayout *verticalLayout;
    QQuickWidget *keybContainer;

private slots:
    void onFocusChange(QWidget *, QWidget *);
};
#endif // MAINWINDOW_H
