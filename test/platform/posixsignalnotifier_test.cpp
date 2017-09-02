#include <QObject>
#include <QProcess>
#include <QtTest/QtTest>

#include <signal.h>

// Check signal handling for them
static const int SIGNALS[] = {
    SIGHUP,
    SIGINT,
    SIGQUIT,
    SIGTERM,
};

static bool isCorrectlyHandled(int signum)
{
    QProcess p;
}

class TestPosixSignalNotifier : public QObject
{
    Q_OBJECT
private slots:
    void test()
    {
        for (int signum : SIGNALS) {
            QVERIFY(isCorrectlyHandled(signum));
        }
    }
};

QTEST_GUILESS_MAIN(TestPosixSignalNotifier)
#include "posixsignalnotifier_test.moc"
