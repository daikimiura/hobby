iseq = RubyVM::InstructionSequence.compile(<<SRC, "", "")
  puts "Hello world"
SRC

File.write(ARGV[0], iseq.to_binary)

