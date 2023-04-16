#include "clickablelabel.hpp"

ClickableLabel::ClickableLabel(QWidget* parent, Qt::WindowFlags f)
    : QLabel(parent)
{
    Q_UNUSED(f)
}

ClickableLabel::~ClickableLabel() {}

// Mouse press events
void ClickableLabel::mousePressEvent(QMouseEvent* event)
{
    if(event->buttons() & Qt::LeftButton)
        emit clickedLeftButton();
}
