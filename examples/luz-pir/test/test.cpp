/** Generated by YAKINDU Statechart Tools code generator. */

#include <AUnit.h>
using namespace aunit;
#include "../arduino/arduino.cpp"
Arduino *arduino;

#include "../statechart/statechart.cpp"
Statechart *statechart = Statechart::get();

class StatechartTest : public TestOnce
{

protected:
  void setup() override
  {
    TestOnce::setup();
    arduino->setupArduino();
  }
  void teardown() override
  {
    delete statechart;
    TestOnce::teardown();
  }

public:
  void setupTeste()
  {
    TestRunner::setTimeout(30);
    TestRunner::exclude("*");
    // TestRunner::include("looping*");
    TestRunner::include("StatechartTest", "*");
  }

  void loopTeste()
  {
    // arduino->loopArduino(statechart);
    TestRunner::run();
  }
};

test(StatechartTest, testLuzInitOFF)
{

  arduino->loopArduino(statechart);
  statechart->enter();
  assertTrue(statechart->luz->isRaisedOFF());
}
test(StatechartTest, testSinalPIR_SinalLuz)
{

  statechart->enter();
  statechart->pir->raiseON();
  assertTrue(statechart->luz->isRaisedON());
  statechart->pir->raiseOFF();
  assertTrue(statechart->luz->isRaisedOFF());
}
// test(StatechartTest, test5Ativacoes)
// {

//   statechart->enter();

//   // sc_integer i = 0;
//   int i = 0;

//   statechart->pir()->raiseON();

//   i = i + 1;

//   while ((i) < (5))
//   {
//     i = i + 1;
//     statechart->pir()->raiseOFF();
//     statechart->pir()->raiseON();
//   }

//   statechart->pir()->raiseON();

//   assertTrue((statechart->getCount()) == (5));

//   // EXPECT_TRUE(statechart->isStateActive(Statechart::main_region_Estado5Ativacoes));

//   // statechart->pir()->raiseON();

//   // EXPECT_TRUE(statechart->isStateActive(Statechart::main_region__final_));
// }
