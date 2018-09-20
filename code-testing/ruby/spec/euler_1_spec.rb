require 'spec_helper'

RSpec.describe Euler_1 do
  let(:example) {Euler_1.new(10)}

  describe ".new" do
    it "takes a number as an argument" do
      expect(example).to be_a(Euler_1)
    end
  end

  describe "#divisible_by_3_or_5" do
    it "finds all numbers in problem_set divisible by 3 or 5" do
      expect(example.divisible_by_3_or_5).to eq([3, 5, 6, 9])
    end
  end

  describe "#add_divisible_numbers" do
    it "adds all the numbers divisble by 3 and 5" do
      example.divisible_by_3_or_5
      expect(example.add_divisible_numbers).to eq(23)
    end
  end
end
