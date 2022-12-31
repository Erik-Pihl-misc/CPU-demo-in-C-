#ifndef STACK_HPP_
#define STACK_HPP_

#include "cpu.hpp"

template<class T>
struct cpu::stack
{
   static constexpr auto ADDRESS_WIDTH = 256;
   std::array<T, ADDRESS_WIDTH> data{};
   std::uint8_t sp = ADDRESS_WIDTH - 1;
   bool stack_empty = true;

   void reset(void)
   {
      for (auto& i : data)
      {
         i = 0x00;
      }

      sp = ADDRESS_WIDTH - 1;
      stack_empty = true;
      return;
   }

   stack(void)
   {
      this->reset();
      return;
   }

   int push(const T& new_element)
   {
      if (stack_empty)
      {
         data[sp] = new_element;
         stack_empty = false;
         return 0;
      }
      else
      {
         if (sp > 0)
         {
            data[--sp] = new_element;
            return 0;
         }
         else
         {
            return 1;
         }
      }
   }

   int pop(T& retrieved_value)
   {
      if (stack_empty) return 1;
      retrieved_value = data[sp];

      if (sp < ADDRESS_WIDTH - 1)
      {
         sp++;
      }
      else
      {
         stack_empty = true;
      }
      return 0;
   }

   T first_element(void) const
   {
      return data[ADDRESS_WIDTH - 1];
   }

   T last_element(void) const
   {
      return data[sp];
   }

   auto num_elements(void) const
   {
      return ADDRESS_WIDTH - 1 - sp;
   }
};

#endif /* STACK_HPP_ */