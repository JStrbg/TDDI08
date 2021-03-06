#include <iostream>
#include "tl.h"

using std::cout;
using std::endl;

tl::tl(sc_module_name name)
: sc_module(name)
{

  SC_METHOD(get_sensors);
  dont_initialize();
  sensitive  << inc_NS << inc_SN << inc_WE << inc_EW;

  SC_METHOD(traffic_logic);
  dont_initialize();

  SC_METHOD(print_lights);
  dont_initialize();
  //Trigga på sensorförändring: inc_EW inc_NS inc_SN inc_WE
  //kontrollera nuvarande status
  //justera lampor vartefter
  //skriv ut
}
void tl::get_sensors()
{
  inc[0] += inc_NS->read();
  inc[1] += inc_SN->read();
  inc[2] += inc_WE->read();
  inc[3] += inc_EW->read();

  traffic_logic();
}
void tl::traffic_logic()
{
  //NS || SN  om någon av dem inte redan är true samtidigt som WE || EW är true
  if ((inc[0] || inc[1]) && !((lights[0] || lights[1]) && (inc[2] || inc[3])))
  {
    lights[0] = inc[0];
    lights[1] = inc[1];
    lights[2] = false;
    lights[3] = false;
    if(inc[0])
      inc[0]--;
    if(inc[1])
      inc[1]--;
  }
  else if(inc[2] || inc[3]) //EW || WE
  {
    lights[0] = false;
    lights[1] = false;
    lights[2] = inc[2];
    lights[3] = inc[3];
    if(inc[2])
      inc[2]--;
    if(inc[3])
      inc[3]--;
  }
  else
  {
    lights[0] = false;
    lights[1] = false;
    lights[2] = false;
    lights[3] = false;
  }
  print_lights();
}
void tl::print_lights()
{
  cout << endl << sc_time_stamp();
  cout << endl << "NS : " << lights[0];
  cout << endl << "SN : " << lights[1];
  cout << endl << "WE : " << lights[2];
  cout << endl << "EW : " << lights[3] << endl;
}
