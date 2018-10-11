file='text.txt'
split_lines = []
File.readlines(file).each do |line|
  split_lines << line.split(" ")
end

hash = {}
split_lines.each do |line|
  if line.length == 3
    
