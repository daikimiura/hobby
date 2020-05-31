n = gets.to_i
a = gets.split.map(&:to_i)
ans =1 
flag = true
(1..n).each do |i|
    if a[i-1] == 0
        puts 0
        flag = false
        break
    end
end

if flag
(1..n).each do |i|
     ans *= a[i-1]
    if ans > 1000000000000000000
       puts -1
       flag = false
       break
    end
end
end

if flag
    puts ans
end

