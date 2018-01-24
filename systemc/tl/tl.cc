#include "tl.h"

tl::tl(sc_module_name name)
: sc_module(name)
{
  SC_METHOD(get_sensor);
  SC_METHOD(check_others);
  SC_METHOD(print_light);
  //ta in sensor
  //kolla om ledigt
  //skriv ut lampa eller vänta
}
void tl::get_sensor()
{
  bool sensorValue = //sensor -> read();
}
void tl::check_others()
{
  bool good2Go = //controlInput -> read();
}
void tl::print_light
{
  bool light; //true grön, false röd
  cout << grön / röd
}
