#ifndef TST_T_INTEGERS_H
#define TST_T_INTEGERS_H

#include "integers.h"
#include <QtTest>
#include "mainwindow.h"

class TestIntegers: public QObject
{
    Q_OBJECT

public:
    TestIntegers() = default;
    ~TestIntegers() = default;

private slots:
    void test_gcd_data();
    void test_gcd();

    void test_lcm_data();
    void test_lcm();

    void test_isPrime_data();
    void test_isPrime();

    void test_isArmstrong_data();
    void test_isArmstrong();

private:
    Integers A;
    Integers B;
};
class TestMainWindowUI : public QObject
{
    Q_OBJECT

public:
    TestMainWindowUI() = default;
    ~TestMainWindowUI() = default;

private slots:
    void initTestCase();    // Инициализация перед всеми тестами
    void cleanupTestCase(); // Очистка после всех тестов
    void init();            // Инициализация перед каждым тестом
    void cleanup();         // Очистка после каждого теста

    void testGCDCalculation();
    void testLCMCalculation();
    void testPrimeCheck();
    void testArmstrongCheck();

private:
    MainWindow* m_mainWindow;
};



#endif // TST_T_INTEGERS_H
