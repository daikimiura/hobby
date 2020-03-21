require 'digest/md5'
md5_a1 = 'c627e19450db746b739f41b64097d449'
md5_a2 = Digest::MD5.hexdigest('GET:/~q9/flag.html')
nonce = 'hPLo+2GhBQA=ec7703ecd53c6531eafa1b2c0469b4be324288d2'
nc = '00000002'
cnonce = '08d03893e719d08a'
qop = 'auth'
res = Digest::MD5.hexdigest(md5_a1 + ':' + nonce + ':' + nc + ':' + cnonce + ':' + qop + ':' + md5_a2)
puts res