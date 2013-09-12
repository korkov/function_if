function_if
===========

boost::function extension

The function_if is executed if the condition is satisfied.
##Examples
Suppose we have the following functions:
```c++
int ret_one() { return 1; }
bool ret_true() { return true; }
bool ret_false() { return false; }
void hello() { std::cout << "hello" << std::endl; }
```
##function_if
This code will print 'hello'
```c++
boost::function_if<void()> f(hello, ret_true);
f();
```
This will do nothing
```c++
boost::function_if<void()> f(hello, ret_false);
f();
```
##function_if_ret
This code will assign value '1' to the variable
```c++
boost::function_if_ret<int()> f(ret_one, ret_true, 5);
int a = f();
```
This will assign default value '5' to the variable
```c++
boost::function_if_ret<int()> f(ret_one, ret_false, 5);
int a = f();
```
##make_function_if, make_function_if_ret
You can use make_* helpers
```c++
boost::make_function_if(hello, ret_true)();
```
