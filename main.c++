#include <QCoreApplication>
#include <QCommandLineParser>
#include <QDebug>
#include <QtNetwork>

#include "iasrv.h++"


int main( int argc, char * argv[] )
{
	QCoreApplication a( argc, argv );
	QCoreApplication::setApplicationName( "iasrv" );
	QCoreApplication::setApplicationVersion( "1.0" );

	QCommandLineParser clParser;

	QCommandLineOption hostOption( QStringList() << "h" << "host",
								   QCoreApplication::translate( "main", "IP address or hostname." ),
								   QCoreApplication::translate( "main", "IP" ) );
	clParser.addOption( hostOption );

	QCommandLineOption portOption( QStringList() << "p" << "port",
								   QCoreApplication::translate( "main", "Port number." ),
								   QCoreApplication::translate( "main", "Port" ) );
	clParser.addOption( portOption );

	clParser.process( a );
	QString host = clParser.value( hostOption );
	QString port = clParser.value( portOption );

	qDebug() << host;
	qDebug() << port;

	QHostAddress hostAddress;
	hostAddress.setAddress( host );

	iasrv server;
	if ( !server.listen( hostAddress , port.toUInt() ) )
	{
		qDebug() << "Unable to start the server: " << server.errorString() << ".";
	}

	qDebug() << "The server is running on\nIP: " << server.serverAddress().toString() << "\nPort: " << server.serverPort() << "\n\n" <<
			 "Run the Client now.";

	return a.exec();
}
