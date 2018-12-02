#euler 11 - code by Nate Weeks to solve euler problem 11
#november 2018
require 'pry'
class Euler_11
  attr_accessor :integer_list
  def initialize(filestring)
    #takes a file and parses a large string of integers into an array of integers
    @integer_list = []
  # parse the input into an array of individual integers
    File.readlines(filestring).each { |line| @integer_list << line[0...-1].split(" ")}
    @integer_list.each {|arr| arr.map! {|char| char.to_i}}
  end

  def grid_search
    grid = @integer_list
    width = grid[0].length
    height = grid.length
    largest_product = 0
    row_offset = [0, 1, 1, 1]
    column_offset = [1, 0, 1, -1]

    grid.each_with_index do |row, row_index|
      row.each_index do |column_index|
        r = row_index
        c = column_index
        for i in 0..3
          result = 1
          4.times do
            if r < width && c < height
              result = result * grid[r][c]
            end
            r = r + row_offset[i]
            c = c + column_offset[i]
          end
          if result > largest_product
            largest_product = result
          end
        end
      end
    end
    return largest_product
  end
end

integer_list = Euler_11.new("./input/euler_11_text.txt")
print integer_list.grid_search

# """
#  grid_search.py
# """
#
# grid = [ [1, 2, 3, 4, 5, 6],
#          [1, 2, 3, 4, 5, 6],
#          [1, 2, 3, 4, 5, 6],
#          [1, 2, 3, 4, 5, 6],
#          [1, 2, 3, 4, 5, 6],
#          [1, 2, 3, 4, 5, 6] ]
#
# width = len(grid[0])
# height = len(grid)
# big_result = 0
#
# for row in range(width):
#     for col in range(height):
#         # (row, col) is starting point
#         # loop over   >>   V    .     .
#         #                  V     .   .
#         for (row_offset, col_offset) in
#             ((0,1), (1,0), (1,1), (1,-1)):
#                  result = 1
#                  r = row
#                  c = col
#                  for which in range(4):
#
#                      try:
#                          result = result * grid[r][c]
#                      except:
#                          result = 0
#                      r = r + row_offset
#                      c = c + col_offset
#                  if result > big_result:
#                     big_result = result


# def greatest_product_right(integer_list)
#   greatest_product = 0
#   integer_list.each_with_index do |int, index|
#     product = int
#     3.times do
#       index += 1
#       if integer_list[index]
#         product += product * integer_list[index]
#       end
#     end
#     if product > greatest_product
#       greatest_product = product
#     end
#   end
#   return greatest_product
# end
#
# def greatest_product_four(integer_list)
#   greatest_product = 0
#   column = 0
#   #code that checks 4 rows down at the same index
#   integer_list.each do |row|
#     row_product = greatest_product_right(row)
#     if row_product > greatest_product
#       greatest_product = row_product
#     end
#     row.each_with_index do |int, index|
#       col = column
#       up_down_product = int
#       diag_product = int
#       3.times do
#         col += 1
#         if integer_list[col][index]
#           up_down_product += up_down_product * integer_list[col][index]
#         end
#         if integer_list[col][index+1]
#           diag_product += diag_product * integer_list[col][index+1]
#         end
#       end
#       if up_down_product > greatest_product
#         greatest_product = up_down_product
#       end
#       if diag_product > greatest_product
#         greatest_product = diag_product
#       end
#     end
#     column += 1
#   end
#   return greatest_product
# end

  # code that checks 4 rows diagonal by adding 1 to the index and going down a row
