trains = []

File.readlines('./test.txt').each { |line| trains << line.split(',').each {|line| line.tr!("\n", '')  }}

print trains
