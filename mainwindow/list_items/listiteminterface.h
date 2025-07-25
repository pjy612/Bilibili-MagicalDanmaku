#ifndef LISTITEMINTERFACE_H
#define LISTITEMINTERFACE_H

#include <QWidget>
#include <QApplication>
#include <QResizeEvent>
#include <QLabel>
#include <QVBoxLayout>
#include <QCheckBox>
#include <QTimer>
#include "myjson.h"
#include "interactivebuttonbase.h"
#include "custompaintwidget.h"

class ListItemInterface : public QWidget
{
    Q_OBJECT
public:
    explicit ListItemInterface(QWidget *parent = nullptr);

    virtual void fromJson(MyJson) = 0;
    virtual MyJson toJson() const = 0;

    virtual bool isEnabled() const
    {
        return false;
    }

    virtual QString title() const
    {
        return "";
    }

    virtual QString body() const
    {
        return "";
    }

    virtual void setCode(const QString &code)
    {
        Q_UNUSED(code);
    }

    virtual QString getCode() const
    {
        return "";
    }

    void setRow(int row);

    int getRow() const;

    bool matchId(QString s) const;

    virtual void triggered();

    virtual bool isEmpty() const
    {
        return title().isEmpty() && body().isEmpty();
    }

    virtual bool isMatch(const QString& text) const
    {
        return false;
    }

signals:
    void signalResized();
    void signalInsertCodeSnippets(const QJsonDocument& doc);
    void signalShowCodeGUIEditor();

public slots:
    virtual void autoResizeEdit()
    {}

protected:
    void resizeEvent(QResizeEvent *event) override;

public:
    QCheckBox* check;
    InteractiveButtonBase* btn;
    static QColor triggerColor;

protected:
    CustomPaintWidget* _bgLabel;
    QVBoxLayout* vlayout;
    QHBoxLayout* hlayout;
    InteractiveButtonBase* guiBtn;

private:
    int _row;
    int _cardMargin = 9;
    bool _triggering = false;
    QTimer* _triggerTimer = nullptr;

};

#endif // LISTITEMINTERFACE_H
