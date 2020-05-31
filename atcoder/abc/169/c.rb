n = gets.split
a = n.first.to_i
b = n.last.to_s.delete(".").to_i
puts (a*b).floor/100