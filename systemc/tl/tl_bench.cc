#include <systemc.h>
#include "tl.h"
#include "input_gen.h"

int sc_main(int argc, char **argv)
{
  // The command-line arguments are as follows:
  // 1. the simulation time (in seconds),
  // 2. the file with input data.
  assert(argc == 3);

  sc_time sim_time(atof(argv[1]), SC_SEC);
  char *infile = argv[2];

  sc_buffer<bool> inc_NS_sig;
  sc_buffer<bool> inc_SN_sig;
  sc_buffer<bool> inc_WE_sig;
  sc_buffer<bool> inc_EW_sig;

  tl trafficlight("tl");
  Generator gen("Generator", infile);

  trafficlight(inc_NS_sig,inc_SN_sig,inc_WE_sig,inc_EW_sig);
  gen(inc_NS_sig,inc_SN_sig,inc_WE_sig,inc_EW_sig);

  sc_start(sim_time);
  return 0;
}
