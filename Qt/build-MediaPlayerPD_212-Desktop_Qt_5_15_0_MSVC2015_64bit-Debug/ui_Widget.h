/********************************************************************************
** Form generated from reading UI file 'Widget.ui'
**
** Created by: Qt User Interface Compiler version 5.15.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_WIDGET_H
#define UI_WIDGET_H

#include <QtCore/QVariant>
#include <QtGui/QIcon>
#include <QtWidgets/QApplication>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QSlider>
#include <QtWidgets/QTableView>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_Widget
{
public:
    QPushButton *pushButtonPlay;
    QPushButton *pushButtonPause;
    QPushButton *pushButtonStop;
    QLabel *labelComposition;
    QPushButton *pushButtonOpen;
    QPushButton *pushButtonPrev;
    QPushButton *pushButtonNext;
    QSlider *horizontalSliderVolume;
    QLabel *labelVolume;
    QSlider *horizontalSliderProgress;
    QLabel *labelProgress;
    QLabel *labelDuration;
    QPushButton *pushButtonMute;
    QTableView *tableViewPlaylist;

    void setupUi(QWidget *Widget)
    {
        if (Widget->objectName().isEmpty())
            Widget->setObjectName(QString::fromUtf8("Widget"));
        Widget->resize(800, 600);
        QIcon icon;
        icon.addFile(QString::fromUtf8(":/ico/ico/preferences_desktop_sound_16925.ico"), QSize(), QIcon::Normal, QIcon::Off);
        Widget->setWindowIcon(icon);
        pushButtonPlay = new QPushButton(Widget);
        pushButtonPlay->setObjectName(QString::fromUtf8("pushButtonPlay"));
        pushButtonPlay->setGeometry(QRect(130, 60, 80, 21));
        pushButtonPause = new QPushButton(Widget);
        pushButtonPause->setObjectName(QString::fromUtf8("pushButtonPause"));
        pushButtonPause->setGeometry(QRect(220, 60, 80, 21));
        pushButtonStop = new QPushButton(Widget);
        pushButtonStop->setObjectName(QString::fromUtf8("pushButtonStop"));
        pushButtonStop->setGeometry(QRect(310, 60, 80, 21));
        labelComposition = new QLabel(Widget);
        labelComposition->setObjectName(QString::fromUtf8("labelComposition"));
        labelComposition->setGeometry(QRect(40, 30, 561, 16));
        pushButtonOpen = new QPushButton(Widget);
        pushButtonOpen->setObjectName(QString::fromUtf8("pushButtonOpen"));
        pushButtonOpen->setGeometry(QRect(40, 560, 80, 21));
        pushButtonPrev = new QPushButton(Widget);
        pushButtonPrev->setObjectName(QString::fromUtf8("pushButtonPrev"));
        pushButtonPrev->setGeometry(QRect(40, 60, 80, 21));
        pushButtonNext = new QPushButton(Widget);
        pushButtonNext->setObjectName(QString::fromUtf8("pushButtonNext"));
        pushButtonNext->setGeometry(QRect(400, 60, 80, 21));
        horizontalSliderVolume = new QSlider(Widget);
        horizontalSliderVolume->setObjectName(QString::fromUtf8("horizontalSliderVolume"));
        horizontalSliderVolume->setGeometry(QRect(610, 60, 160, 16));
        horizontalSliderVolume->setOrientation(Qt::Horizontal);
        labelVolume = new QLabel(Widget);
        labelVolume->setObjectName(QString::fromUtf8("labelVolume"));
        labelVolume->setGeometry(QRect(620, 30, 151, 16));
        horizontalSliderProgress = new QSlider(Widget);
        horizontalSliderProgress->setObjectName(QString::fromUtf8("horizontalSliderProgress"));
        horizontalSliderProgress->setGeometry(QRect(40, 130, 731, 16));
        horizontalSliderProgress->setOrientation(Qt::Horizontal);
        labelProgress = new QLabel(Widget);
        labelProgress->setObjectName(QString::fromUtf8("labelProgress"));
        labelProgress->setGeometry(QRect(40, 100, 191, 16));
        labelDuration = new QLabel(Widget);
        labelDuration->setObjectName(QString::fromUtf8("labelDuration"));
        labelDuration->setGeometry(QRect(670, 100, 101, 16));
        pushButtonMute = new QPushButton(Widget);
        pushButtonMute->setObjectName(QString::fromUtf8("pushButtonMute"));
        pushButtonMute->setGeometry(QRect(570, 60, 31, 21));
        tableViewPlaylist = new QTableView(Widget);
        tableViewPlaylist->setObjectName(QString::fromUtf8("tableViewPlaylist"));
        tableViewPlaylist->setGeometry(QRect(45, 171, 721, 361));

        retranslateUi(Widget);

        QMetaObject::connectSlotsByName(Widget);
    } // setupUi

    void retranslateUi(QWidget *Widget)
    {
        Widget->setWindowTitle(QCoreApplication::translate("Widget", "Winamp", nullptr));
        pushButtonPlay->setText(QString());
        pushButtonPause->setText(QString());
        pushButtonStop->setText(QString());
        labelComposition->setText(QCoreApplication::translate("Widget", "TextLabel Composition", nullptr));
        pushButtonOpen->setText(QCoreApplication::translate("Widget", "Open", nullptr));
        pushButtonPrev->setText(QString());
        pushButtonNext->setText(QString());
        labelVolume->setText(QCoreApplication::translate("Widget", "Volume:", nullptr));
        labelProgress->setText(QCoreApplication::translate("Widget", "Progress", nullptr));
        labelDuration->setText(QCoreApplication::translate("Widget", "Duration:", nullptr));
        pushButtonMute->setText(QString());
    } // retranslateUi

};

namespace Ui {
    class Widget: public Ui_Widget {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_WIDGET_H
