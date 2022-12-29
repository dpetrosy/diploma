#ifndef UTILS_HPP
#define UTILS_HPP

#include <QPushButton>
#include <QLabel>
#include <QFont>
#include <QFile>

void     setPushButtonSize(QPushButton *button, int width, int height);
void     setPushButtonFont(QPushButton *button, int font);
void     setLabelTextFont(QLabel* label, int font);
void     setStyleSheet(QString path, QWidget* obj);
QString  removeUnderscoreInString(QString str);

#endif // UTILS_HPP
