require_relative 'euler_1'

def test_euler(problem_set)
  problem_1 = Euler_1.new(problem_set)
  problem_1.divisible_by_3_or_5
  answer = problem_1.add_divisible_numbers
  puts "the sum of all the numbers divisble by 3 or 5 under 1000 is #{answer}"
end

test_euler(1000)
