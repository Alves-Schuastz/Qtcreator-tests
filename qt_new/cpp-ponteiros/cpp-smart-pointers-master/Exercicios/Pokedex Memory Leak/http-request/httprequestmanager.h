#ifndef HTTPREQUESTMANAGER_H
#define HTTPREQUESTMANAGER_H

#include "http-request_global.h"

#include <QObject>
#include <QDebug>
#include <QNetworkAccessManager>
#include <QNetworkReply>
#include <QNetworkRequest>
#include <QJsonDocument>
#include <QTimer>
#include <QNetworkDiskCache>

#include "response/httpstubresponse.h"

class HTTPREQUEST_EXPORT HttpRequestManager : public QObject {
public:

    template<class StubResponse>
    StubResponse* get( const QString& baseUrl, const QStringList& paths, const int timeout = 30000 ) const {
        return get<StubResponse>( toUrl( baseUrl, paths ), timeout );
    };

    template<class StubResponse>
    StubResponse* get( const QString& url, const int timeout = 30000 ) const {

        qInfo() << "HttpRequestManager::get server ...";

        QNetworkRequest request = QNetworkRequest( QUrl( url ) );
        request.setAttribute( QNetworkRequest::CacheLoadControlAttribute, QNetworkRequest::PreferCache );
        request.setSslConfiguration( QSslConfiguration::defaultConfiguration() );

        QNetworkAccessManager networkManager;

        QNetworkDiskCache diskCache;
        diskCache.setCacheDirectory( "cache/request" );
        networkManager.setCache( &diskCache );

        QNetworkReply* reply = networkManager.get( request );

        HttpStatusCodeEnum status;
        const QByteArray data = awaitSync( timeout, reply, status );

        return toResponse<StubResponse>( data, status );
    };

    static QString toQuerys( const QString& baseUrl, const QList<QString>& querys );

private:
    template<class StubResponse>
    StubResponse* toResponse( const QByteArray& data, const HttpStatusCodeEnum status ) const {

        StubResponse* response = new StubResponse();
        QJsonDocument document = QJsonDocument::fromJson( data );

        HttpStubResponse* httpStubResponse = static_cast<HttpStubResponse*>( response );

        httpStubResponse->fromJson( document );
        httpStubResponse->setStatus( status );

        return response;

    };

    QByteArray awaitSync( const int timeout, QNetworkReply* reply, HttpStatusCodeEnum& status ) const;

    QString toUrl( const QString& base, const QStringList& paths ) const;
};

#endif // HTTPREQUESTMANAGER_H
