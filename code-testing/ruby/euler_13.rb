# a program by Nate Weeks to solve Euler 13 - product of 50 digit nums
#November 2018

def parse_info(filestring)
  #takes a file and parses a large string of integers into an array of integers
  integer_list = []
# parse the input into an array of individual integers
  File.readlines(filestring).each { |line| integer_list << line[0...-1].to_i}

  return integer_list
end


def calculate_total(array)
  sum = 0
  array.each { |number| sum += number }
  return sum
end

print calculate_total(parse_info("./input/euler_13_input.txt"))
