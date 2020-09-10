#include "test_matrix.h"
#include "test_version.h"

int main(int argc, char* argv[])
{
    int status = 0;
    status |= QTest::qExec(new TestVersion(), argc, argv);
    status |= QTest::qExec(new TestMatrix(), argc, argv);
    return status;
}
