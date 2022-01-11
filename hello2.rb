require "narray"

science = NArray.to_na( [65,80,67,35,58,60,72,75,68,92,36,50,25,85,46,42,78,62,84,70] )
english = NArray.to_na( [44,87,100,63,52,60,58,73,55,86,29,56,89,23,65,84,64,27,86,84] )

p science.mean
p science.stddev
p science.sum
p english.mean
p english.stddev
p english.sum

p "sci"
for i in 0..19
  p (science[i]-62.5)/18.4*10+50
end

p "eng"
for i in 0..19
  p (english[i]-64.25)/22.1*10+50
end

p science.sort
p english.sort
