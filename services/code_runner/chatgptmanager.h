#ifndef CHATGPTMANAGER_H
#define CHATGPTMANAGER_H

#include <QObject>
#include "livedanmaku.h"
#include "chatgptutil.h"
#include "netinterface.h"
#include "liveservicebase.h"

#define GPT_TASK_RESPONSE_EVENT QString("GPT_RESPONSE")

class ChatGPTManager : public QObject
{
public:
    ChatGPTManager(QObject* parent = nullptr);

    void setLiveService(LiveServiceBase* service);

    void chat(UIDT uid, QString text, NetStringFunc func);

    void clear();

    void localNotify(const QString& text);

private:
    LiveServiceBase* liveService = nullptr;
    QMap<UIDT, QList<ChatBean>> usersChats;
};

#endif // CHATGPTMANAGER_H
