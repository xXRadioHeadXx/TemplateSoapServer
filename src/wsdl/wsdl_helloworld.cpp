// This file is generated by KDAB's kdwsdl2cpp from helloworld.wsdl.
// All changes you do to this file will be lost.
/*
    You may use and relicense this generated file without restriction.
*/

#include "wsdl_helloworld.h"

#include <QtCore/QString>
#include <KDSoapClient/KDSoapMessage.h>
#include <KDSoapClient/KDSoapValue.h>
#include <KDSoapClient/KDSoapPendingCallWatcher.h>
#include <KDSoapClient/KDSoapNamespaceManager.h>

SayHelloJob::SayHelloJob( Hello_Service* service, QObject* _parent )
    : KDSoapJob(_parent), mService(service), mMsg(), mResultReply()
{
}

void SayHelloJob::setMsg( const QString& arg0 )
{
    mMsg = arg0;
}

QString SayHelloJob::msg() const
{
    return mMsg;
}

void SayHelloJob::doStart()
{
    const QString action = QString::fromLatin1("sayHello");
    KDSoapMessage message;
    message.setUse(KDSoapMessage::EncodedUse);
    message.setNamespaceUri(QString::fromLatin1("urn:examples:helloservice"));
    KDSoapValue _valueMsg = KDSoapValue(QString::fromLatin1("msg"), QVariant::fromValue(mMsg), KDSoapNamespaceManager::xmlSchema2001(), QString::fromLatin1("string"));
    _valueMsg.setNamespaceUri(QString::fromLatin1(""));
    message = _valueMsg;
    KDSoapPendingCall pendingCall = mService->clientInterface()->asyncCall(QLatin1String("sayHello"), message, action, requestHeaders());
    KDSoapPendingCallWatcher *watcher = new KDSoapPendingCallWatcher(pendingCall, this);
    QObject::connect(watcher, &KDSoapPendingCallWatcher::finished,
                     this, &SayHelloJob::slotFinished);
}

QString SayHelloJob::reply() const
{
    return mResultReply;
}

void SayHelloJob::slotFinished( KDSoapPendingCallWatcher* watcher )
{
    watcher->deleteLater();
    KDSoapMessage _reply = watcher->returnMessage();
    if (!_reply.isFault()) {
        mResultReply = _reply.value().value<QString>();
    }
    emitFinished(_reply, watcher->returnHeaders());
}


void Hello_ServiceServerBase::sayHelloResponse( const KDSoapDelayedResponseHandle& responseHandle, const QString& ret )
{
    KDSoapMessage _response;
    KDSoapValue _valueReply = KDSoapValue(QString::fromLatin1("reply"), QVariant::fromValue(ret), KDSoapNamespaceManager::xmlSchema2001(), QString::fromLatin1("string"));
    _valueReply.setNamespaceUri(QString::fromLatin1(""));
    _response = _valueReply;
    sendDelayedResponse(responseHandle, _response);
}

void Hello_ServiceServerBase::processRequest( const KDSoapMessage &_request, KDSoapMessage &_response, const QByteArray& _soapAction )
{
    setResponseNamespace(QLatin1String("http://www.ecerami.com/wsdl/HelloService.wsdl"));
    const QByteArray method = _request.name().toLatin1();
    if (method == "sayHello" || _soapAction == "sayHello") {
        QString msg;
        msg = _request.value().value<QString>();
        QString ret = sayHello(msg);
        if (!hasFault()) {
            KDSoapValue _valueReply = KDSoapValue(QString::fromLatin1("reply"), QVariant::fromValue(ret), KDSoapNamespaceManager::xmlSchema2001(), QString::fromLatin1("string"));
            _valueReply.setNamespaceUri(QString::fromLatin1(""));
            _response = _valueReply;
        }
        return;
    }
    KDSoapServerObjectInterface::processRequest(_request, _response, _soapAction);
}


class Hello_Service::PrivateDPtr
{
public:
    PrivateDPtr();

public:
    KDSoapClientInterface *m_clientInterface;
    KDSoapMessage m_lastReply;
    QString m_endPoint;
};

Hello_Service::PrivateDPtr::PrivateDPtr()
    : m_clientInterface(nullptr)
{
}


Hello_Service::Hello_Service( QObject* _parent )
    : QObject(_parent), d_ptr(new PrivateDPtr)
{
}

Hello_Service::~Hello_Service()
{
    delete d_ptr->m_clientInterface;

    delete d_ptr;
    d_ptr = nullptr;
}

void Hello_Service::ignoreSslErrors()
{
    clientInterface()->ignoreSslErrors();
}

