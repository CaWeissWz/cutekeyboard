#include "mainwindow.h"
#include <QQuickItem>
#include <QPropertyAnimation>
#include <QTimer>

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
{
    this->setWindowTitle("CuteKeyboard and Widgets Example");
    this->resize(640, 640);

    centralwidget = new QWidget(parent);
    centralwidget->setObjectName("centralwidget");


    lineEdit1 = new QLineEdit(centralwidget);
    lineEdit1->setFixedSize(QSize(200,25));
    lineEdit1->setFocusPolicy(Qt::ClickFocus);

    label1 = new QLabel(centralwidget);
    label1->setText("Basic QLineEdit");

    horizontalLayout1 = new QHBoxLayout();
    horizontalLayout1->addStretch(1);
    horizontalLayout1->addWidget(label1);
    horizontalLayout1->addWidget(lineEdit1);
    horizontalLayout1->addStretch(1);


    lineEdit2 = new QLineEdit(centralwidget);
    lineEdit2->setFixedSize(QSize(200,25));
    lineEdit2->setFocusPolicy(Qt::ClickFocus);
    lineEdit2->setInputMethodHints(Qt::ImhPreferNumbers);

    label2 = new QLabel(centralwidget);
    label2->setText("Numeric input QLineEdit");

    horizontalLayout2 = new QHBoxLayout();
    horizontalLayout2->addStretch(1);
    horizontalLayout2->addWidget(label2);
    horizontalLayout2->addWidget(lineEdit2);
    horizontalLayout2->addStretch(1);


    lineEdit3 = new QLineEdit(centralwidget);
    lineEdit3->setFixedSize(QSize(200,25));
    lineEdit3->setFocusPolicy(Qt::ClickFocus);
    lineEdit3->setInputMethodHints(Qt::ImhDigitsOnly);

    label3 = new QLabel(centralwidget);
    label3->setText("Digits only QLineEdit");

    horizontalLayout3 = new QHBoxLayout();
    horizontalLayout3->addStretch(1);
    horizontalLayout3->addWidget(label3);
    horizontalLayout3->addWidget(lineEdit3);
    horizontalLayout3->addStretch(1);


    verticalLayout = new QVBoxLayout();
    verticalLayout->addStretch(1);
    verticalLayout->addLayout(horizontalLayout1);
    verticalLayout->addSpacing(10);
    verticalLayout->addLayout(horizontalLayout2);
    verticalLayout->addSpacing(10);
    verticalLayout->addLayout(horizontalLayout3);
    verticalLayout->addStretch(1);

    keybContainer = new QQuickWidget(centralwidget);
    keybContainer->setGeometry(QRect(0,400,640,240));
    keybContainer->setFocusPolicy(Qt::NoFocus);
    keybContainer->setAcceptDrops(false);
    keybContainer->setAutoFillBackground(false);
    keybContainer->setResizeMode(QQuickWidget::SizeRootObjectToView);
    keybContainer->setSource(QUrl(QString::fromUtf8("qrc:/example_widgets.qml")));

    centralwidget->setLayout(verticalLayout);
    this->setCentralWidget(centralwidget);

    keybContainer->setAttribute(Qt::WA_AlwaysStackOnTop);
    keybContainer->setAttribute(Qt::WA_TranslucentBackground);
    keybContainer->setClearColor(Qt::transparent);

    auto * keyboard = keybContainer->rootObject()->findChild<QQuickItem *>("inputPanel");
    keyboard->setProperty("languageLayout", "De");

    keybContainer->hide();

    connect(qApp, SIGNAL(focusChanged(QWidget *, QWidget *)), this, SLOT(onFocusChange(QWidget *, QWidget *)) );

    // on returnPressed, set focus away from QLineEdit
    for(int i=0; i < centralwidget->children().count(); i++)
    {
        if(qobject_cast<QLineEdit*>(centralwidget->children()[i]) != NULL) //Check if newWidget is based on QLineEdit
        {
            connect(centralwidget->children()[i], SIGNAL(returnPressed()), centralwidget, SLOT(setFocus()));
        }
    }
}


void MainWindow::onFocusChange(QWidget * oldWidget, QWidget * newWidget)
{
    Q_UNUSED(oldWidget);

    if(qobject_cast<QLineEdit*>(newWidget) != NULL) //Check if newWidget is based on QLineEdit
    {
        if(keybContainer->isHidden() == true)
        {
            QPropertyAnimation *keybAnim = new QPropertyAnimation(keybContainer, "pos", this);
            keybAnim->setDuration(200);
            keybAnim->setStartValue(QPoint(0, centralwidget->size().height()));
            keybAnim->setEndValue(QPoint(0, centralwidget->size().height() - keybContainer->size().height()));
            keybAnim->start();

            keybContainer->show();
        }
    }
    else
    {
        if(keybContainer->isHidden() == false)
        {
            QPropertyAnimation *keybAnim = new QPropertyAnimation(keybContainer, "pos", this);
            keybAnim->setDuration(200);
            keybAnim->setStartValue(QPoint(0, keybContainer->pos().y()));
            keybAnim->setEndValue(QPoint(0, centralwidget->size().height()));
            keybAnim->start();

            QTimer::singleShot(200, keybContainer, SLOT(hide()));
        }
    }
}

