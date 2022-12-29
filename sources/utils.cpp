#include "utils.hpp"

void setPushButtonSize(QPushButton *button, int width, int height)
{
    button->setSizeIncrement(width, height);
    button->setMinimumSize(width, height);
}

void setPushButtonFont(QPushButton *button, int font)
{
    QFont buttonFont = button->font();
    buttonFont.setPointSize(font);
    button->setFont(buttonFont);
}

void setLabelTextFont(QLabel* label, int font)
{
    QFont buttonFont = label->font();
    buttonFont.setPointSize(font);
    label->setFont(buttonFont);
}

void setStyleSheet(QString path, QWidget* obj)
{
    QFile file;
    file.setFileName(path);
    file.open(QFile::ReadOnly);
    QString styleSheet = QLatin1String(file.readAll());
    obj->setStyleSheet(styleSheet);
    file.close();
}

QString removeUnderscoreInString(QString str)
{
    for (auto it = str.begin(); it != str.end(); ++it)
        if (*it == '_')
            *it = ' ';
    return str;
}
