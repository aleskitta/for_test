#include "tst_t_integers.h"
#include "qtestcase.h"
#include <qlineedit.h>
#include <qpushbutton.h>
#include <qlabel.h>

// GCD test data
void TestIntegers::test_gcd_data() {
    QTest::addColumn<unsigned int>("a");
    QTest::addColumn<unsigned int>("b");
    QTest::addColumn<unsigned int>("expected");
    QTest::addColumn<bool>("useCompare"); // Флаг выбора макроса

    QTest::newRow("10 and 15") << 10u << 15u << 5u << true;
    QTest::newRow("21 and 7")  << 21u << 7u  << 7u << true;
    QTest::newRow("17 and 23") << 17u << 23u << 1u << false;
    QTest::newRow("0 and 5")   << 0u  << 5u  << 0u << false;
    QTest::newRow("48 and 18") << 48u << 18u << 6u << true;
}

void TestIntegers::test_gcd() {
    QFETCH(unsigned int, a);
    QFETCH(unsigned int, b);
    QFETCH(unsigned int, expected);
    QFETCH(bool, useCompare);

    Integers obj(a, b);
    if (useCompare) {
        QCOMPARE(obj.gcd(), expected);
    } else {
        QVERIFY(obj.gcd() == expected);
    }
}

// LCM test data
void TestIntegers::test_lcm_data() {
    QTest::addColumn<unsigned int>("a");
    QTest::addColumn<unsigned int>("b");
    QTest::addColumn<unsigned int>("expected");

    QTest::newRow("10 and 15") << 10u << 15u << 30u;
    QTest::newRow("7 and 3")   << 7u  << 3u  << 21u;
    QTest::newRow("0 and 5")   << 0u  << 5u  << 0u;
}

void TestIntegers::test_lcm() {
    QFETCH(unsigned int, a);
    QFETCH(unsigned int, b);
    QFETCH(unsigned int, expected);

    Integers obj(a, b);
    QCOMPARE(obj.lcm(), expected);
}

// Prime test data
void TestIntegers::test_isPrime_data() {
    QTest::addColumn<unsigned int>("number");
    QTest::addColumn<bool>("expected");

    QTest::newRow("17")  << 17u << true;
    QTest::newRow("2")   << 2u  << true;
    QTest::newRow("1")   << 1u  << false;
    QTest::newRow("0")   << 0u  << false;
    QTest::newRow("100") << 100u << false;
}

void TestIntegers::test_isPrime() {
    QFETCH(unsigned int, number);
    QFETCH(bool, expected);

    Integers obj;
    obj.setA(number);
    QCOMPARE(obj.isPrime(), expected);
}

// Armstrong test data
void TestIntegers::test_isArmstrong_data() {
    QTest::addColumn<unsigned int>("number");
    QTest::addColumn<bool>("expected");

    QTest::newRow("153")  << 153u  << true;
    QTest::newRow("370")  << 370u  << true;
    QTest::newRow("371")  << 371u  << true;
    QTest::newRow("100")  << 100u  << false;
    QTest::newRow("1634") << 1634u << true;
}

void TestIntegers::test_isArmstrong() {
    QFETCH(unsigned int, number);
    QFETCH(bool, expected);

    Integers obj;
    obj.setA(number);
    QCOMPARE(obj.isArmstrong(), expected);
}
void TestMainWindowUI::initTestCase()
{
    // Инициализация перед всеми тестами
}

void TestMainWindowUI::cleanupTestCase()
{
    // Очистка после всех тестов
}

void TestMainWindowUI::init()
{
    // Создаем главное окно перед каждым тестом
    m_mainWindow = new MainWindow();
    m_mainWindow->show();
    QVERIFY(QTest::qWaitForWindowActive(m_mainWindow));
}

void TestMainWindowUI::cleanup()
{
    // Удаляем главное окно после каждого теста
    delete m_mainWindow;
    m_mainWindow = nullptr;
}

void TestMainWindowUI::testGCDCalculation()
{
    // Находим элементы интерфейса
    QLineEdit* aInput = m_mainWindow->findChild<QLineEdit*>("aInput");
    QLineEdit* bInput = m_mainWindow->findChild<QLineEdit*>("bInput");
    QPushButton* gcdButton = m_mainWindow->findChild<QPushButton*>("gcdButton");
    QLineEdit* resultOutput = m_mainWindow->findChild<QLineEdit*>("resultOutput");

    QVERIFY(aInput != nullptr);
    QVERIFY(bInput != nullptr);
    QVERIFY(gcdButton != nullptr);
    QVERIFY(resultOutput != nullptr);

    // Вводим значения
    aInput->setText("10");
    bInput->setText("15");

    // Нажимаем кнопку GCD
    QTest::mouseClick(gcdButton, Qt::LeftButton);

    // Проверяем результат
    QCOMPARE(resultOutput->text(), "5");
}

void TestMainWindowUI::testLCMCalculation()
{
    QLineEdit* aInput = m_mainWindow->findChild<QLineEdit*>("aInput");
    QLineEdit* bInput = m_mainWindow->findChild<QLineEdit*>("bInput");
    QPushButton* lcmButton = m_mainWindow->findChild<QPushButton*>("lcmButton");
    QLineEdit* resultOutput = m_mainWindow->findChild<QLineEdit*>("resultOutput");

    QVERIFY(aInput && bInput && lcmButton && resultOutput);

    aInput->setText("10");
    bInput->setText("15");
    QTest::mouseClick(lcmButton, Qt::LeftButton);
    QCOMPARE(resultOutput->text(), "30");
}

void TestMainWindowUI::testPrimeCheck()
{
    QLineEdit* numberInput = m_mainWindow->findChild<QLineEdit*>("numberInput");
    QPushButton* primeButton = m_mainWindow->findChild<QPushButton*>("primeButton");
    QLabel* answerOutput = m_mainWindow->findChild<QLabel*>("answerOutput");

    QVERIFY(numberInput && primeButton && answerOutput);

    // Тест простого числа
    numberInput->setText("17");
    QTest::mouseClick(primeButton, Qt::LeftButton);
    QCOMPARE(answerOutput->text(), "Yes");

    // Тест не простого числа
    numberInput->setText("100");
    QTest::mouseClick(primeButton, Qt::LeftButton);
    QCOMPARE(answerOutput->text(), "No");
}

void TestMainWindowUI::testArmstrongCheck()
{
    QLineEdit* numberInput = m_mainWindow->findChild<QLineEdit*>("numberInput");
    QPushButton* armstrongButton = m_mainWindow->findChild<QPushButton*>("armstrongButton");
    QLabel* answerOutput = m_mainWindow->findChild<QLabel*>("answerOutput");

    QVERIFY(numberInput && armstrongButton && answerOutput);

    // Тест числа Армстронга
    numberInput->setText("153");
    QTest::mouseClick(armstrongButton, Qt::LeftButton);
    QCOMPARE(answerOutput->text(), "Yes");

    // Тест не числа Армстронга
    numberInput->setText("100");
    QTest::mouseClick(armstrongButton, Qt::LeftButton);
    QCOMPARE(answerOutput->text(), "No");
}

//QTEST_APPLESS_MAIN(TestIntegers)
int main(int argc, char *argv[])
{
    int status = 0;

    // Запуск тестов для Integers
    TestIntegers testIntegers;
    status |= QTest::qExec(&testIntegers, argc, argv);

    // Запуск UI-тестов
    TestMainWindowUI testUI;
    status |= QTest::qExec(&testUI, argc, argv);

    return status;
}
