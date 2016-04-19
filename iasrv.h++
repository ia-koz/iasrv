#ifndef IASRV_H
#define IASRV_H

#include <QTcpServer>


class iasrv : public QTcpServer
{
		Q_OBJECT

	public:
		iasrv( QObject * parent = 0 );

	protected:
		void				incomingConnection( qintptr socketDescriptor ) override;
};

#endif // IASRV_H
