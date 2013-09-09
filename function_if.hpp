#include <boost/function.hpp>

namespace boost
{
  template<typename F> 
  struct function_if
  {
    typedef typename boost::function<F>::result_type result_type;

    typedef boost::function<bool()> predicate_type;

    function_if(F f, predicate_type p)
      : m_f(f)
      , m_p(p)
    {
    }

    boost::function<F> m_f;
    predicate_type m_p;

    template <typename... Params>
    result_type operator()(Params&&... parameters)
    {
      return (m_p()) ? m_f(parameters...) : result_type();
    }
  };

  template<typename F> 
  struct function_if_ret
  {
    typedef typename boost::function<F>::result_type result_type;

    typedef boost::function<bool()> predicate_type;

    function_if_ret(F f, predicate_type p, result_type r = result_type())
      : m_f(f)
      , m_p(p)
      , m_r(r)
    {
    }

    boost::function<F> m_f;
    predicate_type m_p;
    result_type const m_r;

    template <typename... Params>
    result_type operator()(Params&&... parameters)
    {
      return (m_p()) ? m_f(parameters...) : m_r;
    }
  };

  template <typename F, typename P>
  function_if<F> make_function_if(F const& f, P const& p)
  {
    return function_if<F>(f, p);
  }

  template <typename F, typename P, typename R>
  function_if_ret<F> make_function_if_ret(F const& f, P const& p, R const& r)
  {
    return function_if_ret<F>(f, p, r);
  }
}
