class Rectangle
    def initialize(length, width)
    @length = length
    @width = width
  end

  def length
      @length
  end

  def width
      @width
  end
end

my_rectangle = Rectangle.new(5,6)

print my_rectangle.length
