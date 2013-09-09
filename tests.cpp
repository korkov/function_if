#include <assert.h>
#include "function_if.hpp"

void set_ok(bool& ok) { ok = true; }
int ret_one() { return 1; }

bool ret_true() { return true; }
bool ret_false() { return false; }

void tests()
{
  using boost::function_if;
  using boost::make_function_if;
  using boost::function_if_ret;
  using boost::make_function_if_ret;

  bool ok = false;

  ok = false;
  function_if<void(bool&)>(set_ok, ret_true)(ok);
  assert(ok);

  ok = false;
  function_if<void(bool&)>(set_ok, ret_false)(ok);
  assert(!ok);

  assert(function_if<int()>(ret_one, ret_true)() == 1);
  assert(function_if<int()>(ret_one, ret_false)() == 0);

  assert(function_if_ret<int()>(ret_one, ret_false, 5)() == 5);


  ok = false;
  make_function_if(set_ok, ret_true)(ok);
  assert(ok);

  ok = false;
  make_function_if(set_ok, ret_false)(ok);
  assert(!ok);

  assert(make_function_if(ret_one, ret_true)() == 1);
  assert(make_function_if(ret_one, ret_false)() == 0);

  assert(make_function_if_ret(ret_one, ret_false, 5)() == 5);
}

int main()
{
  tests();
  return 0;
}
