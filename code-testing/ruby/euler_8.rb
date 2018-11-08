# euler 8 - code by Nate Weeks to solve euler problem 8
#November 2018

def parse_info
  #parses a large string of integers into an array of integers
  integer_list = []
# parse the input into an array of individual integers
  File.readlines("./input/euler_8_input.txt").each { |line| line[0...-1].split("").each {|char| integer_list << char.to_i}}
  return integer_list
end

def greatest_product(number, integer_list)
  # takes an array of integers and a number of consecutive integers and
  # outputs the greatest possible product of a number of consecutive integers
  i = 0                                 #outer loop index
  greatest_product = 0
  while i < integer_list.length - number do
    product = 1
    j = i                               #inner loop index
    number.times do
      product *= integer_list[j]
      j += 1
    end
    if product > greatest_product
      greatest_product = product
    end
    i += 1
  end
end

puts greatest_product(13, parse_info())
