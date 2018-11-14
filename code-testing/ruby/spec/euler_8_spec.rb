require_relative 'spec_helper'

RSpec.describe greatest_product(4, parse_info("./input/euler_8_input.txt")) do
  it "finds the greatest product" do
    expect(greatest_product(4, parse_info("./input/euler_8_input.txt"))).to equal(5832)
    expect(greatest_product(13, parse_info("./input/euler_8_input.txt"))).to equal(23514624000)
  end
end
