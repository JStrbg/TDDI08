#include "input_gen.h"
#include <cassert>

Generator::Generator(sc_module_name name, char *datafile)
  : sc_module(name)
{
  assert(datafile != 0);       // An input file should be given.

  in = new ifstream(datafile); // Open the input file.
  assert(*in);                 // Check that everything is OK.

  SC_THREAD(generate_thread);

  inc_NS.initialize(0);
  inc_SN.initialize(0);
  inc_WE.initialize(0);
  inc_EW.initialize(0);
}

Generator::~Generator()
{
  delete in;
}

void Generator::generate_thread()
{
  bool inc[4];
  for (;;) {
    wait(1, SC_SEC);     // Generate new inputs every second.
    for(int i = 0; i < 4; i++)
    {
      *in >> inc[i]; // Read from the input file.
    }
    inc_NS->write(inc[0]);
    inc_SN->write(inc[1]);
    inc_WE->write(inc[2]);
    inc_EW->write(inc[3]);
  }
}