void Hello_Service::setEndPoint( const QString& endPoint )
{
    d_ptr->m_endPoint = endPoint;
    if (d_ptr->m_clientInterface)
        d_ptr->m_clientInterface->setEndPoint( endPoint );
}

QString Hello_Service::endPoint() const
{
    return d_ptr->m_endPoint;
}

void Hello_Service::setSoapVersion( KDSoapClientInterface::SoapVersion soapVersion )
{
    clientInterface()->setSoapVersion(soapVersion);
}

KDSoapClientInterface::SoapVersion Hello_Service::soapVersion() const
{
    return clientInterface()->soapVersion();
}

int Hello_Service::lastErrorCode() const
{
    if (d_ptr->m_lastReply.isFault())
        return d_ptr->m_lastReply.childValues().child(QLatin1String("faultcode")).value().toInt();
    return 0;
}

QString Hello_Service::lastFaultCode() const
{
    if (d_ptr->m_lastReply.isFault())
        return d_ptr->m_lastReply.childValues().child(QLatin1String("faultcode")).value().toString();
    return QString();
}

QString Hello_Service::lastError() const
{
    if (d_ptr->m_lastReply.isFault())
        return d_ptr->m_lastReply.faultAsString();
    return QString();
}

const KDSoapClientInterface *Hello_Service::clientInterface() const
{
    if (!d_ptr->m_clientInterface) {
        const QString endPoint = !d_ptr->m_endPoint.isEmpty() ? d_ptr->m_endPoint : QString::fromLatin1("http://localhost:8081/hello");
        const QString messageNamespace = QString::fromLatin1("http://www.ecerami.com/wsdl/HelloService.wsdl");
        d_ptr->m_clientInterface = new KDSoapClientInterface(endPoint, messageNamespace);
        d_ptr->m_clientInterface->setStyle( KDSoapClientInterface::DocumentStyle );
        d_ptr->m_clientInterface->setSoapVersion( KDSoapClientInterface::SOAP1_1 );
    }
    return d_ptr->m_clientInterface;
}

KDSoapClientInterface *Hello_Service::clientInterface()
{
    return const_cast<KDSoapClientInterface*>( const_cast< const Hello_Service*>( this )->clientInterface() );
}

QString Hello_Service::sayHello( const QString& msg )
{
    const QString action = QString::fromLatin1("sayHello");
    KDSoapMessage message;
    message.setUse(KDSoapMessage::EncodedUse);
    message.setNamespaceUri(QString::fromLatin1("urn:examples:helloservice"));
    KDSoapValue _valueMsg = KDSoapValue(QString::fromLatin1("msg"), QVariant::fromValue(msg), KDSoapNamespaceManager::xmlSchema2001(), QString::fromLatin1("string"));
    _valueMsg.setNamespaceUri(QString::fromLatin1(""));
    message = _valueMsg;
    d_ptr->m_lastReply = clientInterface()->call(QLatin1String("sayHello"), message, action);
    if (d_ptr->m_lastReply.isFault())
        return QString();
    QString ret;
    ret = d_ptr->m_lastReply.value().value<QString>();
    return ret;
}

void Hello_Service::asyncSayHello( const QString& msg )
{
    const QString action = QString::fromLatin1("sayHello");
    KDSoapMessage message;
    message.setUse(KDSoapMessage::EncodedUse);
    message.setNamespaceUri(QString::fromLatin1("urn:examples:helloservice"));
    KDSoapValue _valueMsg = KDSoapValue(QString::fromLatin1("msg"), QVariant::fromValue(msg), KDSoapNamespaceManager::xmlSchema2001(), QString::fromLatin1("string"));
    _valueMsg.setNamespaceUri(QString::fromLatin1(""));
    message = _valueMsg;
    KDSoapPendingCall pendingCall = clientInterface()->asyncCall(QLatin1String("sayHello"), message, action);
    KDSoapPendingCallWatcher *watcher = new KDSoapPendingCallWatcher(pendingCall, this);
    QObject::connect(watcher, &KDSoapPendingCallWatcher::finished,
                     this, &Hello_Service::_kd_slotSayHelloFinished);
}

void Hello_Service::_kd_slotSayHelloFinished( KDSoapPendingCallWatcher* watcher )
{
    const KDSoapMessage reply = watcher->returnMessage();
    if (reply.isFault()) {
        Q_EMIT sayHelloError(reply);
        Q_EMIT soapError(QLatin1String("sayHello"), reply);
    } else {
        QString ret;
        ret = reply.value().value<QString>();
        Q_EMIT sayHelloDone( ret );
    }
    watcher->deleteLater();
}


