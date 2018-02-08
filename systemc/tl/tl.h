#ifndef TL_H
#define TL_H
#include <systemc.h>

SC_MODULE(tl)
{
  //boolkanaler för detektion av inkommande bilar
  sc_in<bool> inc_NS;
  sc_in<bool> inc_SN;
  sc_in<bool> inc_WE;
  sc_in<bool> inc_EW;

  //boolkanaler för ljus (används ej atm)
  sc_out<bool> tl_NS;
  sc_out<bool> tl_SN;
  sc_out<bool> tl_WE;
  sc_out<bool> tl_EW;

  //internt
  bool tl[4] = {false,false,false,false};
  int inc[4] = {0,0,0,0};

  SC_HAS_PROCESS(tl);
  tl(sc_module_name name);

  void get_sensors();
  void print_lights();
  void traffic_logic();
}

#endif //TL_H
