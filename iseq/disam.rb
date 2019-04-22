iseq = RubyVM::InstructionSequence.compile(<<SRC, "","")
  def hello
    puts "Hello world"
  end
  hello
SRC

puts iseq.disasm

