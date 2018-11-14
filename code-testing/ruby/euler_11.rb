#euler 11 - code by Nate Weeks to solve euler problem 11
#november 2018

def parse_info(filestring)
  #takes a file and parses a large string of integers into an array of integers
  integer_list = []
# parse the input into an array of individual integers
  File.readlines(filestring).each { |line| integer_list << line[0...-1].split(" ")}
  integer_list.each {|arr| arr.map! {|char| char.to_i}}
end

def greatest_product_right(integer_list)
  greatest_product = 0
  integer_list.each_with_index do |int, index|
    product = int
    3.times do
      index += 1
      if integer_list[index]
        product += product * integer_list[index]
      end
    end
    if product > greatest_product
      greatest_product = product
    end
  end
  return greatest_product
end

def greatest_product_four(integer_list)
  greatest_product = 0
  column = 0
  #code that checks 4 rows down at the same index
  integer_list.each do |row|
    row_product = greatest_product_right(row)
    if row_product > greatest_product
      greatest_product = row_product
    end
    row.each_with_index do |int, index|
      up_down_product = int
      diag_product = int
      3.times do
        column += 1
        if integer_list[column][index]
          up_down_product += up_down_product * integer_list[column][index]
        end
        if integer_list[column][index+1]
          diag_product += diag_product * integer_list[column][index+1]
        end
      end
      if up_down_product > greatest_product
        greatest_product = up_down_product
      end
      if diag_product > greatest_product
        greatest_product = diag_product
      end
    end
  end
  return greatest_product
end

  # code that checks 4 rows diagonal by adding 1 to the index and going down a row

integer_list = parse_info("./input/euler_11_text.txt")
print integer_list[0][2]
print greatest_product_four(integer_list)
