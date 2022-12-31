#ifndef DATA_MEMORY_HPP_
#define DATA_MEMORY_HPP_

#include "cpu.hpp"

template<class T>
struct cpu::data_memory
{
   static constexpr auto ADDRESS_WIDTH = 2000;

   std::array<T, ADDRESS_WIDTH> data{};

   data_memory(void)
   {
      this->reset();
      return;
   }

   void reset(void)
   {
      for (auto& i : this->data)
      {
         i = 0x00;
      }
      return;
   }

   int write(const std::uint16_t address, const T& new_element)
   {
      if (address < ADDRESS_WIDTH)
      {
         data[address] = new_element;
         return 0;
      }
      else
      {
         return 1;
      }
   }

   T read(const std::uint16_t address) const
   {
      if (address < ADDRESS_WIDTH)
      {
         return data[address];
      }
      else
      {
         return static_cast<T>(0);
      }
   }
};

#endif /* DATA_MEMORY_HPP_ */