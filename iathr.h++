#ifndef IATHR_H
#define IATHR_H

#include <QThread>
#include <QTcpSocket>


class iathr : public QThread
{
		Q_OBJECT

	public:
		iathr( qintptr		socketDescriptor,
			   QObject *	parent );

		void					run() override;

	signals:
		void					error( QTcpSocket::SocketError socketError );

	public slots:
		void					readyRead();
		void					disconnected();

	private:
		QTcpSocket *			tcpSocket;
		qintptr					socketDescriptor;
};

#endif // IATHR_H
