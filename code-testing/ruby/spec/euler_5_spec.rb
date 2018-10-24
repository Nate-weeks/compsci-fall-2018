require_relative 'spec_helper'

RSpec.describe Euler_5 do
  let(:example) {Euler_5.new}

  describe ".new" do
    it "intializes a new object" do
      expect(example).to be_a(Euler_5)
    end
  end

  describe "#check_factors" do
    it "checks if number is a factor of every number in array" do
      expect(example.check_factors(1000)).to equal(false)
    end
  end

  describe "#find_smallest_number" do
    it "finds the smallest number that is a factor of factors" do
      expect(example.find_smallest_number).to be_a(Integer)
      expect(example.find_smallest_number).to_not be_a(String)
    end
  end
end
