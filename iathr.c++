#include "iathr.h++"
#include <QDataStream>
#include <QTextCodec>


iathr::iathr( qintptr		socketDescriptor,
			  QObject 	*	parent )
	: QThread( parent ),
	  tcpSocket( 0 ),
	  socketDescriptor( socketDescriptor )
{
}

void iathr::run()
{
	tcpSocket = new QTcpSocket();
	if ( !tcpSocket->setSocketDescriptor( socketDescriptor ) )
	{
		emit error( tcpSocket->error() );
		return;
	}

	connect( tcpSocket, SIGNAL( readyRead() ), this, SLOT( readyRead() ), Qt::DirectConnection );
	connect( tcpSocket, SIGNAL( disconnected() ), this, SLOT( disconnected() ) );

	exec();
}

void iathr::readyRead()
{
	QByteArray data = tcpSocket->readAll();
	qDebug() << data;

	// TODO: Здесь будет алгоритм деления числа на простые множители.

	QByteArray block;
	QDataStream out( &block, QIODevice::WriteOnly );
	out << "Test text from server.";

	tcpSocket->write( block );

	// Закроем соединение, дабы клиентский поток не висел просто так.
	tcpSocket->disconnectFromHost();
	tcpSocket->waitForDisconnected();
}

void iathr::disconnected()
{
	qDebug() << socketDescriptor << " Disconnected.\n";

	tcpSocket->deleteLater();
	exit( 0 );
}
