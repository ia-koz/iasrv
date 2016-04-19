#include "iasrv.h++"
#include "iathr.h++"


iasrv::iasrv( QObject * parent )
	: QTcpServer( parent )
{
}

void iasrv::incomingConnection( qintptr socketDescriptor )
{
	qDebug() << "New connection...";
	iathr * thread = new iathr( socketDescriptor, this );
	connect( thread, SIGNAL( finished() ), thread, SLOT( deleteLater() ) );
	thread->start();
}
