# numbers = [11, 12, 13, 14, 15, 16, 17, 18, 19, 20]
#
# i = 2520
# answer = false
# while answer == false
#   numbers.each do |number|
#     if i % number == 0
#       answer = true
#     else answer = false
#       break
#     end
#   end
#   if answer == true
#     break
#   else
#   i += 2
#
#   end
# end
#
# puts i

# A ruby program by Nate Weeks to solves Euler problem 5
#  Smallest Multiple for 1-20 october 2018
class Euler_5
  def initialize()
    @factors = [11, 12, 13, 14, 15, 16, 17, 18, 19, 20]
  end

# method to check a given number for factors without remainders
  def check_factors(number)
    answer = false
    @factors.each do |factor|
      if number % factor == 0
        answer = true
      else answer = false
        break
      end
    end
    return answer
  end

# loop through each number starting at 2520 to check for factoring without remainders
  def find_smallest_number
    number = 2520                       #2520 because that was the given example for 1-10
    while number
      answer = check_factors(number)
      if answer == true
        break
      end
      number += 20               # += 20 for least steps divisible by 20
    end
    return number
  end
end

# test code
# euler_5 = Euler_5.new
# puts euler_5.find_smallest_number
