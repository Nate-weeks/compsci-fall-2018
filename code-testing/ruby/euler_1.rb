class Euler_1
  attr_reader :problem_set, :divisble_numbers

  def initialize(array_size)
    @problem_set = (1..array_size - 1).to_a
  end

  def divisible_by_3_or_5
    @divisible_numbers = []
    @problem_set.each do |num|
      if num % 3 == 0 || num %5 == 0
        @divisible_numbers << num
      end
    end
    return @divisible_numbers
  end

  def add_divisible_numbers
    sum = 0
    @divisible_numbers.each do |num|
      sum += num
    end
    return sum
  end
end
